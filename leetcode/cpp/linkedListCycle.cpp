#include <iostream>
#include "list_node.h"

using std::cout;
using std::endl;

/*****************************************************
 * Given a linked list, determine if it has a cycle in it.
 * 
 * Follow up:
 * Can you solve it without using extra space?
*****************************************************/

class Solution {
public:
    // also can impl through hash
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;

        ListNode *fast = head->next;
        while (fast != NULL && fast->next != NULL) {

            if (head == fast) return true;
            fast = fast->next->next;
            head = head->next;
        }
        return false;
    }
};


// 10:02, 10:12
int main(int argc, char* argv[]) {

    Solution *solu = new Solution();

    ListNode *head = createLink(7);
    // compose cycle
    int i=0;
    ListNode *walk = head;
    ListNode *theOne = NULL;
    ListNode *theEnd = NULL;
    int idxTheOne = 2;
    int idxEnd = 6;
    for (; i<=idxEnd; ++i) {
        if (i==idxTheOne) {
            theOne = walk;
        } else if (i==idxEnd) {
            theEnd= walk;
        }
        walk = walk->next;
    }

    theEnd->next = theOne;
    // echoList(head);
    cout << solu->hasCycle(head) << endl;

}
