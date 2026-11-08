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

    for(int i = 0;text[i] != '\0'; i++)
    {
        LinkStrNode *p = new LinkStrNode{text[i], nullptr};
        r->next = p;
        r = p;
    }
}

void Append(LinkStrNode *&r, char ch)
{
    LinkStrNode *p = new LinkStrNode{ch, nullptr};
    r->next = p;
    r = p;
}

LinkStrNode *Concat(const LinkStrNode *s, const LinkStrNode *t)
{
    LinkStrNode *result = new LinkStrNode{'\0', nullptr};
    LinkStrNode *r = result;

    for(const LinkStrNode *p = s->next; p != nullptr; p = p->next)
    {
        Append(r, p->data);
    }

    for(const LinkStrNode *p = t->next; p != nullptr; p = p->next)
    {
        Append(r, p->data);
    }

    return result;
}

LinkStrNode *SubStr(const LinkStrNode *s, int i, int count)
{
    if(i < 1 || count < 0)
    {
        return nullptr;
    }

    const LinkStrNode *p = s->next;

    for(int position = 1; position < i && p != nullptr; position++)
    {
        p = p->next;
    }

    if(p == nullptr)
    {
        return nullptr;
    }

    const LinkStrNode *check = p;
    for(int k = 0; k < count; k ++)
    {
        if(check == nullptr)
        {
            return nullptr;
        }
        check = check->next;
    }

    LinkStrNode *result = new LinkStrNode{'\0', nullptr};
    LinkStrNode *r = result;
    for(int k = 0; k < count; k++)
    {
        Append(r, p->data);
        p = p->next;
    }

    return result;
}

void DispStr(LinkStrNode *s)
{
    LinkStrNode *p = s->next;
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
    StrAssign(b, "base");

    LinkStrNode* joined = Concat(a, b);
    LinkStrNode* part = SubStr(joined, 3, 4);

    cout << "Joined: ";
    DispStr(joined);

    if (part != nullptr) {
        cout << "Substring: ";
        DispStr(part);
    }

    DestroyStr(a);
    DestroyStr(b);
    DestroyStr(joined);
    DestroyStr(part);
    return 0;
}