#include <bits/stdc++.h>
using namespace std;
void display(vector<int>a){
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
}
vector<int> solve(vector<int>arr) {

    int n = arr.size();
    vector<int> res;
    stack<int> s;

    for(int i=n-1; i>=0; i--) {
        int num = arr[i];
        if(i==n-1) {
            res.push_back(-1);
            s.push(num);
        }

        else {
            // Pop smaller elements
            while(!s.empty() && num > s.top()) {
                s.pop();
            }

            s.empty()? res.push_back(-1) : res.push_back(s.top());
            s.push(num);
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


