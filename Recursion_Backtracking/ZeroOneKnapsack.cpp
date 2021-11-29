#include <iostream>
#include <vector>
#define endl '\n';
using namespace std;

void zeroOneKnapsack(int n,vector<int> val, vector<int> weight,int cap){
 
  vector<vector<int>> dp(val.size()+1, vector<int> (cap+1, 0));
  for(int i=1; i<dp.size(); i++) {
    for(int j=1; j<dp[0].size(); j++) {
      
      int remCap = j-weight[i-1];
      if(remCap>=0) {
        dp[i][j]=max(dp[i-1][remCap]+val[i-1], dp[i-1][j]);
      } 
      else {
        dp[i][j] = dp[i-1][j];
      }
    }  
  }

  cout << dp[val.size()][cap] << endl;
}