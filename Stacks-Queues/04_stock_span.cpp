#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>arr) {
    stack<int> s;
    vector<int> res;

    for(int i=0; i<arr.size(); i++) {
        if(i==0) {
            res.push_back(1);
        } else {
            while(!s.empty() && arr[i] > arr[s.top()]) s.pop();
            s.empty()? res.push_back(i+1) : res.push_back(i-s.top());
        }
        s.push(i);
    }

    return res;
}   

int main(int argc, char **argv) {  
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    vector<int>span = solve(arr);
    for(int i:span) 
        cout << i << " ";

   return 0;
}
