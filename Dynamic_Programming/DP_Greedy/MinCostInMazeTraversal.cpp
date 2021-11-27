#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Iterative DP
int minCost(int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp ){
        
   for(int i=dp.size()-1; i>=0; i--) {
    for(int j=dp[0].size()-1; j>=0; j--) {
      if(i==dp.size()-1 && j==dp[0].size()-1){
        dp[i][j]=arr[i][j];
      } else if(i==dp.size()-1) {
        dp[i][j] = dp[i][j+1] + arr[i][j];
      } else if(j==dp[0].size()-1){
        dp[i][j] = dp[i+1][j] + arr[i][j];
      } else {
        dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + arr[i][j];
      }
    }
   }
  
  return dp[0][0];  
}

// TRY : Recursive DP