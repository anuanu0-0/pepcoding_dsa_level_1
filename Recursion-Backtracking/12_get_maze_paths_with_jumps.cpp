#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> get_maze_paths(int sr, int sc, int dr, int dc) {
    
    if(sr>dr || sc>dc) return {};
    else if(sr==dr && sc==dc){
        return {""};
    }

    vector<string> paths;
    for(int i=1; i<=dc-sc; i++) {
        vector<string> hPaths = get_maze_paths(sr, sc+i, dr, dc);
        for(string s:hPaths) paths.push_back("h" + to_string(i) + s);
    }

    for(int i=1; i<=dr-sr; i++) {
        vector<string> vPaths = get_maze_paths(sr+i, sc, dr, dc);
        for(string s:vPaths) paths.push_back("v" + to_string(i) + s);
    }

    for(int i=1; i<=dc-sc && i<=dr-sr; i++) {
        vector<string> dPaths = get_maze_paths(sr+i, sc+i, dr, dc);
        for(string s:dPaths) paths.push_back("d" + to_string(i) + s);
    }

    return paths;
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
    vector<string> ans = get_maze_paths(0,0,n-1,m-1);
    display(ans);

    return 0;
}