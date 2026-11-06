#include <iostream>
using namespace std;

struct LinkStrNode{
    char data;
    LinkStrNode *next;
};

void StrAssign(LinkStrNode *&s, const char text[])
{
    s = new LinkStrNode{'\0', nullptr};
    LinkStrNode *r = s;

    for(int i = 0; text[i] != '\0'; i++)
    {
        LinkStrNode *p = new LinkStrNode{text[i], nullptr};
        r->next = p;
        r = p;
    }
}

void StrCopy(LinkStrNode *&s, const LinkStrNode *t)
{
    s = new LinkStrNode{'\0', nullptr};
    LinkStrNode *r = s;

    const LinkStrNode* p = t->next;

    while(p != nullptr)
    {
        LinkStrNode *node = new LinkStrNode{p->data, nullptr};
        r->next = node;
        r = node;
        p = p->next;
    }
}

int StrLength(const LinkStrNode *s)
{
    int length = 0;
    const LinkStrNode *p = s->next;

    while(p != nullptr)
    {
        length ++;
        p = p->next;
    }

    return length;
}

bool StrEqual(const LinkStrNode *s, const LinkStrNode *t)
{
    const LinkStrNode *p = s->next;
    const LinkStrNode *q = t->next;

    while(p != nullptr && q != nullptr)
    {
        if(p->data != q->data)
        {
            return false;
        }
        p = p->next;
        q = q->next;
    }

    return p == nullptr && q == nullptr;
}

void DispStr(const LinkStrNode *s)
{
    const LinkStrNode *p = s->next;

    while(p != nullptr)
    {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}

void DestroyStr(LinkStrNode *&s)
{
    while(s != nullptr)
    {
        LinkStrNode *next = s->next;
        delete s;
        s = next;
    }
}

int main() {
    LinkStrNode* a = nullptr;
    LinkStrNode* b = nullptr;

    StrAssign(a, "data");
    StrCopy(b, a);

    cout << "a: ";
    DispStr(a);

    cout << "b: ";
    DispStr(b);

    cout << "Length: " << StrLength(a) << '\n';
    cout << boolalpha << "Equal: " << StrEqual(a, b) << '\n';

    DestroyStr(a);
    DestroyStr(b);
    return 0;
}