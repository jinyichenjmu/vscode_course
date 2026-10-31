#include <iostream>
using namespace std;

typedef struct DLNode{
    int data;
    struct DLNode *prior;
    struct DLNode *next;
} DLinkNode;

void CreateListR(DLinkNode *&L, int a[], int n)
{
    L = new DLinkNode{0,nullptr,nullptr};
    DLinkNode *r = L;

    for(int i = 0;i<n;i++)
    {
        DLinkNode *s = new DLinkNode{a[i],nullptr,nullptr};
        s->prior = r;
        r->next = s;
        r = s;
    }
}

void sortList(DLinkNode *&L)
{
    if(L->next == nullptr || L->next->next == nullptr)
    {
        return;
    }
    DLinkNode *p = L->next->next;       //第一个数据节点认为有序.
    
    L->next->next = nullptr;

    while(p != nullptr)
    {
        DLinkNode *q = p->next;
        DLinkNode *pre = L;
        while(pre->next != nullptr && pre->next->data < p->data)
        {
            pre = pre->next;
        }

        p->next = pre->next;
        p->prior = pre;
        if(pre->next != nullptr)
        {
            pre->next->prior = p;
        }
        pre->next = p;
        
        p = q;
    }
}

void PrintForward(DLinkNode *L)
{
    DLinkNode *p = L->next;
    while(p != nullptr)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

void PrintBackward(DLinkNode *L)
{
    DLinkNode *p = L;
    while(p->next != nullptr)
    {
        p = p->next;
    }

    while(p != L)
    {
        cout << p->data << ' ';
        p = p->prior;
    }
    cout << endl;
}

void DestroyList(DLinkNode *&L)
{
    while(L != nullptr)
    {
        DLinkNode *next = L->next;
        delete L;
        L = next;
    }
}

int main() {
    int a[] = {4, 2, 5, 3};
    DLinkNode* L = nullptr;
    CreateListR(L, a, 4);

    cout << "Before: ";
    PrintForward(L);

    sortList(L);

    cout << "Forward: ";
    PrintForward(L);

    cout << "Backward: ";
    PrintBackward(L);

    DestroyList(L);
    return 0;
}