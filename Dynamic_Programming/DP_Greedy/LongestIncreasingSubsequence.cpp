#include<bits/stdc++.h>
using namespace std;

/*
    APPROACH : 1D DP
        Storage : Longest increaasing subsequence at particular point
        Options : Increase the count if increasing, Start a new count if not.
*/
int lis(int n, vector<int> nums) {
    vector<int> dp(n+1);

    int maxCount = 0;
    for(int i=0; i<n; i++) {

        int preMax = INT_MIN;
        for(int j=0; j<i; j++) {
            // Get max prev element
            if(nums[i]>=nums[j]) {    
                if(preMax==INT_MIN)
                    preMax = dp[j];
                else
                    preMax = max(preMax, dp[j]);
            }
        }

        // Increase / Initialize the count
        if(preMax == INT_MIN)
            dp[i] = 1;
        else    
            dp[i] = preMax + 1;

        // Update maxCount
        maxCount = max(maxCount, dp[i]);
    }

    return maxCount;
}


int main() {
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    cout << lis(n, nums);

    return 0;
}