#include <iostream>
#include <cstring>
using namespace std;

// 十六进制怎么表示负数呢？
int parseFromHex(char *hexInt) {

    if (hexInt == NULL) {
        return 0;
    }

    int len = strlen(hexInt);
    if (len < 3 ||
            (strncmp(hexInt, "0x", 2) != 0 && strncmp(hexInt, "0X", 2) != 0)) {
        return 0;
    }

    int idx = 2;
    int rst = 0;
    char ch;
    char upperCh;

    while (idx < len) {
        ch = *(hexInt + idx);
        upperCh = toupper(ch);

        if (ch <= '9' && ch >= '0') {
            rst = rst * 16 + (ch - '0');

        } else if (upperCh <= 'F' && upperCh >= 'A') {
            rst = rst * 16 + (upperCh - 'A') + 10;
        } else {
            return rst;
        }
        ++idx;
    }

    return rst;
}

int main() {

    int decInt;

    char hexInt[32] = "0x5ab";
    decInt = parseFromHex(hexInt);
    cout << hexInt << " : " << decInt << endl;

    strcpy(hexInt, "0xf");
    decInt = parseFromHex(hexInt);
    cout << hexInt << " : " << decInt << endl;

    strcpy(hexInt, "0x");
    decInt = parseFromHex(hexInt);
    cout << hexInt << " : " << decInt << endl;

    strcpy(hexInt, "cx");
    decInt = parseFromHex(hexInt);
    cout << hexInt << " : " << decInt << endl;

    strcpy(hexInt, "0x2d$2");
    decInt = parseFromHex(hexInt);
    cout << hexInt << " : " << decInt << endl;
}
