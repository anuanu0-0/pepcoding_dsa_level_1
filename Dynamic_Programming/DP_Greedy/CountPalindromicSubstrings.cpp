#include<bits/stdc++.h>
using namespace std;

int countPalindromicSubstrings(string str) {
   int n = str.size();
   int counter = 0;
   vector<vector<int>> dp(n, vector<int> (n));
   for(int gap=0; gap<n; gap++) {
       for(int i=0, j=gap; j<n; i++,j++) {
           if(gap==0) {
               dp[i][j] = 1;
               counter++;
           } else if(gap==1) {
               if(str[i]==str[j]) {
                   dp[i][j] = 1;
                   counter++;
               }
               else {
                   dp[i][j] = 0;
               }
           } else {
               if(dp[i+1][j-1]==1 && str[i]==str[j]){
                   dp[i][j]=1;
                   counter++;
               } else {
                   dp[i][j]=0;
               }
           }
       }
   }

   return counter;
}

int main() {

    string str;
    cin >> str;
    cout << countPalindromicSubstrings(str);
    return 0;
}
