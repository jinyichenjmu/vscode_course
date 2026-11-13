#include <iostream>
using namespace std;

struct LinkNode{
    int data;
    LinkNode *next;
};

int Sum(LinkNode *L)
{
    if(L == nullptr)
    {
        return 0;
    }

    return L->data + Sum(L->next);
}

int main()
{
    // 从后往前创建结点，组成 10 → 20 → 30
    LinkNode third{30, nullptr};
    LinkNode second{20, &third};
    LinkNode first{10, &second};

    LinkNode* L = &first;

    cout << "Sum: " << Sum(L) << '\n';

    return 0;
}