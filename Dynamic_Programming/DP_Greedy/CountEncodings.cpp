#include<bits/stdc++.h>
using namespace std;

int countEncoding(string code) {
    int n = code.size();

    // Base cases
    if(n==1 && code[n-1]=='0')
        return 0;
    else if(n>1) 
        if(code[n-1]=='0' && code[n-2]-'0'>2)
            return 0;
    
    vector<int> dp(n);
    dp[0]=1;
    for(int i=1; i<n; i++) {
        
        // Add this char to previous results i.e + 1
        dp[i] = dp[i-1];
        // Check if this char and last char combined is less than 27
        int firstDigit = code[i-1] - '0';
        char secondDigit  = code[i] - '0';
        int num = firstDigit*10 + secondDigit;
        if(num<=26 && firstDigit!=0){
            dp[i]+=1;
        }
    }

    return dp[code.size()-1];
}

int main() {

    string code;
    cin >> code;
    cout << countEncoding(code);
    return 0;
}

// Reference
// A	B	C	D	E	F	G	H	I	J	K	L	M	N	O	P	Q	R	S	T	U	V	W	X	Y	Z
// 1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	20	21	22	23	24	25	26
