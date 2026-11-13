#include <iostream>
using namespace std;

void Hanoi(int n, char X, char Y, char Z)
{
    if(n == 1)
    {
        cout << "Move disk " << n << " from " <<  X << " to " << Z << endl;
    }
    else
    {
        Hanoi(n - 1, X, Z, Y);

        cout << "Move disk " << n << " from " <<  X << " to " << Z << endl;

        Hanoi(n - 1, Y, X, Z);
    }
}

int main()
{
    Hanoi(2, 'X', 'Y', 'Z');
    return 0;
}