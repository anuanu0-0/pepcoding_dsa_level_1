#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

void slidingWindowMax(int n, vector<int> arr, int k) {
    stack<int> s;
    vector<int> nextGreater(n);

    for(int i=n-1; i>=0; i--) {
        while(!s.empty() && arr[i] >= arr[s.top()]) {
            s.pop();
        }

        if(s.empty()) {
            nextGreater[i]=n;
        } else {
            nextGreater[i]=s.top();
        }

        s.push(i);
    }

    
    for(int i=0,j=0; i<=n-k; i++) {
        if(j<i) j=i;
        while(nextGreater[j] < i+k) {
            j = nextGreater[j];
        }
        
        cout << arr[j] << endl;
    }
}


int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int k;
	cin >> k;

    slidingWindowMax(n, arr, k);
	return 0;
}