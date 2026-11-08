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
        if(k == -1 || s.data[k] == s.data[j])
        {
            k ++;
            j ++;
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

int main() {
    SqString t{{}, 0};
    StrAssign(t, "aaaab");

    int next[MaxSize]{};
    int nextval[MaxSize]{};

    GetNext(t, next);
    GetNextval(t, next, nextval);

    cout << "next:    ";
    for (int i = 0; i < t.length; i++) {
        cout << next[i] << ' ';
    }
    cout << '\n';

    cout << "nextval: ";
    for (int i = 0; i < t.length; i++) {
        cout << nextval[i] << ' ';
    }
    cout << '\n';

    return 0;
}