#include<iostream>
#include<string>
using namespace std;


void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
    
    // Base case
    if (sr==dr && sc==dc) {
        cout << psf << endl;
        return;
    }


    for(int i=1; i<=dc-sc; i++) {
        printMazePaths(sr, sc+i, dr, dc, psf + "h" + to_string(i));
    }

    for(int i=1; i<=dr-sr; i++) {
        printMazePaths(sr+i, sc, dr, dc, psf + "v" + to_string(i));
    }


    for(int i=1; i<=dr-sr && i<=dc-sc; i++) {
        printMazePaths(sr+i, sc+i, dr, dc, psf + "d" + to_string(i));
    }
}