#include <iostream>
using namespace std;

void printPermutations(string str, string asf){

    // Base case
    if(str=="") {
        cout << asf << endl;
        return;
    }

    int n = str.size();
    for(int i=0; i<n; i++) {
        string front = "", end = "";
        char ch = str[i];
        if(i!=0) front = str.substr(0, i);
        if(i+1<n) end = str.substr(i+1);

        printPermutations(front+end, asf + ch);
    }

}