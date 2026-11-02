#include <iostream>
using namespace std;

const int MaxSize = 6;

struct DStack{
    int data[MaxSize];
    int top1;
    int top2;
};

void InitStack(DStack *&s)
{
    s = new DStack{};
    s->top1 = -1;
    s->top2 = MaxSize;
}

bool Push(DStack *s, int which, int e)
{
    if(which != 1 && which != 2)
    {
        return false;
    }

    if(s->top1 + 1 == s->top2)
    {
        return false;
    }

    if(which == 1)
    {
        s->top1 ++;
        s->data[s->top1] = e;
    }
    else{
        s->top2 --;
        s->data[s->top2] = e;
    }
    return true;
}

bool Pop(DStack *s, int which, int &e)
{
    if(which == 1)
    {
        if(s->top1 == -1)
        {
            return false;
        }

        e = s->data[s->top1];
        s->top1 --;
        return true;
    }

    if(which == 2)
    {
        if(s->top2 == MaxSize)
        {
            return false;
        }

        e = s->data[s->top2];
        s->top2 ++;
        return true;
    }

    return false;
}

void DestroyStack(DStack *&s)
{
    delete s;
    s = nullptr;
}

int main()
{
    DStack* s = nullptr;
    InitStack(s);

    Push(s, 1, 10);
    Push(s, 1, 20);
    Push(s, 2, 30);
    Push(s, 2, 40);

    int e = 0;

    if (Pop(s, 1, e)) {
        cout << "Stack 1 pop: " << e << '\n';
    }

    if (Pop(s, 2, e)) {
        cout << "Stack 2 pop: " << e << '\n';
    }

    DestroyStack(s);
    return 0;
}