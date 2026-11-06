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

    for(int i = 0;i<n;i++)
    {
        s.data[i] = text[i];
    }

    s.length = n;
    return true;
}

void StrCopy(SqString &s, const SqString &t)
{
    for(int i = 0; i < t.length; i++)
    {
        s.data[i] = t.data[i];
    }

    s.length = t.length;
}

bool StrEqual(const SqString &s, const SqString &t)
{
    if(s.length != t.length)
    {
        return false;
    }

    for(int i = 0; i < s.length; i++)
    {
        if(s.data[i] != t.data[i])
        {
            return false;
        }
    }

    return true;
}

int StrLength(const SqString &s)
{
    return s.length;
}

void DispStr(const SqString &s)
{
    for(int i = 0; i < s.length; i++)
    {
        cout << s.data[i];
    }
    cout << endl;
}

int main() {
    SqString a{{}, 0};
    SqString b{{}, 0};

    if (!StrAssign(a, "data")) {
        cout << "String is too long.\n";
        return 1;
    }

    StrCopy(b, a);

    cout << "a: ";
    DispStr(a);

    cout << "b: ";
    DispStr(b);

    cout << "Length: " << StrLength(a) << '\n';
    cout << boolalpha << "Equal: " << StrEqual(a, b) << '\n';

    return 0;
}