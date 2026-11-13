#include <iostream>
using namespace std;

struct LinkNode{
    int data;
    LinkNode *next;
};

void Release(LinkNode *&L)
{
    if(L == nullptr)
    {
        return;
    }

    Release(L->next);

    delete L;
    L = nullptr;

    return;
}

int main()
{
    // 创建不带头结点的链表：10 → 20 → 30
    LinkNode* L = new LinkNode{10, nullptr};
    L->next = new LinkNode{20, nullptr};
    L->next->next = new LinkNode{30, nullptr};

    Release(L);

    if (L == nullptr)
    {
        cout << "List released.\n";
    }

    return 0;
}