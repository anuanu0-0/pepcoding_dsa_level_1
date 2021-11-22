#include <iostream>
#include<string>
using namespace std;

string codes[] = {"", "a", "b", "c", "d", "e" ,"f" ,"g" ,"h",
                     "i", "j", "k", "l", "m" ,"n" ,"o" ,"p" ,
                     "q", "r", "s", "t", "u", "v", "w", "x",
                     "y", "z"};


void printEncoding(string str, string asf){
    
    // Base case
    if(str=="") {
        cout << asf << endl;
        return;
    }
    if(str[0]=='0') {
        return;
    }

    int firstChar = str[0]-'0';
    printEncoding(str.substr(1), asf + codes[firstChar]);
    if(str.size()>1) {
        int secondChar = str[1]-'0';
        int num = firstChar*10 + secondChar;
        if(num <=26) {
            printEncoding(str.substr(2), asf + codes[num]);
        }
    }
}