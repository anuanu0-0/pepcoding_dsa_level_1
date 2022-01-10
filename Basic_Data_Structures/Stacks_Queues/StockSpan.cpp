#include <bits/stdc++.h>
using namespace std;

void display(vector<int>a){
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<endl;
}

vector<int> solve(vector<int>arr)
{
    stack<int> s;
    vector<int> res;

    s.push(0);
    res.push_back(1);

    for(int i=1; i<arr.size(); i++) {
        if(!s.empty() && arr[i] < arr[s.top()]) {
            s.push(i);
            res.push_back(1);
        } else {
            while(!s.empty() && arr[i] > arr[s.top()]) {
                s.pop();
            }
            
            if(s.empty()) {
                res.push_back(i+1);
            } else {
                res.push_back(i-s.top());
            }

            s.push(i);
        }
    }

    return res;
}   

int main(int argc, char **argv)
{  
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int>span(n,0);
    span=solve(arr);
    display(span);
   return 0;
}