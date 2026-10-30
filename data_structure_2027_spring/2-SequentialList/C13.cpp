#include <utility>
#include "SqList.h"

void move1(SqList *&L)
{
    int i = 0;
    int j = L->length - 1;

    while(i < j)
    {
        while(i < j && L->data[j] % 2 == 0)
        {
            j --;
        }
        while(i < j && L->data[i] % 2 != 0)
        {
            i ++;
        }

        if(i<j) swap(L->data[i],L->data[j]);
    }
}

void move2(SqList *&L){
    {
        int i = -1;
        int j;

        for(j = 0;j <= L->length - 1;j++)
        {
            if(L->data[j] % 2 != 0)
            {
                i ++;

                if(i != j) swap(L->data[i],L->data[j]);
            }
        }
    }
}

int main() {
    int a[] = {2, 7, 4, 3, 8, 5};

    SqList* L1 = nullptr;
    SqList* L2 = nullptr;

    CreateList(L1, a, 6);
    CreateList(L2, a, 6);

    move1(L1);
    cout << "Method 1: ";
    DispList(L1);

    move2(L2);
    cout << "Method 2: ";
    DispList(L2);

    DestroyList(L1);
    L1 = nullptr;

    DestroyList(L2);
    L2 = nullptr;

    return 0;
}