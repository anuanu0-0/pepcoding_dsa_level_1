#include <iostream>
using namespace std;

void display(int arr[], int idx, int n){
    
    if(n<=idx)
        return;

    cout << arr[n-1] << endl;
    display(arr, idx, n-1);
    return;
}