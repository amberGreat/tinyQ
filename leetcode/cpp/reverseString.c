#include <stdio.h>

/********************************************************
 * Write a function that takes a string as input and returns the string reversed.
 *
 * Example:
 * Given s = "hello", return "olleh".
 *******************************************************/

// 11:33, 11:41д��
char* reverseString(char* s) {
    if (s == NULL ) return NULL;

    int len = strlen(s);
    int middle = len / 2;
    char tmp;
    int i;
    for (i=0; i<middle; ++i) {
        tmp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = tmp;
    }
    return s;
}

// �����C++�ⷨ,��2�����ʹ��������м���
// class Solution {
// public:
//     string reverseString(string s) {
//         int i = 0, j = s.size() - 1;
//         while(i < j){
//             swap(s[i++], s[j--]);
//         }
//         return s;
//     }
// };

int main(int argc, char* argv[]) {
    // char input[] = "hello";
    char input[] = "";
    printf("%s\n", input);
    char *output = reverseString(input);
    printf("%s\n", output);
}
