#include <stdio.h>
#include <string.h>

// 返回字符串的长度，函数不许使用多余的临时变量。
int len(const char *str) {
    if(str == NULL || *str == '\0') { // 一定要判断str是否为NULL，否则，如果为NULL，*str会Segmentation fault (core dumped)
        return 0;
    }
    return (1 + len(str+1));
}

int main()
{
    // char c = 'a';
    // char str[] = "nian";

    int ll;
    const char *str = "nian";
    ll = len(str);
    printf("[%s] len:[%d]\n", str, ll);

    const char *yi = "y";
    ll = len(yi);
    printf("[%s] len:[%d]\n", yi, ll);

    const char *ba = NULL;
    ll = len(ba);
    printf("[%s] len:[%d]\n", ba, ll);

    return 0;
}
