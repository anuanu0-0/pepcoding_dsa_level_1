#include <bits/stdc++.h>
using namespace std;

bool hasDuplicateBrackets(string str) {
    
    stack<char> s;
    for(int i=0; i<str.size(); i++) {
        char ch = str[i];
        
        if(ch == ')') {
            if(s.top() == '(') return true; 
            else {
                 while(s.top()!='(') {
                    s.pop();
                }
                s.pop();
            }
        } else {
            s.push(ch);
        }
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