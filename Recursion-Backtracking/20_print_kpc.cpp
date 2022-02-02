#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf){

    if(ques.empty()) {
        cout << asf << endl;
        return;
    }

    int key = (int)(ques[0]-'0');
    string str = ques.substr(1);
    for(char ch : codes[key]) {
        printKPC(str, asf + ch);
    }
}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}