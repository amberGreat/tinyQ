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

        // �Ȱѳ����д�������ٿ��Ǳ߽硣һ��Ԫ�أ�2��Ԫ�أ�����Ϊ�棬����Ϊż
        while (walk->next != NULL) { // �Ƿ����tmp���ж�����
            if (evenHead == NULL) {
                evenHead = walk->next;
            }

            evenTmp = walk->next;
            walk->next = walk->next->next; // ����2��next�������һ��next�Ѿ�ΪNULL,������segment fault

            if (walk->next == NULL) {
                evenTmp->next = NULL;
            } else {
                walk = walk->next; // һ��ʼ������һ����walk������ǰ�ߣ��Ҳ��ܸ�walk��ֵNULL������ѭ����walk->next��segment fault
                evenTmp->next = walk->next;
            }
        }

        walk->next = evenHead;
        return head;
    }
};

// 10:12, 1041д�꣬�������˰��Сʱ,�������ȷ��
int main(int argc, char* argv[]) {

    // g++ -I./include -o a.out  oddEvenLinkedList.cpp include/list_node.cpp -g
    // createLink ���ǲ�delete�����ԣ���ʵ���main���ڴ�й¶
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
