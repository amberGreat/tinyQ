#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int sockfd, new_fd;
	int sin_size;
	struct sockaddr_in addr, cliaddr;
	
	//����socket
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("createSocket");
		return -1;
	}
	
	//��ʼ��socket�ṹ
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(7092);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	//���׽ӿ�
	if(bind(sockfd,(struct sockaddr *)&addr,sizeof(struct sockaddr))==-1)
	{
		perror("bind");
		return -1;
	}
	
	//���������׽ӿ�
	if(listen(sockfd,10)==-1)
	{
		perror("listen");
		return -1;
	}
	
	
	printf("server is running!\n");
	
	char buff[1024];
	//�ȴ�����
	while(1) 
	{
		sin_size = sizeof(struct sockaddr_in);
		
		//��������
		if((new_fd = accept(sockfd, (struct sockaddr *)&cliaddr, (socklen_t*)&sin_size))==-1)
		{
			perror("accept");
			return -1;
		}
			
		//����һ���ӽ�������ɺͿͻ��˵ĻỰ�������̼�������
		if(!fork())
		{
			//����new_fd����������
			int flags;
			if((flags=fcntl(new_fd, F_GETFL, 0))<0)  
            {
            	perror("fcntl F_GETFL");  
            }
    	    flags |= O_NONBLOCK;  
      		if(fcntl(new_fd, F_SETFL,flags)<0)  
            {
            	perror("fcntl F_SETFL");  
			}
			
			//��ȡ�ͻ��˷�������Ϣ
			memset(buff,0,sizeof(buff));
			while(1)
			{
				if((recv(new_fd,buff,sizeof(buff),0)) < 0)
				{
					if(errno==EWOULDBLOCK)
					{
						perror("recv error, wait....");
						sleep(1);
						continue;
					}
				}
				else
				{
					printf("buff=%s\n",buff);
				}	
				break;
			}

			//��������
			while(1)
			{
				if(send(new_fd,buff,strlen(buff),0) < 0)
				{
					if(errno==EWOULDBLOCK)
					{
						perror("send error, wait....");
						sleep(1);
						continue;
					}
				}
				else
				{
					printf("buff=%s\n",buff);
				}	
				break;
			}
	
			close(new_fd);
			return 0;
		}
		//�����̹ر�new_fd
		close(new_fd);
	}
	close(sockfd);
}
