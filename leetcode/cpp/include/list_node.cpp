#include <iostream> // 忘了这句，‘cout’ was not declared in this scope
#include "list_node.h"

// using namespace std; // 这样也OK，别用范围那么大
using std::cout;
using std::endl;

struct ListNode* echoVal(struct ListNode* head) {
    cout << "val is:[" << head->val << "]" << endl;
    return head;
}

void echoList(struct ListNode* head) {
    struct ListNode *walk = head;

    while(walk != NULL) {
        if (walk != head) {
            cout << "->";
        }
        cout << walk->val;
        walk = walk->next;
    }
    cout << endl;
}

// struct ListNode* createLinkWith(int *arrInt, int len) {
struct ListNode* createLink(int *arrInt, int len) {
    struct ListNode *head = NULL, *walk = NULL;

    for (int i = 0; i < len; ++i) {
        if (head == NULL) {
            head = walk = new ListNode(arrInt[i]);
        } else {
            walk->next = new ListNode(arrInt[i]);
            walk = walk->next;
        }
    }

    return head;
}

struct ListNode* createLink(int len) {
    int *a = new int[len];
    for (int i = 0; i < len; ++i) {
        a[i] = i;
    }

    struct ListNode *head = createLink(a, len);
    // [] 的相对位置
    // delete []a;
    delete[] a;

    return head;
}
