#include <iostream>
#include <cstdio>
using namespace std;

const int MaxSize = 100;

struct SqString{
    char data[MaxSize];
    int length;
};

bool StrAssign(SqString &s, const char text[])
{
    int n = 0;

    while(n < MaxSize && text[n] != '\0')
    {
        n ++;
    }

    if(n == MaxSize && text[n] != '\0')
    {
        return false;
    }

    for(int i = 0; i < n; i++)
    {
        s.data[i] = text[i];
    }
    s.length = n;

    return true;
}

bool Append(SqString &s, char ch)
{
    if(s.length == MaxSize)
    {
        return false;
    }

    s.data[s.length++] = ch;

    return true;
}

void backward(const SqString &str, int i, SqString &result)
{
    if(i == 0)
    {
        return;
    }
    Append(result, str.data[i - 1]);

    backward(str, i - 1, result);
}

int main(){
    char str[MaxSize] = "Hello!";

    SqString s = {};
    StrAssign(s, str);

    SqString result = {};

    backward(s, s.length, result);

    for(int i = 0; i < result.length; i++)
    {
        cout << result.data[i];
    }
    cout << endl;
}