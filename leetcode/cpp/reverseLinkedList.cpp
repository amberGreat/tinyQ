#include <iostream>

using namespace std;

// TODO:
// 1) 使用typedef来简单定义，不过，node似乎可直接使用，不用带struct
// 2) 给node加个构造函数

// 没有构造函数的话， node ini = new node(6, NULL) 会报错，说参数多
// TODO 构造函数一定不要有分号，试一下
// 结构体里面，可以使用本身这个结构体
struct node {
    int v;
    struct node *next;
    node(int x) : v(x), next(NULL) {}
};
// 记得要分号

struct node* echoVal(struct node* head) {
    cout << "val is:[" << head->v << "]" << endl;
    return head;
}

void echoList(struct node* head) {
    struct node *walk = head;

    while(walk != NULL) {
        if (walk != head) {
            cout << "->";
        }
        cout << walk->v;
        walk = walk->next;
    }
    cout << endl;
}

// struct node* createLinkWith(int *arrInt, int len) {
struct node* createLink(int *arrInt, int len) {
    struct node *head = NULL, *walk = NULL;

    for (int i = 0; i < len; ++i) {
        if (head == NULL) {
            head = walk = new node(arrInt[i]);
        } else {
            walk->next = new node(arrInt[i]);
            walk = walk->next;
        }
    }

    return head;
}

struct node* createLink(int len) {
    int *a = new int[len];
    for (int i = 0; i < len; ++i) {
        a[i] = i;
    }

    struct node *head = createLink(a, len);
    // [] 的相对位置
    // delete []a;
    delete[] a;

    return head;
}

struct node* reverseLink(struct node* head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct node *walk = head;
    struct node *temp = NULL;
    struct node *prev = NULL;

    while (walk != NULL) {
        temp = walk;
        walk = walk->next;
        temp->next = prev;
        prev = temp;
    }

    return temp;
}

int main(){

    cout << "hahah" << endl;
    // struct 有构造函数之后，不能直接{}初始化
    // in C++98 'ini' must be initialized by constructor, not by '{...}'
    // struct node ini = {3, NULL};
    // struct node *head = &ini;

    // node *head = new node(6);
    // echoVal(head);

    struct node *head = createLink(5);
    echoList(head);

    head = reverseLink(head);
    echoList(head);

    return 1;
}
