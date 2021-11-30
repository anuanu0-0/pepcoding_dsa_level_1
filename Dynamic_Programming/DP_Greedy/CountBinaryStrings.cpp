#include<bits/stdc++.h> 
using namespace std;

int countBinaryStrings(int n) {
    vector<int> dp(n+1, 0);
    dp[1]=2;
    dp[2]=3;

    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << countBinaryStrings(n) << endl;
}