#include<bits/stdc++.h>
using namespace std;

int getMaxSumNonAdjacentElements(int n, vector<int> nums) {

    int inc = nums[0];
    int exc = 0;

    for(int i=1; i<n; i++) {
        int new_exc = max(inc, exc);
        int new_inc = exc + nums[i];

        exc = new_exc;
        inc = new_inc;
    }

    return max(inc, exc);
}

int main() {
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin>>nums[i];

    cout << getMaxSumNonAdjacentElements(n, nums);
    return 0;
}