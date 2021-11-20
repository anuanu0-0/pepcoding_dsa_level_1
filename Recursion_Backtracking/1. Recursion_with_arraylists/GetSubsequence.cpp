#include <iostream>
#include <vector>
using namespace std;

// Funtion to get subsequences in vector
vector<string> gss(string s){
   
   if(s.size()==0) {
       return {""};
    }

    char firstChar = s[0];
    string subString = s.substr(1);
    vector<string> subseqs = gss(subString);
    vector<string> res;
    for(string word: subseqs) {
        res.push_back(word);
    }

    for(string word: subseqs) {
        res.push_back(firstChar + word);
    }

    return res;
}