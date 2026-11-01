#include <iostream>
using namespace std;

const int MaxSize = 100;

struct SqList{
    int data[MaxSize];
    int length;
};

bool UnionList(const SqList *A, const SqList *B, SqList *C)
{
    if(A->length + B->length > MaxSize)
    {
        return false;
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while(i < A->length && j < B->length)
    {
        if(A->data[i] < B->data[j])
        {
            C->data[k] = A->data[i];   
            i ++;
        }
        else
        {
            C->data[k] = B->data[j];
            j ++;
        }
        k ++;
    }

    while(i < A->length)
    {
        C->data[k] = A->data[i];
        i ++;
        k ++;
    }

    while(j < B->length)
    {
        C->data[k] = B->data[j];
        j++;
        k++;
    }

    C->length = k;
    return true;
}

void PrintList(SqList *L)
{
    for(int i = 0;i<L->length;i++)
    {
        cout << L->data[i] << ' ';
    }
    cout << endl;
}

int main() {
    SqList A{{1, 3, 5}, 3};
    SqList B{{2, 4, 8, 10}, 4};
    SqList C{{}, 0};

    if (UnionList(&A, &B, &C)) {
        cout << "A: ";
        PrintList(&A);

        cout << "B: ";
        PrintList(&B);

        cout << "C: ";
        PrintList(&C);
    } else {
        cout << "Result is too large.\n";
    }

    return 0;
}