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

bool Concat(const SqString &s, const SqString &t, SqString &result)
{
    if(s.length + t.length > MaxSize)
    {
        return false;
    }

    SqString temp{{}, 0};

    for(int i = 0; i < s.length; i++)
    {
        temp.data[i] = s.data[i];
    }

    for(int i = 0; i < t.length; i++)
    {
        temp.data[s.length + i] = t.data[i];
    }

    temp.length = s.length + t.length;
    result = temp;
    return true;
}

bool SubStr(const SqString &s, int i, int count, SqString &result)
{
    if(i < 1 || i > s.length || count < 0 || count > s.length - (i - 1))
    {
        return false;
    }

    SqString temp{{}, 0};

    for(int k = 0; k < count ; k++)
    {
        temp.data[k] = s.data[i - 1 + k];
    }

    temp.length = count;
    result = temp;
    return true;
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
    SqString joined{{}, 0};
    SqString part{{}, 0};

    StrAssign(a, "data");
    StrAssign(b, "base");

    if (Concat(a, b, joined)) {
        cout << "Joined: ";
        DispStr(joined);
    }

    // 从第 3 个字符开始，取 4 个字符。
    if (SubStr(joined, 3, 4, part)) {
        cout << "Substring: ";
        DispStr(part);
    }

    return 0;
}