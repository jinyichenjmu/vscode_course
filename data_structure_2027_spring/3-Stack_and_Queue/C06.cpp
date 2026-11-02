#include <iostream>
#include <string>
using namespace std;

const int MaxSize = 100;

struct OpStack{
    char data[MaxSize];
    int top;
};

int Priority(char ch)
{
    if(ch == '+' || ch == '-')
    {
        return 1;
    }
    if(ch == '/' || ch == '*')
    {
        return 2;
    }
    return 0;
}

bool ToPostfix(const string &exp, string &result)
{
    OpStack s = {{},-1};
    result.clear();

    for(size_t i = 0;i<exp.size();)
    {
        char ch = exp[i];
        if(ch == ' ')
        {
            i++;
        }
        else if(ch >= '0' && ch <= '9')
        {
            while(i < exp.size() && exp[i] >= '0' && exp[i] <= '9')
            {
                result += exp[i];
                i++;
            }
            result += ' ';
        }
        else if(ch == '(')
        {
            if(s.top == MaxSize - 1)
            {
                return false;
            }

            s.data[++s.top] = ch;
            i++;
        }
        else if(ch == ')')
        {
            while(s.top != -1 && s.data[s.top] != '(')
            {
                result += s.data[s.top--];
                result += ' ';
            }

            s.top --;
            i ++;
        }
        else{
            while(s.top != -1 && s.data[s.top] != '(' && Priority(s.data[s.top]) >= Priority(ch))
            {
                result += s.data[s.top--];
                result += ' ';
            }

            if(s.top == MaxSize - 1)
            {
                return false;
            }

            s.data[++s.top] = ch;
            i++;
        }
    }
    while(s.top != -1)
    {
        result += s.data[s.top--];
        result += ' ';
    }
    return true;
}

int main() {
    string exp = "1+2*(4+12)";
    string postfix;

    if (ToPostfix(exp, postfix)) {
        cout << "Postfix: " << postfix << '\n';
    } else {
        cout << "Operator stack is full.\n";
    }

    return 0;
}