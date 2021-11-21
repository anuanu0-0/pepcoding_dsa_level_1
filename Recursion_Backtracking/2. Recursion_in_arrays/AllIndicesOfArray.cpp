#include <iostream>
#include <vector>
using namespace std;

vector<int> allIndex(vector<int>& arr, int idx, int data, int count) {
    // Base case
    if(idx==arr.size()){
        vector<int> base(count);
        return base;
    }

    // Recursive case
    if(arr[idx]==data){
        count+=1;
    }
    vector<int> res = allIndex(arr, idx+1, data, count);

    if(arr[idx]==data){
        
        res[--count] = idx;
    }
    return res;

}