#include <iostream>
using namespace std;

const int MaxSize = 10;

struct SqList
{
    int data[MaxSize];
    int length;
};

void InitList(SqList &list)
{
    list.length = 0;
}

int main()
{
    SqList list{};
    InitList(list);

    cout << "Length: " << list.length << endl;

    if(list.length == 0)
    {
        cout << "The list is empty" << endl;
    }

    return 0;
}