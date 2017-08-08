#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 100

// ͨ������ӳ��ʵ�ָ��ӽ���ͨ��
int main(int argc, char** argv)
{
    char    *p_map;

    /* ����ӳ��,����һ���ڴ湩���ӽ���ͨ�� */
    p_map = (char *)mmap(NULL, BUF_SIZE, PROT_READ | PROT_WRITE,
            MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    if(fork() == 0) {
        sleep(1);
        printf("child got a message: %s\n", p_map);
        sprintf(p_map, "%s", "hi, dad, this is son");
        munmap(p_map, BUF_SIZE); //ʵ���ϣ�������ֹʱ�����Զ����ӳ�䡣
        printf("child exit\n");
        exit(0);
    }

    sprintf(p_map, "%s", "hi, this is father");
    sleep(2);
    printf("parent got a message: %s\n", p_map);

    // �����"child exit"���ⲿ���Լ�������
    sleep(2);
    sprintf(p_map, "%s", "in fater");
    printf("parent got a message: %s\n", p_map);
    sleep(1);
    sprintf(p_map, "%s", "bye");
    printf("parent got a message: %s\n", p_map);

    return 0;
}
