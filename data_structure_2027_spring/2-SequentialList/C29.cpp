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

bool Symm(DLinkNode *L)
{
    if(L == nullptr || L->next == L)
    {
        return true;
    }
    DLinkNode *p = L->next;
    DLinkNode *q = L->prior;

    while(p != q)
    {
        if(p->data != q->data)
        {
            return false;
        }

        if(p->next == q->prior)
        {
            break;
        }

        p = p->next;
        q = q->prior;
    }
    return true;
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
    int a[] = {1, 2, 3, 2, 1};
    DLinkNode* L = nullptr;
    CreateListR(L, a, 5);

    cout << boolalpha;
    cout << "Symmetric: " << Symm(L) << '\n';

    DestroyList(L);
    return 0;
}