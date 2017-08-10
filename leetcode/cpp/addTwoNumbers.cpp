#include <iostream>
#include <cmath>
#include "list_node.h"

using std::cout;
using std::endl;

/*******************************************************************
 * https://leetcode.com/problems/add-two-numbers/description/
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single
 *  digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
*******************************************************************/


// һ��ʼҲ�뵽һλһλ�ӣ�����˼ά���裬��ϲ��ֱ�Ӱ�������������ȡ�ࡣ�������
// 10:53��ʼ��˼·�� 11:05����ͨ����Accepted
// ����ⲻ�ѣ�������Ŀ��˼����������testcase�ı߽������Ƚ϶࣬Ҳ�����͵������
class Solution {
public:
    // ѭ���У��������˸����ж�����е�ֵ
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL || l2 == NULL) return NULL;

        int sumDigit = 0;
        int carry = 0;

        ListNode *prev = NULL;
        ListNode *head= NULL;
        ListNode *tail = NULL;
        while (l1 !=NULL || l2!=NULL) {
            sumDigit = carry;
            if (l1 != NULL) {
                sumDigit += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sumDigit += l2->val;
                l2 = l2->next;
            }

            carry = sumDigit / 10;
            sumDigit = sumDigit % 10;

            tail = new ListNode(sumDigit);
            if (prev == NULL) {
                head = tail;
            } else {
                prev->next = tail;
            }
            prev = tail;
        }

        if (carry >0) {
            tail = new ListNode(carry);
            prev->next = tail;
        }

        if (head == NULL) head = new ListNode(0);

        return head;
    }
};


// class Solution {
// public:
//     // ѭ���У��������˸����ж�����е�ֵ
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         if (l1 == NULL || l2 == NULL) return NULL;
//         // һ��ʼ��int�����������long֮��Ҳ��һ�����������
//         long int sum = 0;
//         int sumDigit = 0;
//         int idx = 0;
// 
//         while (l1 !=NULL || l2!=NULL) {
//             sumDigit = 0;
//             if (l1 != NULL) {
//                 sumDigit += l1->val;
//                 l1 = l1->next;
// 
//             }
//             if (l2 != NULL) {
//                 sumDigit += l2->val;
//                 l2 = l2->next;
//             }
// 
//             sum += sumDigit * pow(10, idx);
//             idx +=1;
//         }
// 
//         int digit = 0;
//         ListNode *prev = NULL;
//         ListNode *head= NULL;
//         ListNode *tail = NULL;
//         while (sum > 0) {
//             digit = sum % 10;
//             sum = sum / 10;
// 
//             tail = new ListNode(digit);
// 
//             if (prev == NULL) {
//                 head = tail;
//             } else {
//                 prev->next = tail;
//             }
//             prev = tail;
//         }
//         if (head == NULL) head = new ListNode(0);
// 
//         return head;
//     }
// };



// ��˼��13min, 10:56��д, 11:13��ʼdebug: ������Ŀ
int main(int argc, char* argv[]) {

    Solution *solu = new Solution();
    // case 1
    // expected: 7 -> 0 -> 8
    // int arr1[] = {2,4,3};
    // int arr2[] = {5,6,4};
    // ListNode *head1 = createLink(arr1, 3);
    // ListNode *head2 = createLink(arr2, 3);

    // case 2
    // Expected:
    // [0,0,0,0,0,0,0,0,0,0,1]
    // int arr1[] = {9};
    // int arr2[] = {1,9,9,9,9,9,9,9,9,9};
    // ListNode *head1 = createLink(arr1, 1);
    // ListNode *head2 = createLink(arr2, 10);

    // case 3
    // expected: 0
    // int arr1[] = {0};
    // int arr2[] = {0};

    // case 4
    // expected: 0 -> 1
    int arr1[] = {5};
    int arr2[] = {5};
    ListNode *head1 = createLink(arr1, 1);
    ListNode *head2 = createLink(arr2, 1);

    echoList(head1);
    echoList(head2);
    ListNode *rst = solu->addTwoNumbers(head1, head2);
    echoList(rst);

    // Input:
    // [5]
    // [5]
    // Output:
    // [1,0]
    // Expected:
    // [0,1]

    // int rst = 10^2; // 1010
    // cout << rst << endl; // ���8
    // cout << pow(10, 2) << endl; // ���8

}
