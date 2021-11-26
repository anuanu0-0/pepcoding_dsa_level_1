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

