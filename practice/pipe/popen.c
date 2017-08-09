#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *read_fp = NULL;
    FILE *write_fp = NULL;
    char buffer[BUFSIZ + 1];
    int chars_read = 0;

    //��ʼ��������
    memset(buffer, '\0', sizeof(buffer));
    //��ls��grep����
    read_fp = popen("ls -l", "r");
    write_fp = popen("grep rwxrwxr-x", "w");
    //�������̶��򿪳ɹ�
    if(read_fp && write_fp)
    {
        //��ȡһ�����ݿ�
        chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
        while(chars_read > 0)
        {
            buffer[chars_read] = '\0';
            //������д��grep����
            fwrite(buffer, sizeof(char), chars_read, write_fp);
            //�������ݿɶ���ѭ����ȡ���ݣ�ֱ��������������
            chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
        }
        //�ر��ļ���
        pclose(read_fp);
        pclose(write_fp);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}
