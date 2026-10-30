#include <iostream>
#include <cstdlib>
using namespace std;

const int MaxSize = 10;

typedef struct 
{
    int data[MaxSize];
    int length;
} SqList;

void CreateList(SqList *&L, int a[],int n)
{
    int i = 0,k = 0;

    L = new SqList;

    while(i < n)
    {
        L->data[k] = a[i];
        k++;
        i++;
    }

    L->length = k;
}

int ListLength(SqList *L)
{
    return L->length;
}

void InitList(SqList *&L)
{
    L = new SqList;
    L->length = 0;
}

void DestroyList(SqList *&L)
{
    delete L;
}

bool ListEmpty(SqList *L)
{
    return L->length == 0;
}

void DispList(SqList *L)
{
    for(int i = 0;i<L->length;i++)
    {
        cout << L->data[i] << ' ';
    }

    cout << '\n';
}

bool GetElem(SqList *L,int i,int &e)
{
    if(i < 1 || i > L->length)
    {
        return false;
    }

    e = L->data[i-1];

    return true;
}

int LocateElem(SqList *L,int e)
{
    int i = 0;
    while(i < L->length && L->data[i] != e)
    {
        i++;
    }

    if(i >= L->length)
    {
        return 0;
    }
    else
    {
        return i+1;
    }
}

bool ListInsert(SqList *&L,int i , int e)
{
    int j;

    if(i < 1 || i > L->length + 1)
    {
        return false;
    }

    i--;

    for(j = L->length; j > i; j--)
    {
        L->data[j] = L->data[j - 1];
    }

    L->data[i] = e;
    L->length ++;
    return true;
}

bool ListDelete(SqList *&L, int i , int &e)
{
    int j;
    if(i < 1 || i > L->length)
    {
        return false;
    }

    i--;

    e = L->data[i];

    for(j = i; j < L->length-1;j++)
    {
        L->data[j] = L->data[j+1];
    }

    L->length--;
    return true;
}

int main()
{
    SqList *L = nullptr;
    int a[] = {1, 3, 1, 4, 2};
    int e =0;
    
    CreateList(L,a,5);

    cout << "List: ";
    DispList(L);

    cout << "Length: " << ListLength(L) << '\n';
    cout << "Empty: " << boolalpha << ListEmpty(L) << '\n';

    if (GetElem(L,3,e))
    {
        cout << "Element 3: " << e << '\n';
    }

    cout << "First position of 1: " << LocateElem(L, 1) << '\n';

    if(L->length < MaxSize && ListInsert(L,4,5))
    {
        cout << "After insert: ";
        DispList(L);
    }
    
    if(ListDelete(L,3,e))
    {
        cout << "Deleted: " << e << '\n';
        cout << "After delete: ";
        DispList(L);
    }

    DestroyList(L);
    L = nullptr;

    return 0;
}