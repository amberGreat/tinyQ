#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int data_processed = 0;
    int filedes[2];
    const char data[] = "Hello pipe!";
    char buffer[BUFSIZ + 1];
    pid_t pid;
    //��ջ�����
    memset(buffer, '\0', sizeof(buffer));

    if(pipe(filedes) == 0)
    {
        //�����ܵ��ɹ�
        //ͨ������fork�����ӽ���
        pid = fork();
        if(pid == -1)
        {
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
        }
        if(pid == 0)
        {
            //�ӽ�����
            //��ȡ����
            data_processed = read(filedes[0], buffer, BUFSIZ);
            printf("Read %d bytes: %s\n", data_processed, buffer);
            exit(EXIT_SUCCESS);
        }
        else
        {
            //��������
            //д����
            data_processed = write(filedes[1], data, strlen(data));
            printf("Wrote %d bytes: %s\n", data_processed, data);
            //����2�룬��Ҫ��Ϊ�˵��ӽ����Ƚ�����������Ҳֻ�Ǵ���Ϊ������ÿ�����
            //��������ʵû�б�Ҫ�ȵ��ӽ��̽���
            sleep(2);
            exit(EXIT_SUCCESS);
        }
    }
    exit(EXIT_FAILURE);
}
