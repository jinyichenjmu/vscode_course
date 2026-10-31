#include <iostream>
using namespace std;

typedef struct LNode{
    int date;
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

bool delmaxnode(LinkNode *&L)
{
    if(L == nullptr)
    {
        return false;
    }

    LinkNode *pre = L;
    LinkNode *maxPre = L;

    while(pre->next != nullptr)
    {
        if(maxPre->next->date < pre->next->date)
        {
            maxPre = pre;
        }
        pre = pre->next;
    }

    if(maxPre->next == nullptr)
    {
        return false;
    }

    LinkNode *target = maxPre->next;
    maxPre->next = target->next;
    delete target;
    return true;
}

void DispList(LinkNode *L)
{
    LinkNode *p = L->next;
    while(p != nullptr)
    {
        cout << p->date << ' ';
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
    int a[] = {10, 30, 20};
    LinkNode* L = nullptr;

    CreateListR(L, a, 3);

    cout << "Before: ";
    DispList(L);

    if (delmaxnode(L)) {
        cout << "After: ";
        DispList(L);
    }

    DestroyList(L);
    return 0;
}