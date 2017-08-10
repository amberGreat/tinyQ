#include <iostream>

using std::cout;
using std::endl;

/***********************************************************************
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 **********************************************************************/

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

// 读了推荐解法后自己的实现，里面dummy_head或者pseudoHead的使用体会一下。也许，涉及到2条链表的时候，可以考虑dummyHead
// 12:05开始写, 12:22开始调试，12:35 Accepted
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;

        // copy node and follow original
        RandomListNode *iter = head, *dup = NULL;
        while (iter != NULL) {
            dup = new RandomListNode(iter->label);
            dup->next = iter->next;
            iter->next = dup;

            iter = dup->next;
        }

        // init random
        iter = head;
        while (iter != NULL) {
            if (iter->random != NULL) {
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }

        // restore original, extract copy
        // 小心最后一个元素的next要NULL
        iter = head;
        RandomListNode *dummyHead = new RandomListNode(0);
        RandomListNode *copyIter = dummyHead;
        while (iter != NULL) {

            copyIter->next = iter->next;
            copyIter = iter->next;

            iter->next = iter->next->next;
            iter = iter->next; // 一开始这句写成iter = iter->next->next; 是错的，因为上一句iter->next已经被赋值修改了。
        }

        return dummyHead->next;
    }
};

// 11:17开始思考, 11:21 有2个思路，但不够好
// (1)hash table，space complexity O(n);
// (2)另一个先复制单链表，再对每个node，遍历链表，判断random节点，time complexity O(n**2)
int main(int argc, char* argv[]) {
    Solution *solu = new Solution();
    RandomListNode *rst = solu->copyRandomList(NULL);
    // cout << "nice" << endl;
}
