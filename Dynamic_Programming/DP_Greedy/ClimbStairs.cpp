#include <iostream>
#include <vector>

using namespace std;

// Iterative DP
int cs_it(int n){
    // write your code here
    vector<int> dp(n+1, 0);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n; i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }

    return dp[n];
}

// Recursive DP
int cs_rec(int n, vector<int> dp){
    // Base case
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    if(dp[n]!=0)
        return dp[n];

    dp[n] = cs_rec(n-1, dp)+cs_rec(n-2, dp)+cs_rec(n-3, dp);
    return dp[n];
}