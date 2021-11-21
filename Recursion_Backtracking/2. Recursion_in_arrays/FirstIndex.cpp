#include<iostream>
using namespace std;

int firstIndex(int arr[], int idx, int x, int n){
    if(idx==n)
        return -1;

    if(arr[idx]==x)
        return idx;
    else {
        int firstIdx = firstIndex(arr, idx+1, x, n);
        return firstIdx;
    }

}