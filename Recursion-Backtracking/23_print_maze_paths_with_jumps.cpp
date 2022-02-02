#include<iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
    
    if(sr>dr || sc>dc) return;
    else if(sr==dr && sc==dc) {
        cout << psf << endl;
        return;
    }

    // Horizontal paths
    for(int i=1; i<=dc-sc; i++) {
        printMazePaths(sr, sc+i, dr, dc, psf + "h" + to_string(i));
    }

    // Vertical paths
    for(int i=1; i<=dr-sr; i++) {
        printMazePaths(sr+i, sc, dr, dc, psf + "v" + to_string(i));
    }

    // Diagonal paths   
    for(int i=1; i<=dc-sc && i<=dr-sr; i++) {
        printMazePaths(sr+i, sc+i, dr, dc, psf + "d" + to_string(i));
    }     
}

int main() {
        int n ;
        int m ;cin>>n>>m;
        printMazePaths(0, 0, n - 1, m - 1, "");
    }