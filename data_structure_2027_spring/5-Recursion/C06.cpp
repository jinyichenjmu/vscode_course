#include <iostream>
using namespace std;

int Fib2(int n)
{
    int a = 1;
    int b = 1;
    int s = 1;

    if(n == 1 || n == 2)
    {
        return 1;
    }

    for(int i = 3; i <= n; i++)
    {
        s = a + b;
        a = b;
        b = s;
    }
    return s;
}

int main()
{
    int n = 5;
    cout << "Fib(" << n << ") = " << Fib2(n) << '\n';

    return 0;
}