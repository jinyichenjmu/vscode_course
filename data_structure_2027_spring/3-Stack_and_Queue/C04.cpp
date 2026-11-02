#include <iostream>
using namespace std;

struct LinkNode{
    int data;
    LinkNode *next;
};

void InitStack(LinkNode *&s)
{
    s = new LinkNode{0,nullptr};
}

bool StackEmpty(const LinkNode *s)
{
    return s->next == nullptr;
}

void Push(LinkNode *s, int e)
{
    LinkNode *p = new LinkNode{e,nullptr};
    p->next = s->next;
    s->next = p;
}

bool Pop(LinkNode *s, int &e)
{
    if(StackEmpty(s))
    {
        return false;
    }

    LinkNode *p = s->next;
    e = p->data;
    s->next = p->next;
    delete p;
    return true;
}

bool GetTop(const LinkNode *s, int &e)
{
    if(StackEmpty(s))
    {
        return false;
    }
    
    e = s->next->data;
    return true;
}

void DestroyStack(LinkNode *&s)
{
    while(s != nullptr)
    {
        LinkNode *next = s->next;
        delete s;
        s = next;
    }
}

int main() {
    LinkNode* s = nullptr;
    InitStack(s);

    cout << boolalpha;
    cout << "Empty: " << StackEmpty(s) << '\n';

    Push(s, 10);
    Push(s, 20);
    Push(s, 30);

    int value = 0;

    if (GetTop(s, value)) {
        cout << "Top: " << value << '\n';
    }

    if (Pop(s, value)) {
        cout << "Popped: " << value << '\n';
    }

    if (GetTop(s, value)) {
        cout << "New top: " << value << '\n';
    }

    DestroyStack(s);
    return 0;
}