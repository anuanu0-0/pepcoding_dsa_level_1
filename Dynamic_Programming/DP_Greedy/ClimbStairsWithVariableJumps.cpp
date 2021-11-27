#include <iostream>
#include <vector>
using namespace std;

// Iterative DP
int cs_it(int arr[], int n){
    vector<int> dp(n+1, 0);
    dp[n]=1;
    for(int i=n-1; i>=0; i--) {
        for(int j=1; j<=arr[i] && i+j < dp.size(); j++) {
            dp[i]+=dp[i+j];
        }
    }

    return dp[0];
}

// Recursive DP
// Changed function signature
int cs(vector<int> arr, int n, vector<int> dp){
    // Base case
    if(arr.size()==n) {
        return 1;
    }
    if(n>arr.size())
        return 0;

    // Look up
    if(dp[n]!=0)
        return dp[n];
        
    // Recursive case
    for(int i=1; i<=arr[n]; i++) {
        dp[n]+=cs(arr, n+i, dp);
    }
    
    return dp[n];
}