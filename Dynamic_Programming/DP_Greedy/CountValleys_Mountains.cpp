#include<bits/stdc++.h>
using namespace std;

int countValleysMountains(int n) {
  
    vector<int> dp(n);
    dp[0]=1;
    dp[1]=1;

    for(int i=2; i<=n; i++) {
        for(int in=i-1, out=0; in>=0; in--, out++){
            dp[i]+=dp[in]*dp[out];
        }
    }

    return dp[n];
}

int main() {

    int n;
    cin>>n;
    cout << countValleysMountains(n) << endl;
    return 0;
}
