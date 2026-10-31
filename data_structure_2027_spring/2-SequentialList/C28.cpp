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
    L->next = L;
    L->prior = L;

    DLinkNode *r = L;

    for(int i = 0;i<n;i++)
    {
        DLinkNode *s = new DLinkNode{a[i],r,L};

        r->next = s;
        L->prior = s;

        r = s;
    }
}

bool deleteValue(DLinkNode *&L, int x)
{
    DLinkNode *p = L->next;
    while(p != L && p->data != x)
    {
        p = p->next;
    }

    if(p->data != x || p == L)
    {
        return false;
    }

    p->prior->next = p->next;
    p->next->prior = p->prior;
    delete p;
    return true;
}

void PrintForward(DLinkNode *L)
{
    DLinkNode *p = L->next;
    while(p != L)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

void PrintBackward(DLinkNode *L)
{
    DLinkNode *p = L->next;
    while(p->next != L)
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
    DLinkNode *p = L->next;
    while(p != L)
    {
        DLinkNode *next = p->next;
        delete p;
        p = next;
    }

    delete L;
    L = nullptr;
}

int main() {
    int a[] = {10, 20, 10};
    DLinkNode* L = nullptr;
    CreateListR(L, a, 3);

    cout << "Before: ";
    PrintForward(L);

    if (deleteValue(L, 10)) {
        cout << "Forward: ";
        PrintForward(L);

        cout << "Backward: ";
        PrintBackward(L);
    }

    DestroyList(L);
    return 0;
}