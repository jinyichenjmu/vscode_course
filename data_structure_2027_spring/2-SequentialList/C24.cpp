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

bool ListDelete(DLinkNode *&L, int i, int &e)
{
    if(i < 1)
    {
        return false;
    }
    DLinkNode *p = L;

    int j = 0;
    while(p != nullptr && j < i)
    {
        j++;
        p = p->next;
    }

    if(p == nullptr)
    {
        return false;
    }

    e = p->data;

    if(p->next != nullptr)
    {
        p->next->prior = p->prior;
    }
    p->prior->next = p->next;
    delete p;
    return true;
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

    int e = 0;

    if (ListDelete(L, 2, e)) {
        cout << "Deleted: " << e << '\n';

        cout << "Forward: ";
        PrintForward(L);

        cout << "Backward: ";
        PrintBackward(L);
    }

    DestroyList(L);
    return 0;
}