#include <iostream>
#include<algorithm>

using namespace std;

int max(int arr[], int idx, int n){
    
    if(idx==n-1)
        return arr[idx];
    int m = max(arr, idx+1, n);
    return max(m, arr[idx]);
    
}
