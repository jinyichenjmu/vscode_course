#include <iostream>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
} LinkNode;

void CreateListR(LinkNode *&L, int a[], int n)
{
    L = new LinkNode{0,nullptr};
    L->next = L;    //形成空环

    LinkNode *r = L;

    for(int i = 0;i<n;i++)
    {
        LinkNode *s = new LinkNode{a[i],L};
        r->next = s;
        r = s;
    }
}

int countValue(LinkNode *L, int value)
{
    int count = 0;
    LinkNode *p = L->next;
    while(p != L)
    {
        if(p->data == value)
        {
            count ++;
        }
        p = p->next;
    }
    return count;
}

void DestroyList(LinkNode *&L)
{
    LinkNode *p = L->next;
    while(p != L)
    {
        LinkNode *next = p->next;
        delete p;
        p = next;
    }
    delete L;
    L = nullptr;
}

int main() {
    int a[] = {10, 20, 10};
    LinkNode* L = nullptr;

    CreateListR(L, a, 3);

    cout << "Count of 10: " << countValue(L, 10) << '\n';
    cout << "Count of 30: " << countValue(L, 30) << '\n';

    DestroyList(L);
    return 0;
}