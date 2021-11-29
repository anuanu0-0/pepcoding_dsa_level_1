#include <iostream>
#include <vector>
using namespace std;

int coinchangecombination(vector<int> coins, int amt, vector<int> dp) {
 
    dp[0]=1;
    for(int i=0; i<coins.size(); i++) {
        for(int j=coins[i]; j<dp.size(); j++) {
            dp[j]+=dp[j-coins[i]];
        }
    }
    return dp[amt];

}
