//ʾ��һ
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa (int signo)
{
    printf ("��׽�����ź�%d\n", signo);
}
int main (void)
{
    signal (SIGABRT, fa);
    printf ("1111111111111\n");
    abort ();
    printf ("2222222222222\n");
    return 0;
}
// ��������
// 1111111111111
// ��׽�����ź�6
// �ѷ��� (������ת��)

