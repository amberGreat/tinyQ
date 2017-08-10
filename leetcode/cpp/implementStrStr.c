#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**************************************************
 * Implement strStr().
 *
 * Returns the index of the first occurrence of needle in haystack,
 * or -1 if needle is not part of haystack.
 **************************************************/

int strStr(char* haystack, char* needle) {

    if (haystack == NULL || needle == NULL) return -1;

    int hayLen = strlen(haystack);
    int neeLen = strlen(needle);

    // ±ß½çÌõ¼þ
    int i = 0, rst;

    for (; i+neeLen <= hayLen; ++i) {
        rst = strncmp(haystack+i, needle, neeLen);
        if (rst == 0) return i;
    }

    return -1;
}

// implement of cpp
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int m = haystack.length(), n = needle.length();
//         if (!n) return 0;
//         for (int i = 0; i < m - n + 1; i++) {
//             int j = 0;
//             for (; j < n; j++)
//                 if (haystack[i + j] != needle[j])
//                     break;
//             if (j == n) return i;
//         }
//         return -1;
//     }
// };

int main(int argc, char* argv[]) {

    char haystack[50];
    char needle[50];

    strcpy(haystack, "abc");
    strcpy(needle, "bc");
    printf("[%s],[%s]: %d\n", haystack, needle, strStr(haystack, needle));

    strcpy(haystack, "abc");
    strcpy(needle, "a");
    printf("[%s],[%s]: %d\n", haystack, needle, strStr(haystack, needle));

    strcpy(haystack, "");
    strcpy(needle, "");
    printf("[%s],[%s]: %d\n", haystack, needle, strStr(haystack, needle));
}
