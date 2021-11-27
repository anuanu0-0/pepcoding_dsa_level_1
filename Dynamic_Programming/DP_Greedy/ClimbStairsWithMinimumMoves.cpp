#include <iostream>
#include <vector>
#include<limits.h>

using namespace std;

// Iterative DP
int cs(int arr[], int n) {
  
  int minMoves;
  vector<int> dp(n+1, 0);

  for(int i=n-1; i>=0; i--) {
    if(arr[i]>0) {
      minMoves = INT_MAX;
      for(int j=1; j<=arr[i] && i+j < dp.size(); j++) {
        minMoves = min(minMoves, dp[i+j]);
      }

      if(minMoves!=INT_MAX){
        dp[i]=minMoves+1;
      }
    }
    else if(i!=n-1){
      dp[i]=INT_MAX;
    }
  }

  return dp[0];
}

// TRY: Recursive DP
