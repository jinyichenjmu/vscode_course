#include <iostream>
using namespace std;

struct LinkNode{
    int data;
    LinkNode *next;
};

void CreateListR(LinkNode *&L, int a[], int n)
{

    L = new LinkNode{0,nullptr};
    LinkNode *r = L;

    if(n == 0)
    {
        return;
    }

    for(int i = 0;i<n;i++)
    {
        LinkNode *s = new LinkNode{a[i],nullptr};
        r->next = s;
        r = s;
    }
}

void Append(LinkNode *&L,LinkNode *&r,int value)
{
    if(r == L || r->data != value)
    {
        LinkNode *s = new LinkNode{value,nullptr};
        r->next = s;
        r = s;
    }
}
LinkNode *UnionList(LinkNode *A, LinkNode *B)
{
    LinkNode *pa = A->next;
    LinkNode *pb = B->next;

    LinkNode *C = new LinkNode{0,nullptr};
    LinkNode *r = C;

    while(pa != nullptr && pb != nullptr)
    {
        if(pa->data < pb->data)
        {
            Append(C,r,pa->data);
            pa = pa->next;
        }
        else
        {
            Append(C,r,pb->data);
            pb = pb->next;
        }
    }

    while(pa != nullptr)
    {
        Append(C,r,pa->data);
        pa = pa->next;
    }
    while(pb != nullptr)
    {
        Append(C,r,pb->data);
        pb = pb->next;
    }
    
    return C;
}

bool ListEmpty(LinkNode *L)
{
    if(L->next == nullptr)
    {
        return true;
    }
    return false;
}

void DispList(LinkNode *L)
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

int main()
{
    int a[100] = {1, 2, 4, 5};
    int b[100] = {2, 3, 4, 6};

    LinkNode *A;
    CreateListR(A,a,4);
    LinkNode *B;
    CreateListR(B,b,4);

    cout << "A:";
    DispList(A);
    cout << "B:";
    DispList(B);

    LinkNode *C = UnionList(A,B);

    cout << "C:";
    DispList(C);

    cout << boolalpha << "empty:" << ListEmpty(C) << endl;

    DestroyList(A);
    DestroyList(B);
    DestroyList(C);
    
}