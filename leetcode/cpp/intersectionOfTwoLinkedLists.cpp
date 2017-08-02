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
 * A:          a1 → a2
 *                     → c1 → c2 → c3
 * B:     b1 → b2 → b3
 *
 * begin to intersect at node c1.
 *
 * Notes:
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.

 **********************************************************************************/


// start from 16:51, 17:06看hints
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 如果需要判断headA == headB，需实现operator==操作符
//     ListNode headA = ListNode(5);
//     ListNode headB = ListNode(5);

// 相交，那么，一定有一个ListNode他们的地址开始相等。
class Solution {
public:
    // 思路一：根据一条链表遍历，里面再遍历一次。但，这样时间就是O(n**2)，需求是O(1)
    // 思路二：看了左耳朵耗子的解法，一开始，先把长度不同的链表长度对齐。17:49开始, 18:00完成。有思路之后，写出代码，使用了，11分钟。
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int lenA = getLength(headA);
        int lenB = getLength(headB);

        if (lenA <= 0 || lenB <=0) {
            return NULL;
        }

        // 由于指针也是值传递，只要不改变指针指向的内容，就不会改变原先参数的结构
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

// leetcode提示的做法
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
