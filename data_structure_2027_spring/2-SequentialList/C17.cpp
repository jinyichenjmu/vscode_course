#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LinkNode;

void InitList(LinkNode *&L)
{
    L = new LinkNode{0, nullptr};
}

// linux c coding style: bool list_empty(){}

bool ListEmpty(LinkNode *L)
{
    return L->next == nullptr;
}

int ListLength(LinkNode *L)
{
    int n = 0;
    LinkNode *p = L;
    while (p->next != nullptr)
    {
        p = p->next;
        n++;
    }

    return n;
}

bool GetElem(LinkNode *L, int i, int &e)
{
    int j = 0;
    LinkNode *p = L;

    if (i <= 0)
        return false;

    while (j < i && p != nullptr)
    {
        j++;
        p = p->next;
    }

    if (p == nullptr)
        return false;

    e = p->data;
    return true;
}

int LocateElem(LinkNode *L, int e)
{
    int i = 1;
    LinkNode *p = L->next;
    while (p != nullptr && p->data != e)
    {
        i++;
        p = p->next;
    }

    if (p == nullptr)
        return 0;

    return i;
}

void DestroyList(LinkNode *&L)
{
    while (L != nullptr)
    {
        LinkNode *next = L->next;
        delete L;
        L = next;
    }
}

int main()
{
    LinkNode *L = nullptr;
    InitList(L);

    cout << boolalpha << "Empty: " << ListEmpty(L) << '\n';

    // 为了演示，建立：头结点 → 10 → 20 → 30。
    L->next = new LinkNode{10, nullptr};
    L->next->next = new LinkNode{20, nullptr};
    L->next->next->next = new LinkNode{30, nullptr};

    cout << "Length: " << ListLength(L) << '\n';

    int e = 0;
    if (GetElem(L, 2, e))
    {
        cout << "Element 2: " << e << '\n';
    }

    cout << "Position of 30: " << LocateElem(L, 30) << '\n';

    DestroyList(L);
    return 0;
}