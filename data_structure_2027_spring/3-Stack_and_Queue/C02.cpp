#include <iostream>
#include <string>
using namespace std;

const int MaxSize = 100;

struct SqStack{
    char data[MaxSize];
    int top;
};

void InitStack(SqStack *&s)
{
    s = new SqStack{};
    s->top = -1;
}

bool Push(SqStack *s, char e)
{
    if(s->top == MaxSize - 1)
    {
        return false;
    }

    s->top ++;
    s->data[s->top] = e;
    return true;
}

bool Pop(SqStack *s, char &e)
{
    if(s->top == -1)
    {
        return false;
    }

    e = s->data[s->top];
    s->top --;
    return true;
}

void DestroyStack(SqStack *&s)
{
    delete s;
    s = nullptr;
}

bool Symmetry(const string &text, bool &result)
{
    SqStack *s = nullptr;
    InitStack(s);
    for(char ch : text)
    {
        if(!Push(s,ch))
        {
            DestroyStack(s);
            return false;
        }
    }
    result = true;

    for(char ch : text)
    {
        char e;
        Pop(s,e);

        if(ch != e)
        {
            result = false;
            break;
        }
    }

    DestroyStack(s);
    return true;
}

int main() {
    string text = "abba";
    bool result = false;

    if (Symmetry(text, result)) {
        cout << boolalpha << "Symmetric: " << result << '\n';
    } else {
        cout << "Text is too long for the stack.\n";
    }

    return 0;
}