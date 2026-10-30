#include <iostream>
using namespace std;

const int MaxSize = 10;

struct SqList
{
    int data[MaxSize];
    int length;
};

bool ListEmpty(const SqList* List)
{
    return List->length == 0;
}

int main()
{
    SqList emptyList{};
    SqList filledList = {{7, 8}, 2};

    cout << boolalpha;
    cout << "Empty list: " << ListEmpty(&emptyList) << endl;
    cout << "Filled list: " << ListEmpty(&filledList) << endl;

    return 0;
}