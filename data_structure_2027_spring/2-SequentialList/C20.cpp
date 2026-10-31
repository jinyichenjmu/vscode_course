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

    for(int i = 0;i<n;i++)
    {
        LinkNode *s = new LinkNode{a[i],nullptr};
        r->next = s;
        r = s;
    }
}

void sortList(LinkNode *&L)
{
    if(L->next == nullptr || L->next->next == nullptr)
    {
        return;
    }

    LinkNode *p = L->next->next;        //待处理节点，首节点作为有序
    L->next->next = nullptr;

    while(p != nullptr)
    {
        LinkNode *q = p->next;

        LinkNode *pre = L;
        while(pre->next != nullptr && pre->next->data < p->data)
        {
            pre = pre->next;
        }

        p->next = pre->next;
        pre->next = p;

        p = q;
    }
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
    int a[] = {4, 2, 5, 3};
    LinkNode* L = nullptr;

    CreateListR(L, a, 4);

    cout << "Before: ";
    DispList(L);

    sortList(L);

    cout << "After: ";
    DispList(L);

    DestroyList(L);
    return 0;
}