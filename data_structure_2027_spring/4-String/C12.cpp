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

void GetNext(const SqString &s, int next[])
{
    if(s.length == 0)
    {
        return;
    }

    int j = 0;
    int k = -1;
    next[0] = -1;

    while(j < s.length - 1)
    {
        if(k == -1 || s.data[j] == s.data[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}

int KMP(const SqString &s, const SqString &t)
{
    if(t.length == 0)
    {
        return 0;
    }

    int next[MaxSize];
    GetNext(t, next);

    int i = 0;      // 目标串下标
    int j = 0;      // 模式串下标

    while(i < s.length && j < t.length)
    {
        if(j == -1 || s.data[i] == t.data[j])          // 没有可继续比较的模式位置。
        {
            i ++;
            j ++;
        }
        else
        {
            j = next[j];
        }
    }

    if(j == t.length)
    {
        return i - j;
    }
    return -1;
}

int Match(const SqString &s, const SqString &t, const int jump[], int &compraisons)
{
    if(t.length == 0)
    {
        return 0;
    }

    int i = 0;      //目标串下标
    int j = 0;      //模式串下标

    while(i < s.length && j < t.length)
    {
        if(j == -1 || s.data[i] == t.data[j])
        {
            i ++;
            j ++;
        }
        else
        {
            j = jump[j];
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

    cout << "Index: " << KMP(s, t) << '\n';

    return 0;
}