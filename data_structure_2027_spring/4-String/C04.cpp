#include <iostream>
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

int StrCompare(const SqString &s, const SqString &t)
{
    int commonLength = s.length;

    if(s.length > t.length)
    {
        commonLength = t.length;
    }

    for(int i = 0; i < commonLength; i++)
    {
        if(s.data[i] < t.data[i])
        {
            return -1;
        }

        if(s.data[i] > t.data[i])
        {
            return 1;
        }
    }
    if(s.length > t.length)
    {
        return 1;
    }
    
    if(s.length < t.length)
    {
        return -1;
    }

    return 0;
}

int main() {
    SqString a{{}, 0};
    SqString b{{}, 0};

    StrAssign(a, "apple");
    StrAssign(b, "apply");

    int result = StrCompare(a, b);
    cout << "Compare: " << result << '\n';

    return 0;
}