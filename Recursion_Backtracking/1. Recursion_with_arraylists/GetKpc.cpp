#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

// Get Character mapping
string getMapping(char ch) {
    int num = ch - '0';
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

    return um[num];

}

// Function to get valid combinations
vector<string> getKPC(string s){
    if(s.size()==0)
        return {""};

    char firstNum = s[0];
    string restString = s.substr(1);
    vector<string> subkpc = getKPC(restString);
    vector<string> result;

    string possibleChars = getMapping(firstNum);
    for(char c: possibleChars) {
        for(string str: subkpc) {
            result.push_back(c + str);
        }
    }

    return result;
}