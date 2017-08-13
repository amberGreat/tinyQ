#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/epoll.h>

#define MAXEVENT 1024

int create_server_socket(int& sockfd)
{
	struct sockaddr_in addr;
	
	//创建socket
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("createSocket");
		return -1;
	}
	
	//初始化socket结构
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(7092);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	//绑定套接口
	if(bind(sockfd,(struct sockaddr *)&addr,sizeof(struct sockaddr))==-1)
	{
		perror("bind");
		return -1;
	}
	
	//创建监听套接口
	if(listen(sockfd,10)==-1)
	{
		perror("listen");
		return -1;
	}
	
	return 0;	
}

int set_socket_non_blocking(int fd)
{
	int flags, s;
	
	flags = fcntl (fd, F_GETFL, 0);
	if (flags == -1)
	{
		perror ("fcntl F_GETFL failed");
		return -1;
	}
	
	flags |= O_NONBLOCK;
	s = fcntl (fd, F_SETFL, flags);
	if (s == -1)
	{
		perror ("fcntl F_SETFL failed");
		return -1;
	}
	
	return 0;
}

int main()
{
	int sockfd, efd;
	struct epoll_event event;
	struct epoll_event *events;	
	int s;
	
	if(create_server_socket(sockfd) != 0)
	{
		perror("create server sock failed\n");
		return 1;
	}
	set_socket_non_blocking(sockfd);
	
	printf("server is running!\n");

	//创建一个epoll的句柄
	//int epoll_create(int size)  
	//Since Linux 2.6.8, the size argument is unused. (The kernel dynamically sizes the required data structures without needing this initial hint.)
	efd = epoll_create(MAXEVENT);
	if (efd == -1)
	{
		perror ("epoll_create");
		abort ();
	}

	//注册新事件到epoll efd
	event.data.fd = sockfd;
	event.events = EPOLLIN | EPOLLET;
	s = epoll_ctl(efd, EPOLL_CTL_ADD, sockfd, &event);
	if (s == -1)
	{
		perror ("epoll_ctl EPOLL_CTL_ADD failed");
		abort ();
	}
	
	events = (epoll_event*)calloc(MAXEVENT, sizeof(event));
	
	while (1)
    {
		int n, i;
		n = epoll_wait(efd, events, MAXEVENT, -1);
		for (i = 0; i < n; i++)
    	{
    		//fd error
      		if ((events[i].events & EPOLLERR) ||
              	(events[i].events & EPOLLHUP) ||
              (!(events[i].events & EPOLLIN)))
        	{
				perror("epoll error\n");
				close (events[i].data.fd);
				continue;
			}
			//新连接
      		else if (sockfd == events[i].data.fd)
       		{
				while (1)
				{
					struct sockaddr in_addr;
					socklen_t in_len;
					int infd;
					char hbuf[NI_MAXHOST], sbuf[NI_MAXSERV];
					
					//接受连接
					in_len = sizeof(in_addr);
					infd = accept(sockfd, &in_addr, &in_len);
					if (infd == -1)
					{
						if ((errno == EAGAIN) ||
						  (errno == EWOULDBLOCK))
						{
							//已接受所有连接
					      	break;
					    }
						else
						{
							perror ("accept");
							break;
						}
					}
					
					s = getnameinfo (&in_addr, in_len,
					               hbuf, sizeof hbuf,
					               sbuf, sizeof sbuf,
					               NI_NUMERICHOST | NI_NUMERICSERV);
					if (s == 0)
					{
					  printf("Accepted connection on descriptor %d "
					         "(host=%s, port=%s)\n", infd, hbuf, sbuf);
					}
					
					/* 设置新接受的socket连接无阻塞*/
					s = set_socket_non_blocking (infd);
					if (s == -1)
					{
					return 1;
					}
					
					//注册新事件到epoll
					event.data.fd = infd;
					event.events = EPOLLIN | EPOLLET;
					s = epoll_ctl(efd, EPOLL_CTL_ADD, infd, &event);
					if (s == -1)
					{
					  perror ("epoll_ctl");
					  return 1;
					}
				}
				continue;
            }
            //数据可读
          	else
            {
              int done = 0;
              while (1)
              {
                  ssize_t count;
                  char buf[512];
                  count = read(events[i].data.fd, buf, sizeof(buf));
                  if(count == -1)
                  {
                      //数据读完
                      if (errno != EAGAIN)
                      {
                          perror ("read");
                          done = 1;
                      }
                      break;
                  }
                  else if(count == 0)
                  {
                      /* End of file. The remote has closed the
                         connection. */
                      done = 1;
                      break;
                   }

                  printf("recv: %s\n", buf);
                }

              if (done)
              {
                  printf ("Closed connection on descriptor %d\n", events[i].data.fd);
                  close (events[i].data.fd);
              }
            }
        }
    }

  free (events);
  close(sockfd);
  return 0;
}
