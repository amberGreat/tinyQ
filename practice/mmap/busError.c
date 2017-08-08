#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    int fd,i;
    int pagesize,offset;
    char *p_map;
    struct stat sb;

    /* 取得page size */
    pagesize = sysconf(_SC_PAGESIZE);
    printf("pagesize is %d\n",pagesize); // 输出值为4096，即4K

    /* 打开文件 */
    fd = open(argv[1], O_RDWR, 00777);
    fstat(fd, &sb);
    printf("file size is %zd\n", (size_t)sb.st_size);

    offset = 0;
    p_map = (char *)mmap(NULL, pagesize * 2, PROT_READ|PROT_WRITE,
            MAP_SHARED, fd, offset);
    close(fd);

    // p_map[sb.st_size] = '9';  /* 导致总线错误 */
    // p_map[pagesize] = '9';    /* 导致段错误 */

    // 以上两句的解释不是很正确，打开了一个文件file size = 40,
    // 则分配的mmap容量为1 * pagesize > 40;所以，超出pagesize的内存，同时还属于进程地址，会报Busy。
    p_map[sb.st_size] = '9';  /* 这个在pagesize范围内，不报错*/
    p_map[pagesize] = '9';    /* 导致总线错误 */

    munmap(p_map, pagesize * 2);

    return 0;
}
