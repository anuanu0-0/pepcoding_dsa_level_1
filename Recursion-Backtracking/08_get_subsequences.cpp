#include <iostream>
#include <vector>
using namespace std;
/**
 * @brief Return subsequences of given string.
 *  Logic : Every character has 2 possibilities : to be part of subsequence or not.
 *          Find subsequences of a substring and append / donot append the additional character.
 * @param s String provided for generating subsequences
 * @return vector<string> Subsequences of the string provided
 */
vector<string> gss(string s){
   if(s.empty()) {
       return {""};
   }    
    
    char firstChar = s[0];
    string subString = s.substr(1);
    vector<string> subseqs = gss(subString);
    vector<string> result;
    for(string i:subseqs) {
        result.push_back(i);
    }

    for(string i:subseqs) {
        result.push_back(firstChar + i);
    }

    return result;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << "[";
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << "]";
}