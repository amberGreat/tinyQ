#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


/*
搜索Evernote的『多线程与volatile变量』有解释。
『GCC编译器常识、以及静态库、动态库』

这是一个关于多线程，每个线程有独立的寄存器，全局变量更新后，寄存器没更新，不一致。
使用volatile， 如volatile int size = 10; 
当多线程访问这个变量时，它会直接从size对应的地址访问，而不会从线程对应的寄存器访问，
这样就不会出现前面说到的同一变量的值在多个线程之间不一致的情况。

$ gcc volatile.c  -pthread
$ gcc volatile.c -lpthread
2中编译都OK，但貌似是有区别.

In general, libraries should follow sources and objects on command line, and -lpthread is not an "option", it's a library specification.
所以，以下编译不能通过：
X gcc -lpthread -o a.out volatile.c X
以下可以：
gcc -pthread volatile.c

*/


/* volatile变量控制线程的运行与结束 */
// static int do_run_thread = 1; // 试了一下把volatile去掉，貌似也可以结束
static volatile int do_run_thread = 1;
static pthread_t thread_tid;

static void *work_thread(void *arg)
{
    while (do_run_thread) {
        printf("thread is running...\n");
        sleep(1);
    }
    printf("stop thread done!\n");
}

static void start_thread()
{
    printf("start thread...\n");
    pthread_create(&thread_tid, NULL, work_thread, NULL);
}

static void stop_thread()
{
    printf("stop thread...\n");
    do_run_thread = 0;
    pthread_join(thread_tid, NULL); /* 等待线程结束 */
}

int main()
{
    start_thread();
    sleep(5);
    stop_thread();

    return 0;
}
