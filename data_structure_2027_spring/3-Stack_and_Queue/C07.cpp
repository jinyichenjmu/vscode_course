#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const int MaxSize = 100;

struct NumStack{
    int data[MaxSize];
    int top;
};

bool Push(NumStack *s, int e)
{
    if(s->top == MaxSize - 1)
    {
        return false;
    }

    s->data[++s->top] = e;
    return true;
}

bool Pop(NumStack *s, int &e)
{
    if(s->top == - 1)
    {
        return false;
    }

    e = s->data[s->top--];
    return true;
}

bool EvaluatePostfix(const string &postfix, int &result)
{
    NumStack s = {{},-1};

    istringstream input(postfix);
    string token;

    while(input >> token)
    {
        if(token == "+" || token == "-" || token == "*" || token == "/")
        {
            int right;
            int left;

            if(!Pop(&s,right) || !Pop(&s,left))
            {
                return false;
            }

            int value = 0;

            if(token == "+")
            {
                value = left + right;
            }
            else if(token == "-")
            {
                value = left - right;
            }
            else if(token == "*")
            {
                value = left * right;
            }
            else
            {
                if(right == 0)
                {
                    return false;
                }
                value = left / right;
            }

            if(!Push(&s,value))
            {
                return false;
            }
        }
        else
        {
            int value = stoi(token);

            if(!Push(&s,value))
            {
                return false;
            }
        }
    }
    if(s.top != 0)
    {
        return false;
    }

    result = s.data[s.top];
    return true;
}

int main() {
    string postfix = "1 2 4 12 + * +";
    int result = 0;

    if (EvaluatePostfix(postfix, result)) {
        cout << "Result: " << result << '\n';
    } else {
        cout << "Cannot evaluate expression.\n";
    }

    return 0;
}