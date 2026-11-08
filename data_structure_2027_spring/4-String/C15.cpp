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

void GetNext(const SqString &t, int next[])
{
    if(t.length == 0)
    {
        return;
    }

    int j = 0;
    int k = -1;
    next[0] = -1;

    while(j < t.length)
    {
        if(k == -1 || t.data[j] == t.data[k])
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

void GetNextval(const SqString &t, const int next[], int nextval[])
{
    if(t.length == 0)
    {
        return;
    }

    nextval[0] = -1;

    for(int j = 1; j < t.length; j++)
    {
        int k = next[j];
        if(t.data[j] == t.data[k])
        {
            nextval[j] = nextval[k];
        }
        else
        {
            nextval[j] = k;
        }
    }
}

int MatchCount(const SqString &s, const SqString &t)
{
    if(t.length == 0)
    {
        return 0;
    }

    int next[MaxSize + 1];
    int nextval[MaxSize];
    GetNext(t, next);
    GetNextval(t, next, nextval);

    int count = 0;

    int i = 0;
    int j = 0;

    while(i < s.length)
    {
        if(i != 0)
        {
            j = next[j];
        }

        while(i < s.length && j < t.length)
        {
            if(j == -1 || s.data[i] == t.data[j])
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
            count ++;
        }
    }
    
    return count;
}

int main(){
    char text1[] = "ababa";
    char text2[] = "aba";

    SqString s, t;

    StrAssign(s, text1);
    StrAssign(t, text2);

    cout << "count: " << MatchCount(s, t) << endl;
}