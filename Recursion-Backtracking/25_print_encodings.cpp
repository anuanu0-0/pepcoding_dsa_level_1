#include <iostream>
#include<string>
using namespace std;

string codes[] = {"", "a", "b", "c", "d", "e" ,"f" ,"g" ,"h",
                     "i", "j", "k", "l", "m" ,"n" ,"o" ,"p" ,
                     "q", "r", "s", "t", "u", "v", "w", "x",
                     "y", "z"};
                     
void printEncoding(string str, string asf){
    if(str.empty()) {
       cout << asf << endl;
       return;
    }

    
    // Dealing with 1 digit 
    int first = str[0]-'0';
    string newStr = str.substr(1);
    
    if(first!=0) {
        printEncoding(newStr, asf + codes[first]);
    }
        
    // Dealing with 2 digit 
    if(str.size()>=2) {
        int second = str[1]-'0';
        int num = first*10 + second;
        newStr = newStr.substr(1);
        if(num>=10 && num<=26) {
            printEncoding(newStr, asf + codes[num]);
        }
    }
}   

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");
    
}