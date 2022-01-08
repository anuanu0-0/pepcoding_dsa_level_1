#include <bits/stdc++.h>
using namespace std;
void display(vector<int>a){
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
}
vector<int> solve(vector<int>arr)
{
    int n = arr.size();
    vector<int> res;
    stack<int> s;

    for(int i=n-1; i>=0; i--) {
        if(i==n-1) {
            s.push(arr[i]);
            res.push_back(-1);
        }
        else {
            while(!s.empty() && s.top() < arr[i]) {
                s.pop();
            }

            if(s.empty()) {
                res.push_back(-1);
            } else {
                res.push_back(s.top());
            }

            s.push(arr[i]);
        }
    }

    reverse(res.begin(), res.end());
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
    vector<int>nge(n,0);
    nge=solve(arr);
    display(nge);
   return 0;
}