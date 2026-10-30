#include <utility>
#include "SqList.h"

void partition1(SqList *&L)
{
    int i = 0, j = L->length-1;
    int pivot = L->data[0];

    while(i<j)
    {
        while(i < j && L->data[j] > pivot)
        {
            j--;
        }

        while(i < j && L->data[i] <= pivot)
        {
            i++;
        }
        
        if(i < j)
        {
            swap(L->data[i], L->data[j]);
        }
    }
    swap(L->data[0], L->data[i]);
}

void partition2(SqList *&L)
{
    int i = 0, j = L->length - 1;
    int pivot = L->data[0];

    while(i < j)
    {
        while(i < j && L->data[j] > pivot)
        {
            j--;
        }

        L->data[i] = L->data[j];

        while(i < j && L->data[i] <= pivot)
        {
            i++;
        }

        L->data[j] = L->data[i];
    }

    L->data[i] = pivot;
}

int main() {
    int a[] = {3, 8, 2, 7, 1, 5, 3, 4, 6, 0};

    SqList* L1 = nullptr;
    SqList* L2 = nullptr;

    CreateList(L1, a, 10);
    CreateList(L2, a, 10);

    // 空表没有第一个元素，所以调用前先判断。
    if (!ListEmpty(L1)) {
        partition1(L1);
    }

    if (!ListEmpty(L2)) {
        partition2(L2);
    }

    cout << "Method 1: ";
    DispList(L1);

    cout << "Method 2: ";
    DispList(L2);

    DestroyList(L1);
    L1 = nullptr;

    DestroyList(L2);
    L2 = nullptr;

    return 0;
}