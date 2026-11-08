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

int BF(const SqString &s, const SqString &t)
{
    int i = 0;      // 当前比较的目标串下标
    int j = 0;      // 当前比较的模式串下标

    while(i < s.length && j < t.length)
    {
        if(s.data[i] == t.data[j])
        {
            i ++;
            j ++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }

    if(j == t.length)
    {
        return i - j;
    }
    return -1;
}

int main() {
    SqString s{{}, 0};
    SqString t{{}, 0};

    StrAssign(s, "aaaaab");
    StrAssign(t, "aaab");

    cout << "Index: " << BF(s, t) << '\n';

    return 0;
}