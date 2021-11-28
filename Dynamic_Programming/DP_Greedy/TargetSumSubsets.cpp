#include <bits/stdc++.h>
using namespace std;

// Iterative DP
void targetSumPair(vector<int> &arr, int target) {
    
    vector<vector<bool>> dp(arr.size()+1, vector<bool> (target+1, false));    
    for(int i=0; i<dp.size(); i++) {
        for(int j=0; j<dp[0].size(); j++) {
            if(i==0 && j==0) {
                dp[i][j]=true;
            } else if(i==0) {
                dp[i][j]=false;
            } else if(j==0) {
                dp[i][j]=true;
            } else {
                if(dp[i-1][j]){
                    dp[i][j]=true;
                } else {
                    int val = arr[i-1];
                    if(val<=j)  {
                        dp[i][j] = dp[i-1][j-val];
                    }
                }
            }
        }
    }
    
    cout << boolalpha << dp[arr.size()][target];
}

// TRY : Recursive DP