#include <iostream>
using namespace std;

int main(){
    int a[] = {1, 3, 1, 4, 2};
    int length = 5;
    int target = 1;

    int position = 0;

    for(int i = 0;i<length; ++i){
        if(a[i] == target){
            position = i + 1;
            break;
        }
    }
    cout << "Position: " << position << endl;
}