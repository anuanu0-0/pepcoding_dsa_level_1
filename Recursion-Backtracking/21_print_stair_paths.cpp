#include <iostream>
using namespace std;

void printStairPaths(int n, string psf){
    
    // Base case
    if(n==0) {
        cout << psf << endl;
        return;
    }
    
    // Recursive case
    for(int i=1; i<=3; i++) {
        if(n-i>=0)
            printStairPaths(n-i, psf+to_string(i));
    }
}

int main(){
    int n;
    cin >> n;
    printStairPaths(n, "");
}