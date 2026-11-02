#include <iostream>
using namespace std;

struct LinkStNode{
    char data;
    LinkStNode *next;
};

void InitStack(LinkStNode *&s)
{
    s = new LinkStNode{0,nullptr};
}

bool StackEmpty(LinkStNode *s)
{
    return s->next == nullptr;
}

void Push(LinkStNode *s, char e)
{
    LinkStNode *p = new LinkStNode{e,nullptr};
    p->next = s->next;
    s->next = p;
}

bool Pop(LinkStNode *s, char &e)
{
    if(StackEmpty(s))
    {
        return false;
    }
    LinkStNode *p = s->next;
    
    e = p->data;
    s->next = p->next;
    delete p;
    return true;
}

void DestroyStack(LinkStNode *&s)
{
    while(s != nullptr)
    {
        LinkStNode *next = s->next;
        delete s;
        s = next;
    }
}

bool Match(const string &exp)
{
    LinkStNode *s = nullptr;
    InitStack(s);

    bool match = true;

    for(char ch : exp)
    {
        if(ch == '(')
        {
            Push(s,ch);
        }
        else if(ch == ')')
        {
            char e;
            if(!Pop(s,e))   
            {
                match = false;
                break;
            }

            if(e != '(')
            {
                match = false;
                break;
            }
        }
    }

    if(!StackEmpty(s))
    {
        match = false;
    }

    DestroyStack(s);
    return match;
}

int main()
{
    string exp = "(a + (b * c))";

    cout << boolalpha;
    cout << "Matched: " << Match(exp) << '\n';

    return 0;
}