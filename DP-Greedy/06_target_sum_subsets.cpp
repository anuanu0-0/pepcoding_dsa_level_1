#include <bits/stdc++.h>
using namespace std;

// 2D DP
void targetSumPair(vector<int> &arr, int target) {
    
    vector<vector<bool>> dp (arr.size(), vector<bool> (target+1, false));
    for(int i=0; i<dp.size(); i++) {
        for(int j=0; j<dp[0].size(); j++) {
            if(i==0 && j==0) {
                dp[i][j] = true;
            } else if(i==0 && j!=0) {
                dp[i][j] = false;
                dp[i][arr[i]] = (dp[i][arr[i]]!=true && arr[i] < dp[0].size()) ? true : false;
            } 
            else {
                if(dp[i-1][j])
                    dp[i][j] = true;
                else {
                    int idx = j-arr[i];
                    if(idx>=0) {
                        dp[i][j] = dp[i-1][idx];
                    }
                }
            }
        }
    }

   cout << boolalpha << dp[arr.size()-1][target];
}
int main()
{
    int n, target;
    cin >> n;
    vector<int> vec(n, 0);
    for(int i=0; i<n; i++) cin>>vec[i];
    cin >> target;
    targetSumPair(vec, target);
    return 0;
}