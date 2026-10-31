#include <iostream>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
} LinkNode;

void CreateListR(LinkNode *&L,int a[],int n)
{
    L = new LinkNode{0,nullptr};
    LinkNode *r = L;

    for(int i = 0;i<n;i++){
        LinkNode *s = new LinkNode{a[i],nullptr};
        r->next = s;
        r = s;
    }
}

void split(LinkNode*& L, LinkNode*& L1, LinkNode*& L2)
{
    LinkNode *p = L->next; //当前待处理节点
    LinkNode *q;        //暂存下一个节点
    LinkNode *r1;        //始终指向L1的尾节点

    L1 = L;       //L1沿用原本头节点
    r1 = L1;

    L2 = new LinkNode{0,nullptr};     //新建L2

    while(p != nullptr)
    {
        r1->next = p;       //尾插L1
        r1 = p;

        p = p->next;    //移动待处理节点
        q = p->next;

        p->next = L2->next;     //头插L2
        L2->next = p;

        p = q;      //移动待处理节点
    }

    r1->next = nullptr;     //保证尾节点指向空指针
}

void DispList(LinkNode *L)
{
    LinkNode *p = L->next;
    while(p != nullptr)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

void DestroyList(LinkNode *&L)
{
    LinkNode *p = L;
    while(p != nullptr)
    {
        LinkNode *next = p->next;
        delete p;
        p = next;
    }
    L = nullptr;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};

    LinkNode* L = nullptr;
    LinkNode* L1 = nullptr;
    LinkNode* L2 = nullptr;

    CreateListR(L, a, 6);

    cout << "Original: ";
    DispList(L);

    split(L, L1, L2);

    cout << "L1: ";
    DispList(L1);

    cout << "L2: ";
    DispList(L2);

    // L 和 L1 指向同一个头结点，只通过 L1 释放一次。
    DestroyList(L1);
    L = nullptr;

    DestroyList(L2);

    return 0;
}
