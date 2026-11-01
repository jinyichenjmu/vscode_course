#include <iostream>
using namespace std;

const int MaxSize = 100;

struct SqList{
    int data[MaxSize];
    int length;
};

struct LinkNode{
    int data;
    LinkNode *next;
};

bool InsertOrdered(SqList *L,int e)
{
    if(L->length == MaxSize)
    {
        return false;
    }

    int i = 0;
    while(i < L->length && L->data[i] < e)
    {
        i ++;
    }

    for(int j = L->length; j > i; j--)
    {
        L->data[j] = L->data[j-1];
    }

    L->data[i] = e;
    L->length ++;
    return true;
}

void InsertOrdered(LinkNode *L, int e)
{
    LinkNode *pre = L;

    while(pre->next != nullptr && pre->next->data < e)
    {
        pre = pre->next;
    }

    LinkNode *s = new LinkNode{e,nullptr};

    s->next = pre->next;
    pre->next = s;
}

void PrintList(const SqList *L)
{
    for(int i = 0;i < L->length;i++)
    {
        cout << L->data[i] << ' ';
    }
    cout << endl;
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
    // 两张表初始时都为空，依次插入相同的值。
    SqList A{{}, 0};
    LinkNode* B = new LinkNode{0, nullptr};

    int values[] = {3, 7, 1, 5};

    for (int value : values) {
        InsertOrdered(&A, value);
        InsertOrdered(B, value);
    }

    cout << "Sequential: ";
    PrintList(&A);

    cout << "Linked: ";
    PrintList(B);

    DestroyList(B);
    return 0;
}