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

bool ReplaceFirstAB(LinkStrNode *s)
{
    LinkStrNode *p = s->next;

    while(p != nullptr && p ->next != nullptr)
    {
        if(p->data == 'a' && p->next->data == 'b')
        {
            LinkStrNode *q = new LinkStrNode{'y', nullptr};

            p->data = 'x';
            p->next->data = 'z';

            q->next = p->next;
            p->next = q;
            
            return true;
        }
        p = p->next;
    }
    return false;
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
    LinkStrNode* s = nullptr;
    StrAssign(s, "cabab");

    cout << "Before: ";
    DispStr(s);

    if (ReplaceFirstAB(s)) {
        cout << "After: ";
        DispStr(s);
    } else {
        cout << "No match.\n";
    }

    DestroyStr(s);
    return 0;
}