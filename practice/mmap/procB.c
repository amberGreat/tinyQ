#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>

#define BUF_SIZE 100

// ʹ�ù���ӳ��ʵ����������֮���ͨ��
int main(int argc, char **argv)
{
    int fd, nread, i;
    struct stat sb;
    char *mapped, buf[BUF_SIZE];

    for (i = 0; i < BUF_SIZE; i++) {
        buf[i] = '#';
    }

    /* ���ļ� */
    if ((fd = open(argv[1], O_RDWR)) < 0) {
        perror("open");
    }

    /* ��ȡ�ļ������� */
    if ((fstat(fd, &sb)) == -1) {
        perror("fstat");
    }

    /* ˽���ļ�ӳ�佫�޷��޸��ļ� */
    if ((mapped = (char *)mmap(NULL, sb.st_size, PROT_READ |
                    PROT_WRITE, MAP_SHARED, fd, 0)) == (void *)-1) { // mapped[20] = '9'����һ�����̿����仯���ļ��ı䡣
                    // PROT_WRITE, MAP_PRIVATE, fd, 0)) == (void *)-1) {
                    // ���ΪMAP_PRIVATE������mapped[20] = '9'ʱ������copy-on-write���ƣ����⿪����һ���ڴ档�޸ĵ�ֵ����һ�����̲��ῴ�����ļ�Ҳ����ı䡣
        perror("mmap");
    }

    /* ӳ�����, �ر��ļ�Ҳ���Բ����ڴ� */
    close(fd);

    /* �޸�һ���ַ� */
    mapped[20] = '9';

    return 0;
}
