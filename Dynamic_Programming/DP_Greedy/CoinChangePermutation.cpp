#include <iostream>
#include <vector>
using namespace std;

int CCP(vector<int> coins, int amt, vector<int> dp) {

  dp[0]=1;
  for(int i=1; i<dp.size(); i++) {
    for(int j=0; j<coins.size();  j++) {
      if(coins[j]<=i){
        dp[i]+=dp[i-coins[j]];
      }
    }
  }

  return dp[amt];
}