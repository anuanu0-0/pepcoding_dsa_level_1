#include<bits/stdc++.h>
using namespace std;

int countPalindromicSubsequences(string str) {
    int n = str.size();
    vector<vector<int>> dp(n, vector<int> (n));

    for(int gap=0; gap<n; gap++) {
        for(int i=0, j=gap; j<n; i++, j++) {
            if(gap==0) {
                dp[i][j]=1;
            } else if (gap==1) {
                dp[i][j] = str[i]==str[j]?3:2;
            } else {
                if(str[i]==str[j]) {
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1;
                } else {
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
                }
            }
        }
    }

    return dp[0][n-1];
}