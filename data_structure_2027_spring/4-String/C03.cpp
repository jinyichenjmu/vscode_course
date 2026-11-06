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

bool InsStr(const SqString &s, int i, const SqString &t, SqString &result)
{
    if(i < 1 || i > s.length + 1 || s.length + t.length > MaxSize)
    {
        return false;
    }

    SqString temp = {{}, 0};
    int k = 0;

    for(int j = 0; j < i - 1; j++)
    {
        temp.data[k++] = s.data[j];
    }

    for(int j = 0; j < t.length; j++)
    {
        temp.data[k++] = t.data[j];
    }

    for(int j = i - 1; j < s.length; j++)
    {
        temp.data[k++] = s.data[j];
    }
    
    temp.length = k;
    result = temp;
    return true;
}

bool DelStr(const SqString &s, int i, int count, SqString &result)
{
    if(i < 1 || i > s.length || count < 0 || count > s.length - (i - 1))
    {
        return false;
    }

    SqString temp{{}, 0};
    int k = 0;

    for(int j = 0; j < i - 1; j++)
    {
        temp.data[k++] = s.data[j];
    }

    for(int j = i - 1 + count; j < s.length; j++)
    {
        temp.data[k++] = s.data[j];
    }

    temp.length = k;
    result = temp;
    return true;
}

bool RepStr(const SqString &s, int i, int count, const SqString &t, SqString &result)
{
    if(i < 1 || i > s.length || count < 0 || count > s.length - (i - 1) || s.length - count + t.length > MaxSize)
    {
        return false;
    }

    SqString temp = {{}, 0};
    int k = 0;

    for(int j = 0; j < i - 1; j++)
    {
        temp.data[k++] = s.data[j];
    }

    for(int j = 0; j < t.length; j++)
    {
        temp.data[k++] = t.data[j];
    }

    for(int j = i - 1 + count; j < s.length; j++)
    {
        temp.data[k++] = s.data[j];
    }

    temp.length = k;
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
    SqString t{{}, 0};
    SqString result{{}, 0};

    StrAssign(a, "abcd");
    StrAssign(t, "XY");

    if (InsStr(a, 3, t, result)) {
        cout << "Insert: ";
        DispStr(result);
    }

    if (DelStr(a, 3, 2, result)) {
        cout << "Delete: ";
        DispStr(result);
    }

    if (RepStr(a, 2, 2, t, result)) {
        cout << "Replace: ";
        DispStr(result);
    }

    return 0;
}