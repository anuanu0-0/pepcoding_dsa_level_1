#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Note: Keep track of different brances
// and append to corresponding paths
vector<string> get_stair_paths(int n){
    vector<string> baseCase;
    if(n==0) {
        baseCase.push_back("");
        return baseCase;
    }
    else if(n<0)  
        return baseCase;

    vector<string> p1 = get_stair_paths(n-1);
    vector<string> p2 = get_stair_paths(n-2);
    vector<string> p3 = get_stair_paths(n-3);
    vector<string> allPaths;

    for(string p:p1) allPaths.push_back("1"+p);
    for(string p:p2) allPaths.push_back("2"+p);
    for(string p:p3) allPaths.push_back("3"+p);
    
    return allPaths;
}
