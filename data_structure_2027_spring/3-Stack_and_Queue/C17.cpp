#include <iostream>
using namespace std;

const int Maxsize = 100;

struct SqStack{
    int data[Maxsize];
    int top;
};

void InitStack(SqStack *&s)
{
    s = new SqStack{};
    s->top = -1;
}

bool StackEmpty(SqStack *s)
{
    return s->top == -1;
}

bool Push(SqStack *s, int e)
{
    if(s->top + 1 == Maxsize)
    {
        return false;
    }

    s->data[++s->top] = e;
    return true;
}

bool Pop(SqStack *s, int &e)
{
    if(StackEmpty(s))
    {
        return false;
    }

    e = s->data[s->top--];
    return true;
}

void DestroyStack(SqStack *&s)
{
    delete s;
    s = nullptr;
}

bool DeleteElement(SqStack *&s, int key)
{
    if(StackEmpty(s))
    {
        return false;
    }

    SqStack *s2 = nullptr;
    InitStack(s2);          //辅助栈

    int value;
    while(Pop(s, value))
    {
        if(value != key)
        {
            Push(s2, value);
        }
    }
    
    while(Pop(s2, value))
    {

        Push(s, value);
    }
    DestroyStack(s2);
    return true;
}

int main(){
    SqStack *s = nullptr;
    InitStack(s);
    
    Push(s, 1);
    Push(s, 2);
    Push(s, 3);
    Push(s, 1);
    Push(s, 3);
    Push(s, 3);

    if(!DeleteElement(s, 3))
    {
        cout << "Failed!" << endl;
        DestroyStack(s);
        return 0;
    }
    cout << "After: ";
    int value;
    while(Pop(s, value))
    {
        cout << value << " ";
    }
    cout << endl;
    DestroyStack(s);
}