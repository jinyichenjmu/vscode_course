#include <iostream>
using namespace std;

int Fib(int n)
{
    if(n == 1 || n == 2)
    {
        return 1;
    }

    return Fib(n - 1) + Fib(n - 2);
}

int main()
{
    int n = 5;
    int result = Fib(n);

    cout << "第 " << n << " 项是 " << result << '\n';

    return 0;
}