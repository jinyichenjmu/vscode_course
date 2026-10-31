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
        r->next = s;
        s->prior = r;
        r = s;
    }
}

bool ListInsert(DLinkNode *&L, int i, int e)
{
    if(i <= 0)
    {
        return false;
    }

    DLinkNode *p = L;
    int j = 0;

    while(p->next != nullptr && j < i-1)
    {
        j++;
        p = p->next;
    }

    if(j != i-1)
    {
        return false;
    }

    DLinkNode *q = p->next;
    DLinkNode *s = new DLinkNode{e,nullptr,nullptr};

    s->next = q;
    s->prior = p;
    
    if(q != nullptr)
    {
        q->prior = s;
    }
    p->next = s;
    return true;
}

void PrintForward(DLinkNode *L)
{
    DLinkNode *p = L->next;
    while (p != nullptr)
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

    if (ListInsert(L, 2, 15)) {
        cout << "Forward: ";
        PrintForward(L);

        cout << "Backward: ";
        PrintBackward(L);
    }

    DestroyList(L);
    return 0;
}