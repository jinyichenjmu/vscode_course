#include <iostream>
#include <vector>
using namespace std;

double avg(int A[], int n)      
{   
    if(n < 1)
    {
        cout << "Error!" << endl;
        exit(0);
    }

    if(n == 1)
    {
        return A[0];
    }

    double curAvg = (avg(A, n - 1) * (n - 1) + A[n - 1]) / (n);

    return curAvg;
}

int main(){
    int n;
    
    if(!(cin >> n) || n < 1)
    {
        return 0;
    }

    vector<int> A;

    for(int i = 0; i < n; i++)
    {   
        int x;
        if(!(cin >> x)) return 0;

        A.push_back(x);
    }

    cout << "average: " << avg(A.data(), n) << endl;
}