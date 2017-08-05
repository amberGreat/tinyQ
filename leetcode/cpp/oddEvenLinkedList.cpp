#include <iostream>
#include "list_node.h"

using std::cout;
using std::endl;

/***********************************************************************
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * Given a singly linked list, group all odd nodes together followed by the even nodes.
 * Please note here we are talking about the node number and not the value in the nodes.
 *
 * You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
 *
 * Example:
 * Given 1->2->3->4->5->NULL,
 * return 1->3->5->2->4->NULL.
 *
 * Note:
 * The relative order inside both the even and odd groups should remain as it was in the input.
 * The first node is considered odd, the second node even and so on ...
***********************************************************************/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode *walk = head;
        ListNode *evenHead = NULL;
        ListNode *evenTmp = NULL;

        // 先把常规的写出来，再考虑边界。一个元素，2个元素，长度为奇，长度为偶
        while (walk->next != NULL) { // 是否加上tmp的判断条件
            if (evenHead == NULL) {
                evenHead = walk->next;
            }

            evenTmp = walk->next;
            walk->next = walk->next->next; // 连续2个next，如果第一个next已经为NULL,后续会segment fault

            if (walk->next == NULL) {
                evenTmp->next = NULL;
            } else {
                walk = walk->next; // 一开始忘了这一步，walk忘了向前走；且不能给walk赋值NULL，否则循环后walk->next会segment fault
                evenTmp->next = walk->next;
            }
        }

        walk->next = evenHead;
        return head;
    }
};

// 10:12, 1041写完，还是用了半个小时,结果不正确。
int main(int argc, char* argv[]) {

    // g++ -I./include -o a.out  oddEvenLinkedList.cpp include/list_node.cpp -g
    // createLink 总是不delete，所以，其实这个main会内存泄露
    Solution *solu = new Solution();

    cout << "begin run:" << endl;
    ListNode *head = createLink(5);
    echoList(head);
    head = solu->oddEvenList(head);
    echoList(head);

    cout << "---------------------------------" << endl;
    head = createLink(4);
    echoList(head);
    head = solu->oddEvenList(head);
    echoList(head);

    cout << "---------------------------------" << endl;
    head = createLink(1);
    echoList(head);
    head = solu->oddEvenList(head);
    echoList(head);

}
