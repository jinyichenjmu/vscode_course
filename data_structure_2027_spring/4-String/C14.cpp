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
        n++;
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

    while(j < t.length - 1)
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

        if(t.data[k] == t.data[j])
        {
            nextval[j] = nextval[k];
        }
        else
        {
            nextval[j] = k;
        }
    }
}

int Match(const SqString &s, const SqString &t, const int jump[], int &comparisons)
{
    comparisons = 0;

    if(t.length == 0)
    {
        return 0;
    }

    int i = 0;      //目标串下标
    int j = 0;      //模式串下标

    while(i < s.length && j < t.length)
    {
        if(j == -1)
        {
            i ++;
            j ++;
        }
        else
        {
            comparisons ++;
            if(s.data[i] == t.data[j])
            {
                i ++;
                j ++;
            }
            else
            {
                j = jump[j];
            }
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

    StrAssign(s, "aaabaaaab");
    StrAssign(t, "aaaab");

    int next[MaxSize]{};
    int nextval[MaxSize]{};

    GetNext(t, next);
    GetNextval(t, next, nextval);

    int normalComparisons = 0;
    int improvedComparisons = 0;

    int normalIndex = Match(s, t, next, normalComparisons);
    int improvedIndex = Match(s, t, nextval, improvedComparisons);

    cout << "KMP index: " << normalIndex
         << ", comparisons: " << normalComparisons << '\n';

    cout << "Improved index: " << improvedIndex
         << ", comparisons: " << improvedComparisons << '\n';

    return 0;
}