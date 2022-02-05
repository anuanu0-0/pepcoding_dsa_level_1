#include <bits/stdc++.h>
using namespace std;

bool hasDuplicateBrackets(string str) {

    stack<char> s;
    for(char ch : str) {
        if(ch==')') {
            if(s.top()=='(') return true;
            while(s.top()!='(') s.pop();
            s.pop();
        }
        else s.push(ch);
    }

    return false;
}



int main(int argc, char **argv)
{ 
   string s;
   getline(cin, s);
   cout << boolalpha << hasDuplicateBrackets(s) << endl;
   return 0;
}