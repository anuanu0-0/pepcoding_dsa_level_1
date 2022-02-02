#include <iostream>
#include <vector>
using namespace std;

// Iterative solution
int cs(int arr[], int n){
    
    int dp[n+1];
    dp[n]=1;

    for(int i=n-1; i>=0; i--) {
        int count = 0;
        for(int j=1; j<=arr[i] && i+j<=n; j++) {
            count += dp[i+j];
        }

        dp[i] = count;
    }

    return dp[0];
}

// Recursive solution
int cs_rec(vector<int> arr, int n, vector<int> dp){
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
        dp[n]+=cs_rec(arr, n+i, dp);
    }
    
    return dp[n];
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<cs(arr,n)<<endl;
}