#include<bits/stdc++.h>
using namespace std;

int countEncoding(string code) {
    vector<int> dp(code.size()+1);
    dp[0]=1;

    for(int i=1; i<code.size(); i++) {
        int num1 = code[i-1] -'0';
        int num2 = code[i] - '0';
        if(num1==0 && num2==0) {
            dp[i]=0;
        } else if(num1==0 && num2!=0) {
            dp[i]=dp[i-1];
        } else if(num1!=0 && num2==0) {
            if(num1==1 || num1==2){
                dp[i] = i>=2 ? dp[i-2]:1;
            }
            else 
                dp[i]=0;
        }
        else {
            if(num1*10+num2<=26){
                dp[i]=dp[i-1] + (i>=2 ? dp[i-2]:1);
            } 
            else{
                dp[i]=dp[i-1];
            }
        }
    }
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
