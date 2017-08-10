#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

/*************************************************************
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good
 *  question to ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
*************************************************************/

/*
// 思路一样，就是实现更简洁
bool isPalindrome(char* s) {
    int len = strlen(s);
    if(!len) return true;
    char *p1 = s, *p2 = s + len - 1;
    while(p1 < p2){
        if(!isalnum(*p1)){p1++;continue;}
        if(!isalnum(*p2)){p2--;continue;}
        if(tolower(*p1++) != tolower(*p2--)) return false;
    }
    return true;
}
*/

bool isPalindrome(char* s) {

    if (s == NULL) return false;
    int len = strlen(s);
    if (len == 0 || len == 1) return true;

    char c1, c2;
    char *head = s, *tail = s + len -1;
    int step = len - -1;
    while (step >0) {
        if (!isalnum(*head)) {
            head += 1;
            step -= 1;
            continue;
        }
        if (!isalnum(*tail)) {
            tail -= 1;
            step -= 1;
            continue;
        }
        c1 = *head;
        c2 = *tail;

        if (isupper(c1)) {
            c1 = tolower(c1);
        }
        if (isupper(c2)) {
            c2 = tolower(c2);
        }

        if (c1 != c2) {
            return false;
        }
        if (tail - head > 2) {
            head += 1;
            tail -= 1;
            step -= 2;
        } else {
            break;
        }
    }

    return true;
}

int main(int argc, char* argv[]) {

    char input[50];
    strcpy(input, "abc d");
    printf("%s: %d\n", input, isPalindrome(input));

    strcpy(input, "abccba");
    printf("%s: %d\n", input, isPalindrome(input));

    strcpy(input, "ab ,$ccb a");
    printf("%s: %d\n", input, isPalindrome(input));

    strcpy(input, ")abccba  ");
    printf("%s: %d\n", input, isPalindrome(input));

    strcpy(input, "");
    printf("%s: %d\n", input, isPalindrome(input));
}
