#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

// 这里声明，定义在cpp。编译记得带list_node.cpp
// g++ -I./include -o a.out  oddEvenLinkedList.cpp include/list_node.cpp -g
// -I./include => 是为了#include "list_node.h"能找到头文件

struct ListNode; // 这句有没有都OK
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct ListNode* echoVal(struct ListNode* head);
void echoList(struct ListNode* head);
struct ListNode* createLink(int *arrInt, int len);
struct ListNode* createLink(int len);

#endif
