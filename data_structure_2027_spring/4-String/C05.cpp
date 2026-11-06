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

void LongestString(const SqString &s, int &index, int &maxlen)
{
    index = 0;
    maxlen = 0;

    int i = 0;

    while(i < s.length)
    {
        int start = i;

        while(i < s.length && s.data[i] == s.data[start])
        {
            i ++;
        }

        int length = i - start;

        if(length > maxlen)
        {
            index = start;
            maxlen = length;
        }
    }
}

int main() {
    SqString s{{}, 0};
    StrAssign(s, "aaabbccccdd");

    int index;
    int maxlen;
    LongestString(s, index, maxlen);

    cout << "Start index: " << index << '\n';
    cout << "Length: " << maxlen << '\n';

    cout << "Segment: ";
    for (int i = 0; i < maxlen; i++) {
        cout << s.data[index + i];
    }
    cout << '\n';

    return 0;
}