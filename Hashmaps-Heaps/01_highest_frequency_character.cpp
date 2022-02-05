#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string str;
  cin >> str;

  unordered_map<char, int> um;
  for(char ch:str) {
    um[ch]++;
  }

  int maxCount = 0;
  char ans;
  for(auto i:um) {
    if(i.second > maxCount) {
      maxCount = i.second;
      ans = i.first;
    }
  }

  cout << ans << endl;

}