#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("hello world");
    __asm__("int $0x03"); // ��������˵������жϣ�����֮�����У����Trace/breakpoint trap (core dumped)
    printf("hello world");
    return 0;
}
