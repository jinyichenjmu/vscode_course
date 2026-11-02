#include <iostream>
using namespace std;

const int MaxSize = 5;

struct SqStack{
    int data[MaxSize];
    int top;
};

void InitStack(SqStack *&q)
{
    q = new SqStack{};
    q->top = -1;
}

bool StackEmpty(const SqStack *s)
{
    return s->top == -1;
}

bool Push(SqStack *s, int e)
{
    if(s->top == MaxSize - 1)
    {
        return false;
    }

    s->top++;
    s->data[s->top] = e;
    return true;
}

bool Pop(SqStack *s,int &e)
{
    if(StackEmpty(s))
    {
        return false;
    }

    e = s->data[s->top];
    s->top --;
    return true;
}

bool GetTop(const SqStack *s, int &e)
{
    if(StackEmpty(s))
    {
        return false;
    }

    e = s->data[s->top];
    return true;
}

void DestroyStack(SqStack *&s)
{
    delete s;
    s = nullptr;
}

int main()
{
    SqStack *s = nullptr;
    InitStack(s);

    cout << boolalpha;
    cout << "Empty: " << StackEmpty(s) << endl;

    Push(s,10);
    Push(s,20);
    Push(s,30);

    int value = 0;

    if(GetTop(s,value))
    {
        cout << "Top: " << value << endl;
    }

    if(Pop(s,value))
    {
        cout << "Popped: " << value << endl;
    }

    if(GetTop(s,value))
    {
        cout << "New Top: " << value << endl;
    }

    DestroyStack(s);
    return 0;
}
