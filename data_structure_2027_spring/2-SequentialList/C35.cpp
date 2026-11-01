#include <iostream>
using namespace std;

struct LinkNode{
    int data;
    LinkNode *next;
};

LinkNode *CreateListR(int a[], int n)
{
    LinkNode *L = new LinkNode{0,nullptr};
    LinkNode *r = L;

    for(int i = 0;i<n;i++)
    {
        LinkNode *s = new LinkNode{a[i],nullptr};
        r->next = s;
        r = s;
    }

    return L;
}

void DeleteDuplicates(LinkNode *&L)
{
    LinkNode *p = L->next;
    if(p == nullptr)
    {
        return;
    }

    while(p->next != nullptr)
    {
        if(p->data == p->next->data)
        {
            LinkNode *q = p->next;
            p->next = q->next;
            delete q;

            //不移动 让其继续检查后继
        }
        else
        {
            p = p->next;
        }
    }
}

void PrintList(LinkNode *L)
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
    while(L != nullptr)
    {
        LinkNode *next = L->next;
        delete L;
        L = next;
    }
}

int main() {
    int a[] = {1, 1, 1, 3, 3, 5};
    LinkNode* L = CreateListR(a, 6);

    cout << "Before: ";
    PrintList(L);

    DeleteDuplicates(L);

    cout << "After: ";
    PrintList(L);

    DestroyList(L);
    return 0;
}