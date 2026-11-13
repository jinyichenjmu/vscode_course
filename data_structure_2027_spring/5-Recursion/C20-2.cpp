#include <iostream>
using namespace std;

const int MaxSize = 100;

struct SqString{
    char data[MaxSize];
    int length;
};

bool isMatched(const char ch1, const char ch2)
{
    if(ch1 == ch2 || ch1 == '*' || ch2 == '*')
    {
        return true;
    }

    return false;
}

bool AssignStr(SqString &s, const char text[])
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
        if(k == -1 || isMatched(s.data[j], s.data[k]))
        {
            j ++;
            k ++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}

void GetNextval(const SqString &s, const int next[], int nextval[])
{
    if(s.length == 0)
    {
        return;
    }

    nextval[0] = -1;

    for(int i = 1; i < s.length; i ++)
    {
        int k = next[i];

        if(s.data[i] == s.data[k])
        {
            nextval[i] = nextval[k];
        }
        else
        {
            nextval[i] = k;
        }
    }
}

int KMP(const SqString &s, const SqString &t)
{
    int next[MaxSize] = {};
    int nextval[MaxSize] = {};

    GetNext(t, next);
    GetNextval(t, next, nextval);

    int i = 0;
    int j = 0;

    while(i < s.length && j < t.length)
    {
        if(j == -1 || isMatched(s.data[i], t.data[j]))
        {
            i ++;
            j ++;
        }
        else
        {
            j = nextval[j];
        }
    }

    if(j == t.length)
    {
        return i - j;
    }

    return -1;
}

int main(){
    char str[MaxSize] = "aaabaab";
    char text[MaxSize] = "ba*a";

    SqString s = {}, t = {};
    AssignStr(s, str);
    AssignStr(t, text);

    cout << KMP(s, t) << endl;
}