#include <iostream>
using namespace std;

void printSS(string ques, string ans){
    // Base case
   if(ques.empty()) {
       cout << ans << endl;
       return;
   }

    // Recursive case
    char ch = ques[0];
    string newStr = ques.substr(1);
    printSS(newStr, ans+ch);
    printSS(newStr, ans);
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}