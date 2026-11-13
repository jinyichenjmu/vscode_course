#include <iostream>
#include <string>
using namespace std;

const int MaxSize = 100;

struct SqString{
    char data[MaxSize];
    int length;
};

bool AssignStr(SqString &s, const string &text)
{
    if(text.size() > MaxSize)
    {
        return false;
    }

    s.length = static_cast<int>(text.size());

    for(int i = 0; i < s.length; i ++)
    {
        s.data[i] = text[i];
    }
    return true;
}

bool MatchForm(const SqString &s, int i, const SqString &t, int j)
{
    if(j == t.length)
    {
        return true;
    }

    if(t.data[j] == '*')
    {
        if(MatchForm(s, i, t, j + 1))
        {
            return true;
        }

        if(i < s.length && MatchForm(s, i+1, t, j))
        {
            return true;
        }

        return false;
    }
    if(i < s.length && s.data[i] == t.data[j])
    {
        return MatchForm(s, i + 1, t, j + 1);
    }

    return false;
}

int FindMatch(const SqString &s, const SqString &t)
{
    for(int start = 0; start <= s.length; start++)
    {
        if(MatchForm(s, start, t, 0))
        {
            return start;
        }
    }
    return -1;
}

int main()
{
    SqString s{};
    SqString t{};

    if (!AssignStr(s, "xxabXYZcdyy") || !AssignStr(t, "ab*cd"))
    {
        cout << "String is too long.\n";
        return 1;
    }

    cout << "Index: " << FindMatch(s, t) << '\n';

    return 0;
}