#define Maxsize 10
#include <iostream>
using namespace std;

struct SqList
{
    int data[Maxsize];
    int length;
};

int main(){
    SqList list = {{1, 3, 1, 4, 2}, 5};

    cout << "Length: " << list.length << endl;
    cout << "List: ";

    for(int i = 0;i<list.length;i++)
    {
        cout << list.data[i] << ' ';
    }
    cout << endl;
    return 0;
}