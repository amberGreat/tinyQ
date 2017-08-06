#include <iostream>
#include "list_node.h"

using std::cout;
using std::endl;

/************************************************************
 * Write a function to delete a node (except the tail) in a singly linked list,
 * given only access to that node.
 *
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node
 * with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
 ************************************************************/

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *nNode = node->next;
        *node = *nNode;
    }

    // all these 2 work
    // void deleteNode(ListNode* node) {
    //     *node = *node->next;
    // }
    // void deleteNode(ListNode* node) {
    //     node->val = node->next->val;
    //     node->next = node->next->next;
    // }
};

// 10:41, 10:48写完
int main(int argc, char* argv[]) {

    // g++ -I./include -o a.out  oddEvenLinkedList.cpp include/list_node.cpp -g
    // createLink 总是不delete，所以，其实这个main会内存泄露
    Solution *solu = new Solution();

    cout << "bbegin:" << endl;
    ListNode *head = createLink(5);
    // ListNode *toDelete = head->next;
    ListNode *toDelete = head;
    echoList(head);
    solu->deleteNode(toDelete);
    echoList(head);

    // cout << "---------------------------------" << endl;
    // head = createLink(4);
    // echoList(head);
    // head = solu->oddEvenList(head);
    // echoList(head);
}
