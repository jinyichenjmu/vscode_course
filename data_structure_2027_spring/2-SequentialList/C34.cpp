#include <iostream>
using namespace std;

struct LinkNode
{
    int data;
    LinkNode *next;
};

LinkNode *CreateListR(const int a[], int n)
{
    LinkNode *L = new LinkNode{0, nullptr};
    LinkNode *r = L;

    for (int i = 0; i < n; i++)
    {
        LinkNode *s = new LinkNode{a[i], nullptr};
        r->next = s;
        r = s;
    }

    return L;
}

void CommonNodes(LinkNode *A, const LinkNode *B, const LinkNode *C)
{
    LinkNode *pa = A->next;
    const LinkNode *pb = B->next;
    const LinkNode *pc = C->next;

    A->next = nullptr;
    LinkNode *r = A;

    while (pa != nullptr)
    {
        while (pb != nullptr && pb->data < pa->data)
        {
            pb = pb->next;
        }
        while (pc != nullptr && pc->data < pa->data)
        {
            pc = pc->next;
        }

        if (pb != nullptr && pc != nullptr && pb->data == pa->data && pc->data == pa->data)
        {
            r->next = pa;
            r = pa;
            pa = pa->next;
        }
        else
        {
            LinkNode *next = pa->next;
            delete pa;
            pa = next;
        }
    }
    r->next = nullptr;
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
    int a[] = {1, 2, 4, 6};
    int b[] = {2, 3, 4, 6};
    int c[] = {0, 2, 4, 5};

    LinkNode* A = CreateListR(a, 4);
    LinkNode* B = CreateListR(b, 4);
    LinkNode* C = CreateListR(c, 4);

    CommonNodes(A, B, C);

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