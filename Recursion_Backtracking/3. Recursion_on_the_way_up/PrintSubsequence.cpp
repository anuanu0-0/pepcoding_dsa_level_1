#include <iostream>
using namespace std;

void printSS(string ques, string ans){
    
    // Base case
    if(ques.size()==0) {
        cout << ans << endl;
        return;
    }

    // Recursive case
    char ch = ques[0];
    string str = ques.substr(1);
    printSS(str, ans + ch);
    printSS(str, ans);
    
}