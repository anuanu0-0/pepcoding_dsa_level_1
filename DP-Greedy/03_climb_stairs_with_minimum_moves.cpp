#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Iterative solution
int cs(int arr[], int n, vector<int>& dp) {
    dp[n]=0;

    for(int i=n-1; i>=0; i--) {
        int minPath = INT_MAX;
        for(int j=1; j<=arr[i] && i+j<dp.size(); j++) {
            minPath = min(minPath, dp[i+j]);
        }

        dp[i] = minPath!=INT_MAX ? minPath+1 : INT_MAX;
    }

    return dp[0];
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }

  vector<int> dp(n + 1, 0);

  cout << cs(arr, n, dp) << endl;
}