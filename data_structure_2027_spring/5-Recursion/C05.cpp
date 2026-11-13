#include <iostream>
using namespace std;

int S(int n)
{
    return (n <= 0) ? 0 : S(n - 1) + n;
}

int main()
{
    cout << "Sum: " << S(1) << '\n';
    return 0;
}