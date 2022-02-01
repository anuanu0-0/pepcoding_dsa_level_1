#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;


string getMapping(char ch) {
    unordered_map<int, string> um;
    um.insert({ 0, ".;" });
    um.insert({ 1, "abc" });
    um.insert({ 2, "def" });
    um.insert({ 3, "ghi" });
    um.insert({ 4, "jkl" });
    um.insert({ 5, "mno" });
    um.insert({ 6, "pqrs" });
    um.insert({ 7, "tu" });
    um.insert({ 8, "vwx" });
    um.insert({ 9, "yz" });

    return um[ch-'0'];
}


vector<string> getKPC(string s){
    if(s.empty())
        return {""};
    
    string restString = s.substr(1);
    vector<string> subkpc = getKPC(restString);
    vector<string> result;

    string possibleChars = getMapping(s[0]);
    for(char c: possibleChars) {
        for(string str: subkpc) {
            result.push_back(c + str);
        }
    }

    return result;
}


int main(){
    string s;
    cin >> s;
    vector<string> ans = getKPC(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}