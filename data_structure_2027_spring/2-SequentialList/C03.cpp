#include <iostream>
using namespace std;

int main(){
    const int capacity = 10;
    int a[capacity] = {1, 3, 1, 4, 2};

    int length = 5;
    int position = 4;
    int value = 5;
    if(length >= capacity || position < 1 || position > length + 1){
        cout << "Cannot insert\n";
        return 1;
    }

    for(int i = length;i >= position;i--){
        a[i] = a[i - 1];
    }

    a[position - 1] = value;
    length ++;

    for (int i = 0;i<length;i++){
        cout << a[i] << ' ';
    }
    cout << '\n';

    return 0;
}