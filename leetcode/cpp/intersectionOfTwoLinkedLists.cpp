#include <iostream>
#include <cstdlib>
using namespace std;

// TODO separate header file to create linked list
/**********************************************************************************
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 *
 * program to find the node at which the intersection of two singly linked lists begins.
 * For example, the following two linked lists:
 *
 * A:          a1 �� a2
 *                     �� c1 �� c2 �� c3
 * B:     b1 �� b2 �� b3
 *
 * begin to intersect at node c1.
 *
 * Notes:
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.

 **********************************************************************************/


// start from 16:51, 17:06��hints
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// �����Ҫ�ж�headA == headB����ʵ��operator==������
//     ListNode headA = ListNode(5);
//     ListNode headB = ListNode(5);

// �ཻ����ô��һ����һ��ListNode���ǵĵ�ַ��ʼ��ȡ�
class Solution {
public:
    // ˼·һ������һ����������������ٱ���һ�Ρ���������ʱ�����O(n**2)��������O(1)
    // ˼·���������������ӵĽⷨ��һ��ʼ���Ȱѳ��Ȳ�ͬ�������ȶ��롣17:49��ʼ, 18:00��ɡ���˼·֮��д�����룬ʹ���ˣ�11���ӡ�
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int lenA = getLength(headA);
        int lenB = getLength(headB);

        if (lenA <= 0 || lenB <=0) {
            return NULL;
        }

        // ����ָ��Ҳ��ֵ���ݣ�ֻҪ���ı�ָ��ָ������ݣ��Ͳ���ı�ԭ�Ȳ����Ľṹ
        ListNode *a = headA;
        ListNode *b = headB;

        int i;
        if (lenA < lenB) {
            for (i=0; i < abs(lenB - lenA); ++i) {
                b = b->next;
            }
        } else {
            for (i=0; i < abs(lenA - lenB); ++i) {
                a = a->next;
            }
        }

        while (a != b) {
            a = a->next;
            b = b->next;
        }

        return a;
    }

private:
    int getLength(ListNode *head) {
        int len = 0;
        while (head != NULL) {
            head = head->next;
            ++len;
        }
        return len;
    }
};

// leetcode��ʾ������
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode * a = headA;
//         ListNode * b = headB;
//         int count = 0;
//
//         if(a == NULL || b == NULL)
//             return NULL;
//
//         while (a != b)
//         {
//             a = a->next;
//             b = b->next;
//             if (a == NULL)
//             {
//                 a = headB;
//                 count ++;
//             }
//             if (b == NULL)
//                 b = headA;
//             if (count == 2)
//                 return NULL;
//         }
//         return a;
//     }
// };

int main(int argc, char* argv[]) {
    ListNode *headA = new ListNode(5);
    ListNode *headB = new ListNode(5);

}
