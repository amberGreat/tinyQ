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

// �����Ƽ��ⷨ���Լ���ʵ�֣�����dummy_head����pseudoHead��ʹ�����һ�¡�Ҳ���漰��2�������ʱ�򣬿��Կ���dummyHead
// 12:05��ʼд, 12:22��ʼ���ԣ�12:35 Accepted
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
        // С�����һ��Ԫ�ص�nextҪNULL
        iter = head;
        RandomListNode *dummyHead = new RandomListNode(0);
        RandomListNode *copyIter = dummyHead;
        while (iter != NULL) {

            copyIter->next = iter->next;
            copyIter = iter->next;

            iter->next = iter->next->next;
            iter = iter->next; // һ��ʼ���д��iter = iter->next->next; �Ǵ�ģ���Ϊ��һ��iter->next�Ѿ�����ֵ�޸��ˡ�
        }

        return dummyHead->next;
    }
};

// 11:17��ʼ˼��, 11:21 ��2��˼·����������
// (1)hash table��space complexity O(n);
// (2)��һ���ȸ��Ƶ������ٶ�ÿ��node�����������ж�random�ڵ㣬time complexity O(n**2)
int main(int argc, char* argv[]) {
    Solution *solu = new Solution();
    RandomListNode *rst = solu->copyRandomList(NULL);
    // cout << "nice" << endl;
}
