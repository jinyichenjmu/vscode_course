#include <iostream>
using namespace std;

struct LinkNode{
    int data;
    LinkNode *next;
};

LinkNode *CreateListR(const int a[], int n)
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

void Append(LinkNode *&r, int e)
{
    LinkNode *s = new LinkNode{e,nullptr};
    r->next = s;
    r = s;
}

LinkNode *UnionList(const LinkNode *A, const LinkNode *B)
{
    LinkNode *C = new LinkNode{0,nullptr};      //新建头节点
    LinkNode *r = C;

    LinkNode *pa = A->next, *pb = B->next;

    while(pa != nullptr && pb != nullptr)
    {
        if(pa->data < pb->data)
        {
            Append(r,pa->data);
            pa = pa->next;
        }
        else
        {
            Append(r,pb->data);
            pb = pb->next;
        }
    }

    while(pa != nullptr)
    {
        Append(r,pa->data);
        pa = pa->next;
    }

    while(pb != nullptr)
    {
        Append(r,pb->data);
        pb = pb->next;
    }

    return C;
}

void PrintList(const LinkNode *L)
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
    int a[] = {1, 3, 5};
    int b[] = {2, 4, 8, 10};

    LinkNode* A = CreateListR(a, 3);
    LinkNode* B = CreateListR(b, 4);
    LinkNode* C = UnionList(A, B);

    cout << "A: ";
    PrintList(A);

    cout << "B: ";
    PrintList(B);

    cout << "C: ";
    PrintList(C);

    DestroyList(A);
    DestroyList(B);
    DestroyList(C);
    return 0;
}