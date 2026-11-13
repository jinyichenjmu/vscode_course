#include <iostream>
using namespace std;

const int MaxSize = 100;

struct SqList{
    int data[MaxSize];
    int length;
};

int Max(const SqList &L, int i, int j)
{
    if(i == j)
    {
        return L.data[i];
    }

    int mid = (i + j) / 2;

    int leftmax = Max(L, i, mid);
    int rightmax = Max(L, mid + 1, j);

    if(leftmax > rightmax)
    {
        return leftmax;
    }
    return rightmax;
}

int main()
{
    SqList L{{4, 9, 2, 7}, 4};

    cout << "Maximum: " << Max(L, 0, L.length - 1) << '\n';

    return 0;
}