#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    //Base cases
    vector<string> baseCase;
    if(sr==dr && sc==dc){
        baseCase.push_back("");
        return baseCase;
    } else if(sr>dr || sc>dc) {
        return baseCase;
    }

    vector<string> paths1 = getMazePaths(sr, sc+1, dr, dc);
    vector<string> paths2 = getMazePaths(sr+1, sc, dr, dc);

    vector<string> allPaths;
    for(string s: paths1) allPaths.push_back("h"+s);
    for(string s: paths2) allPaths.push_back("v"+s);
    
    return allPaths;    
}
    