#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    vector<string> baseCase;
    if(sc>dc || sr>dr) return baseCase;
    else if(sc==dc && sr==dr) {
        baseCase.push_back("");
        return baseCase;
    }

    vector<string> hPaths = getMazePaths(sr, sc+1, dr, dc);
    vector<string> vPaths = getMazePaths(sr+1, sc, dr, dc);

    vector<string> allPaths;
    for(string s : hPaths) allPaths.push_back("h" + s);
    for(string s : vPaths) allPaths.push_back("v" + s);
    
    return allPaths;
}


void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}