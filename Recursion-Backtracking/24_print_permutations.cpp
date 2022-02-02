#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
    // Base case
    if(str.empty()) {
        cout << asf << endl;
        return;
    }

    // Recursive case
    for(int i=0; i<str.size(); i++) {
        string prefix = "", suffix = "";
        char ch = str[i];
         if(i!=0) prefix = str.substr(0, i);
        if(i+1<str.size()) suffix = str.substr(i+1);
        printPermutations(prefix+suffix, asf + ch);
    }
}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}