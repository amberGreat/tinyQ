#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <aio.h>
#include <pthread.h>

#define BUF_SIZE 1024


void aio_completion_handler(sigval_t sigval);

void setup_io(int fd, aiocb& my_aiocb)
{
	//��ʼ��AIO����
	bzero( (char *)&my_aiocb, sizeof(struct aiocb) );
	my_aiocb.aio_fildes = fd;
	my_aiocb.aio_buf = malloc(BUF_SIZE+1);
	my_aiocb.aio_nbytes = BUF_SIZE;
	my_aiocb.aio_offset = 0;
	
	//�����̻߳ص�����
	my_aiocb.aio_sigevent.sigev_notify = SIGEV_THREAD;
	my_aiocb.aio_sigevent.sigev_notify_function = aio_completion_handler;
	my_aiocb.aio_sigevent.sigev_notify_attributes = NULL;
	my_aiocb.aio_sigevent.sigev_value.sival_ptr = &my_aiocb;
}

//�ص�����
void aio_completion_handler(sigval_t sigval)
{
	struct aiocb *req;
	int ret;
	
	req = (struct aiocb *)sigval.sival_ptr;
	
	if (aio_error(req) == 0) 
	{
		if((ret = aio_return(req)) > 0)
		{
			printf("Thread id %u recv:%s\n", (unsigned int)pthread_self(), (char*)req->aio_buf);
		}
	}

	char* buf = (char*)req->aio_buf;
	
	if(send(req->aio_fildes, buf, strlen(buf), 0) == -1)
	{
		perror("send");
		return;
	}

	close(req->aio_fildes);

	return;
}

int main()
{
	int sockfd;
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
	
	//�ȴ�����
	while(1) 
	{
		int new_fd;
  		struct aiocb my_aiocb;
		sin_size = sizeof(struct sockaddr_in);
		
		//��������
		if((new_fd = accept(sockfd, (struct sockaddr *)&cliaddr, (socklen_t*)&sin_size))==-1)
		{
			perror("accept");
			return -1;
		}

		printf("Thread id %u accept connect, fd: %d\n", (unsigned int)pthread_self(), new_fd);
		
		setup_io(new_fd, my_aiocb);
		aio_read(&my_aiocb);
	}
	close(sockfd);
}
