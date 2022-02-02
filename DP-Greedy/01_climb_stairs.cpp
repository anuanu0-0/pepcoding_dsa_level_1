#include <iostream>
#include <vector>
using namespace std;

// Iterative solution
int cs_it(int n){
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}

// Recursive solution
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

// Iterative Optimized
int cs_itOptimized(int n) {

    int a = 0, b = 1, c = 1;  
    int res = 0;
    for(int i=2; i<=n; i++) {
        res = a+b+c;
        a = b;
        b = c;
        c = res;
    }

    return res;
}

int main(){
    int n;
    cin>>n;
    cout<<cs_it(n)<<endl;
}