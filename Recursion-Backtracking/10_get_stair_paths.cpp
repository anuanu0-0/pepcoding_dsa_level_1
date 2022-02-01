#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> get_stair_paths(int n){
    if(n==0)
        return {""};

    vector<string> p1, p2, p3;
    if(n-1>=0)
        p1 = get_stair_paths(n-1);
    if(n-2>=0)
        p2 = get_stair_paths(n-2);
    if(n-3>=0)
        p3 = get_stair_paths(n-3);

    vector<string> allPaths;
    for(string p:p1) allPaths.push_back("1" + p);
    for(string p:p2) allPaths.push_back("2" + p);
    for(string p:p3) allPaths.push_back("3" + p);

    return allPaths;
}

int main(){
    int n;
    cin >> n;
    vector<string> ans = get_stair_paths(n);
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