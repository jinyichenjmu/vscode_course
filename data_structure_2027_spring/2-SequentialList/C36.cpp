#include <iostream>
using namespace std;

int MiddleValue(const int A[], const int B[], int n)
{
    int i = 0;
    int j = 0;
    int value = 0;

    for(int count = 1;count <= n; count++)
    {
        if(i == n || (j < n && A[i] > B[j]))
        {
            value = B[j];
            j ++;
        }
        else
        {
            value = A[i];
            i ++;
        }
    }
    return value;
}


int main() {
    int A[] = {11, 13, 15, 17, 19};
    int B[] = {2, 4, 6, 8, 20};

    cout << "Middle: " << MiddleValue(A, B, 5) << '\n';
    
    return 0;
}