#include <iostream>
using namespace std;

double Min(const double A[], int i)
{
    if(i == 0)
    {
        return A[0];
    }

    double minvalue = Min(A, i - 1);

    if(minvalue > A[i])
    {
        return A[i];
    }

    return minvalue;
}

int main()
{
    double a[] = {9.2, 5.5, 3.8, 7.1, 6.5};

    cout << "Minimum: " << Min(a, 4) << '\n';

    return 0;
}