#include<bits/stdc++.h>
using namespace std;

// Non DP solution
// TC : 2^n
int countABCSubsequences(string str) {
    int n = str.size();
    regex r("a+b+c+");

    vector<int> res(n+1);
    vector<string> subseq;
    subseq.push_back("");
    int count = 1;
    for(int i=0; i<n; i++) {

      for(int j=0; j<count; j++) {
          char ch = str[i];
          subseq.push_back(subseq[j] + ch);
      }  

      // Update count
      count = subseq.size();

      for(string s: subseq) {
          if(regex_match(s.begin(), s.end(), r)) {
              res[i]++;
          }
      }
    }
    
    return res[n-1];
}

// Greedy-DP
// TC : n
int countABCSubsequences(string str) {
    int a = 0;
    int ab = 0;
    int abc = 0;

    for(int i=0; i<str.size(); i++) {
        char ch = str[i];
        if(ch=='a') {
            a = 2*a+1;
        } else if (ch=='b') {
            ab = 2*ab+a;
        } else if (ch=='c') {
            abc = 2*abc+ab;
        }
    }
    return abc;
}

int main() {
    string str;
    cin >> str;

    cout << countABCSubsequences(str);
    return 0;
}
