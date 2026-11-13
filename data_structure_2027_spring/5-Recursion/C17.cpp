#include <iostream>
using namespace std;

struct LinkNode{
    int data;
    LinkNode *next;
};

void CreateListR(LinkNode *&L, int a[], int n)
{
    if(n == 0)
    {
        L = nullptr;
        return;
    }

    L = new LinkNode{a[0], nullptr};
    LinkNode *r = L;

    for(int i = 1; i < n; i++)
    {
        LinkNode *s = new LinkNode{a[i], nullptr};
        r->next = s;
        r = s;
    }
}

void traverse(LinkNode *L)
{
    if(L == nullptr)
    {
        return;
    }

    cout << L->data << " ";
    traverse(L->next);
}

void traverseR(LinkNode *L)
{
    if(L == nullptr)
    {
        return;
    }

    traverseR(L->next);
    cout << L->data << " ";
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

int main(){
    int a[] = {1, 3, 4};

    LinkNode *L = nullptr;
    CreateListR(L, a, 3);

    traverse(L);
    cout << endl;
    traverseR(L);
    cout << endl;

    DestroyList(L);
}