#include <iostream>
using namespace std;

int countDigits(int n)
{
    if(n == 0)
    {
        return 0;
    }

    return countDigits(n / 10) + 1;
}

int main(){
    int x;
    cin >> x;

    cout << "count: " << countDigits(x) << endl;
}