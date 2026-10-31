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

void reverseList(DLinkNode *&L)
{
    DLinkNode *p = L->next;
    L->next = nullptr;

    while(p != nullptr)
    {
        DLinkNode *q = p->next;

        p->next = L->next;
        if(L->next != nullptr)
        {
            L->next->prior = p;
        }
        
        p->prior = L;
        L->next = p;

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
    int a[] = {10, 20, 30};
    DLinkNode* L = nullptr;
    CreateListR(L, a, 3);

    cout << "Before: ";
    PrintForward(L);

    reverseList(L);

    cout << "Forward: ";
    PrintForward(L);

    cout << "Backward: ";
    PrintBackward(L);

    DestroyList(L);
    return 0;
}