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

void PrintList(LinkNode *L)
{
    while(L != nullptr)
    {
        cout << L->data << ' ';
        L = L->next;
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

void del(LinkNode *&L, int key)
{
    if(L == nullptr)
    {
        return;
    }

    if(L->data == key)
    {
        LinkNode *p = L;
        L = L->next;
        delete p;

        return;
    }

    del(L->next, key);
}

void delall(LinkNode *&L, int key)
{
    if(L == nullptr)
    {
        return;
    }
    if(L->data == key)
    {
        LinkNode *p = L;
        L = L->next;
        delete p;

        delall(L, key);
        return;
    }

    delall(L->next, key);
}

int main(){
    int a[] = {1, 3, 5, 3, 3, 3, 2};
    LinkNode *L = nullptr;
    CreateListR(L, a, 7);

    cout << "Before: ";
    PrintList(L);

    del(L, 2);
    cout << "After delete 2: ";
    PrintList(L);

    delall(L, 3);
    cout << "After delete 3: ";
    PrintList(L);

    DestroyList(L);
}