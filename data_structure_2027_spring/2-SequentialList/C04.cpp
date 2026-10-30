#include <iostream>
using namespace std;

int main()
{
    int a[] = {1, 3, 1, 5, 4, 2};
    int length = 6;
    int position = 3;

    if(position < 1 || position > length)
    {
        cout << "Cannot delete\n";
        return 1;
    }

    int removed = a[position - 1];

    for(int i = position - 1; i < length - 1; i++)
    {
        a[i] = a[i+1];
    }

    length--;

    cout << "Deleted:" << removed << '\n';
    cout << "List: ";

    for(int i = 0;i<length;i++)
    {
        cout << a[i] << ' ';
    }
    cout << "\n";

    return 0;
}