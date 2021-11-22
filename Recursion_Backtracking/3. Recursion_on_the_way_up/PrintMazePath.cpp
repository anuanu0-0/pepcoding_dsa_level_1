#include <iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf){
    
    // Base case
    if(sr==dr && sc==dc) {
        cout << psf << endl;
        return;
    }
    else if(sc>dc || sr>dr) {
        // Not possible case
        return;
    }
    
    // Recursive case
    printMazePaths(sr, sc+1, dr, dc, psf + "h");
    printMazePaths(sr+1, sc, dr, dc, psf + "v");

}
