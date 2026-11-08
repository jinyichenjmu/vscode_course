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

int StrLength(const LinkStrNode *s)
{
    int length = 0;

    LinkStrNode *p = s->next;
    while(p != nullptr)
    {
        length ++;
        p = p->next;
    }

    return length;
}

void Append(LinkStrNode *&r, char ch)
{
    LinkStrNode *p = new LinkStrNode{ch, nullptr};
    r->next = p;
    r = p;
}

LinkStrNode *InsStr(const LinkStrNode *s, int i, const LinkStrNode *t)
{
    int length = StrLength(s);

    if(i < 1 || i > length + 1)
    {
        return nullptr;
    }

    LinkStrNode *result = new LinkStrNode{'\0', nullptr};
    LinkStrNode *r = result;
    const LinkStrNode* p = s->next;

    for(int k = 1; k < i; k++)
    {
        Append(r, p->data);
        p = p->next;
    }

    for(const LinkStrNode *q = t->next; q != nullptr; q = q->next)
    {
        Append(r, q->data);
    }

    while(p != nullptr)
    {
        Append(r, p->data);
        p = p->next;
    }

    return result;
}

LinkStrNode *DelStr(const LinkStrNode *s, int i, int count)
{
    int length = StrLength(s);
    if(i < 1 || i > length || count < 0 || count > length - (i - 1))
    {
        return nullptr;
    }

    LinkStrNode *result = new LinkStrNode{'\0', nullptr};
    LinkStrNode *r = result;
    const LinkStrNode *p = s->next;

    for(int k = 1; k < i; k++)
    {
        Append(r, p->data);
        p = p->next;
    }

    for(int k = 0; k < count; k++)
    {
        p = p->next;
    }

    while(p != nullptr)
    {
        Append(r, p->data);
        p = p->next;
    }

    return result;
}

LinkStrNode *RepStr(const LinkStrNode *s, int i, int count, const LinkStrNode *t)
{
    int length = StrLength(s);

    if(i < 1 || i > length || count < 0 || count > length - (i - 1))
    {
        return nullptr;
    }

    LinkStrNode *result = new LinkStrNode{'\0', nullptr};
    LinkStrNode *r = result;
    const LinkStrNode *p = s->next;

    for(int k = 1; k < i; k++)
    {
        Append(r, p->data);
        p = p->next;
    }

    for(const LinkStrNode *q = t->next; q != nullptr; q = q->next)
    {
        Append(r, q->data);
    }

    for(int k = 0; k < count; k++)
    {
        p = p->next;
    }

    while(p != nullptr)
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
    LinkStrNode* t = nullptr;

    StrAssign(a, "abcd");
    StrAssign(t, "XY");

    LinkStrNode* inserted = InsStr(a, 3, t);
    LinkStrNode* deleted = DelStr(a, 3, 2);
    LinkStrNode* replaced = RepStr(a, 2, 2, t);

    if (inserted != nullptr) {
        cout << "Insert: ";
        DispStr(inserted);
    }

    if (deleted != nullptr) {
        cout << "Delete: ";
        DispStr(deleted);
    }

    if (replaced != nullptr) {
        cout << "Replace: ";
        DispStr(replaced);
    }

    cout << "Original: ";
    DispStr(a);

    DestroyStr(a);
    DestroyStr(t);
    DestroyStr(inserted);
    DestroyStr(deleted);
    DestroyStr(replaced);
    return 0;
}