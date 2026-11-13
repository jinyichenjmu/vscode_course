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

    for(int i = 1; i < n; i ++)
    {
        LinkNode *s = new LinkNode{a[i], nullptr};
        
        r->next = s;
        r = s;
    }
}

int count(LinkNode *L)
{
    if(L == nullptr)
    {
        return 0;
    }

    return count(L->next) + 1;
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
    LinkNode *L;
    int a[3] = {1, 2, 3};
    CreateListR(L, a, 3);

    cout << count(L) << endl;

    DestroyList(L);
}