#include <iostream>
using namespace std;

void display(int arr[], int idx, int n){
    if(idx>=n)
        return;
    
    cout << arr[idx] << endl;
    display(arr, idx+1, n);
    return;
}