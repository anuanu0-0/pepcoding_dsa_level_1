#include<bits/stdc++.h>
using namespace std;
/*
    APPROACH : 1D DP
        Storage : Max Increasing Sum till that point
        Iterate over the previous smaller elements to get largest in that range.
        Keep track of overall max sum and check for conditions when no previous element was smaller.
*/


int getMaxSumIncreasingSubsequences(int n, vector<int> nums) {
    vector<int> dp(n+1);
    int maxSum = INT_MIN;
    for(int i=0; i<n; i++) {

        int prevMax = INT_MIN;
        for(int j=0; j<i; j++) {
            // when num in range
            if(nums[i]>=nums[j]) {
                if(prevMax==INT_MIN)
                    prevMax = dp[j];
                else
                    prevMax = max(prevMax, dp[j]);
            }
        }

        if(prevMax==INT_MIN) 
            dp[i] = nums[i];
        else
            dp[i] = nums[i] + prevMax;

        maxSum = max(maxSum, dp[i]);
    }

    return maxSum;
}

int main() {
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    cout << getMaxSumIncreasingSubsequences(n, nums);

    return 0;
}