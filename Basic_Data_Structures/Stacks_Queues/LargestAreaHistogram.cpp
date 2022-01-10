#include <bits/stdc++.h>
using namespace std;

int largestAreaHistogram(vector<int> arr) {

    int n = arr.size();
    stack<int> s;

    // Left boundary
    vector<int> lb;
    lb.push_back(-1);
    s.push(arr[0]);

    for(int i=1; i<n; i++) {
        while(!s.empty() && arr[i] <= arr[s.top()]) {
            s.pop();
        }

        if(s.empty()) lb.push_back(-1);
        else lb.push_back(s.top());

        s.push(i);
    }

    // Right boundary
    s=stack<int>();
    vector<int> rb;
    rb.push_back(n);
    s.push(n-1);

    for(int i=n-2; i>=0; i--) {
        while(!s.empty() && arr[i] <= arr[s.top()]) {
            s.pop();
        }

        if(s.empty()) rb.push_back(n);
        else rb.push_back(s.top());

        s.push(i);
    }

    // Calculating max area
    int maxArea = 0;
    
    reverse(rb.begin(), rb.end());

    for(int i=0; i<n; i++) {
        int width = rb[i]-lb[i]-1;
        maxArea = max(maxArea, arr[i]*width);
    }

    return maxArea;
}

int main(int argc, char **argv)
{  
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    cout << largestAreaHistogram(arr) << endl;
   return 0;
}