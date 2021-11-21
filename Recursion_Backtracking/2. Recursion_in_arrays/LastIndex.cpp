#include <iostream>
#include <limits.h>

using namespace std;

int lastIndex(int arr[], int idx, int x, int n){
    
    if(idx==n)
        return -1;

    int lastIdx = lastIndex(arr, idx+1, x, n);
    if(lastIdx!=-1)
        return lastIdx;
    else if(arr[idx]==x)
        return idx;
    else
        return -1;
}
