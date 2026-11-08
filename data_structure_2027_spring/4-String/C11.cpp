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

int main() {
    SqString t{{}, 0};
    StrAssign(t, "aaab");

    int next[MaxSize]{};
    GetNext(t, next);

    cout << "next: ";
    for (int i = 0; i < t.length; i++) {
        cout << next[i] << ' ';
    }
    cout << '\n';

    return 0;
}