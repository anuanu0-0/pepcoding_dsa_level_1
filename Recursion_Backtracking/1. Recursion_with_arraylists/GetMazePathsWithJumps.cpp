#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Error correction : Use to_string
vector<string> get_maze_paths(int sr, int sc, int dr, int dc) {
    if(sr==dr && sc==dc){
        vector<string> baseCase;
        baseCase.push_back("");
        return baseCase;
    } 

    vector<string> allPaths;
     // Horizaontal paths 
    for(int i=1; i<=dc-sc; i++) {
        vector<string> vPaths = get_maze_paths(sr, sc+i, dr, dc);
        for(string path : vPaths){
            allPaths.push_back("h" + to_string(i) + path);
        }
    }

 
    // Vertical Paths
    for(int i=1; i<=dr-sr; i++) {
        vector<string> hPaths = get_maze_paths(sr+i, sc, dr, dc);
        for(string path : hPaths){
            allPaths.push_back("v" + to_string(i) + path);
        }
    }


    // Diagonal Paths
    for(int i=1; i<=dc-sc && i<=dr-sr; i++) {
        vector<string> dPaths = get_maze_paths(sr+i, sc+i, dr, dc);
        for(string path : dPaths){
            allPaths.push_back("d" + to_string(i) + path);
        }
    }

    return allPaths;
}