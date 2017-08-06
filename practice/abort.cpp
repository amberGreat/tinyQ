//示例一
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa (int signo)
{
    printf ("捕捉到了信号%d\n", signo);
}
int main (void)
{
    signal (SIGABRT, fa);
    printf ("1111111111111\n");
    abort ();
    printf ("2222222222222\n");
    return 0;
}
// 输出结果：
// 1111111111111
// 捕捉到了信号6
// 已放弃 (核心已转储)

