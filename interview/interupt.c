#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("hello world");
    __asm__("int $0x03"); // 文章里面说会产生中断，试验之后，运行，输出Trace/breakpoint trap (core dumped)
    printf("hello world");
    return 0;
}
