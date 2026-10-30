#include <iostream>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
} LinkNode;

bool deleteNode(LinkNode *L,int i,int &e)
{
    if(i < 1 || L == nullptr)
    {
        return false;
    }


    LinkNode *p = L;
    int j = 0;
    while(p->next != NULL && j < i - 1)
    {
        j++;
        p = p->next;
    }
    if(p->next == NULL) return false;
    
    LinkNode *q = p->next;
    e = q->data;
    p->next = q->next;
    
    delete q;
    return true;
}

int main() {
    // 建立：头结点 → 10 → 15 → 20。
    LinkNode* head = new LinkNode{0, nullptr};
    LinkNode* first = new LinkNode{10, nullptr};
    LinkNode* middle = new LinkNode{15, nullptr};
    LinkNode* last = new LinkNode{20, nullptr};

    head->next = first;
    first->next = middle;
    middle->next = last;

    int e = 0;

    // 删除第 2 个数据结点。
    if (deleteNode(head, 2, e)) {
        cout << "Deleted: " << e << '\n';
    }

    // 输出删除后的链表。
    LinkNode* p = head->next;

    while (p != nullptr) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << '\n';

    // 释放剩余结点，包括头结点。
    p = head;

    while (p != nullptr) {
        LinkNode* next = p->next;
        delete p;
        p = next;
    }

    head = nullptr;
    return 0;
}