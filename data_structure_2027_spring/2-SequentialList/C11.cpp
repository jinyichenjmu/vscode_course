#include "SqList.h"

void delnode1(SqList *&L,int x)
{
    int k = 0;
    for(int i = 0;i < L->length;i++)
    {
        if(L->data[i] != x)
        {
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
}

void delnode2(SqList *&L,int x)
{
    int k = 0;
    for(int i = 0;i < L->length;i++)
    {
        if(L->data[i] == x)
        {
            k++;
        }
        else
        {
            L->data[i-k] = L->data[i];
        }
    }

    L->length = L->length - k;
}

int main() {
    int a[] = {1, 3, 1, 4, 2};

    SqList* L1 = nullptr;
    SqList* L2 = nullptr;

    // 创建两份相同的表，分别测试两种解法。
    CreateList(L1, a, 5);
    CreateList(L2, a, 5);

    delnode1(L1, 1);
    cout << "Method 1: ";
    DispList(L1);

    delnode2(L2, 1);
    cout << "Method 2: ";
    DispList(L2);

    DestroyList(L1);
    L1 = nullptr;

    DestroyList(L2);
    L2 = nullptr;

    return 0;
}