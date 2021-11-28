#include <bits/stdc++.h>
using namespace std;

// Iterative DP
int collectGold(int n, int m, vector<vector<int>>& arr, vector<vector<int>>& dp) {
  
  for(int j=dp[0].size()-1; j>=0; j--) {
    for(int i=dp.size()-1; i>=0; i--) {
      if(j==dp[0].size()-1) {
        dp[i][j] = arr[i][j];
      } else if(i==dp.size()-1 && j!=dp[0].size()-1) {
        dp[i][j] = max(dp[i][j+1], dp[i-1][j+1]) + arr[i][j];
      } else if(i==0 && j!=dp[0].size()-1) {
        dp[i][j] = max(dp[i][j+1], dp[i+1][j+1]) + arr[i][j];
      } else {
        dp[i][j] = max(dp[i][j+1], max(dp[i-1][j+1], dp[i+1][j+1])) + arr[i][j];
      }
    }        
  }
  
  int maxGold = 0;
  for(int i=0; i<dp.size(); i++) {
    maxGold = max(maxGold, dp[i][0]);
  }
  
  return maxGold;
}

// TRY : Recursive DP
