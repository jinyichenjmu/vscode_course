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

void DestroyList(LinkNode *&L)
{
    while(L != nullptr)
    {
        LinkNode *next = L->next;
        delete L;
        L = next;
    }
}

int maxnode(LinkNode *L)
{
    if(L->next == nullptr)
    {
        return L->data;
    }

    int max_next = maxnode(L->next);

    if(L->data > max_next)
    {
        return L->data;
    } 

    return max_next;
}

int minnode(LinkNode *L)
{
    if(L->next == nullptr)
    {
        return L->data;
    }

    int min_next = minnode(L->next);

    if(L->data > min_next)
    {
        return min_next;
    }
    return L->data;
}

int main(){
    int a[] = {1, 7, 2, 5};
    LinkNode *L = nullptr;
    CreateListR(L, a, 4);

    cout << "max: " << maxnode(L) << endl;
    cout << "min: " << minnode(L) << endl;

    DestroyList(L);
}