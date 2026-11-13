#include <iostream>
using namespace std;

int fun(int n)
{
    if(n == 1)
    {
        return 1;
    }

    return fun(n - 1) * n;
}

int main()
{
    int result = fun(4);

    cout << "4! = " << result << '\n';

    return 0;
}