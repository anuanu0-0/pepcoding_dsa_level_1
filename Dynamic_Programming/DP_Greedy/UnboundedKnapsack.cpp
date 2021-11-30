#include <iostream>
#include <vector>

using namespace std;

void unboundedKnapsack(int n,vector<int> val, vector<int> weight,int cap){
    
    vector<int> dp(cap+1, 0);

    for(int i=1; i<dp.size(); i++) {
        for(int j=0; j<val.size(); j++) {
            if(i>=weight[j]) {
                dp[i] = max(dp[i], val[j]+dp[i-weight[j]]);
            }
        }
    }    

    cout << dp[cap] << endl;
}