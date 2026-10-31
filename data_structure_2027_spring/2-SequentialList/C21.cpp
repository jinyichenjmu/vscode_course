#include <iostream>
using namespace std;

typedef struct DNode{
    int data;
    struct DNode *prior;
    struct DNode *next;
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
    DLinkNode *p = L;
    while(p != nullptr)
    {
        DLinkNode *next = p->next;
        delete p;
        p = next;
    }
    L = nullptr;
}

int main() {
    int a[] = {10, 20, 30};
    DLinkNode* L = nullptr;

    CreateListR(L, a, 3);

    cout << "Forward: ";
    PrintForward(L);

    cout << "Backward: ";
    PrintBackward(L);

    DestroyList(L);
    return 0;
}

