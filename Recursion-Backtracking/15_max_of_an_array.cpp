#include <iostream>
#include <limits.h>

using namespace std;

int max(int arr[], int idx, int n){
    if(idx==n) return INT_MIN;

    return max(arr[idx], max(arr, idx+1, n));
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int p = max(arr, 0, n);
    cout << p << endl;
}
