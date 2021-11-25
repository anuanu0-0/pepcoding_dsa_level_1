#include<bits/stdc++.h>
using namespace std;

// Check for safe state
bool isStateSafe(vector<vector<int>> chess, int r, int c) {
    for(int i=r-1, j=c; i>=0; i--){
        if(chess[i][j]==1)
            return false;
    }

    for(int i=r-1, j=c-1; i>=0 && j>=0; i--, j--) {
        if(chess[i][j]==1)
            return false;
    }

    for(int i=r-1, j=c+1; i>=0 && j<chess.size(); i--, j++) {
        if(chess[i][j]==1)
            return false;
    }
    return true;
}

void printNQueens(vector<vector<int>> chess,string qsf,int row){    
    // Base case
    if(row==chess.size()) {
        cout << qsf << "." << endl;
        return;
    }

   for(int col=0; col<chess.size(); col++) {
       if(isStateSafe(chess, row, col)==true) {
           chess[row][col]=1;
           string val = qsf + to_string(row) + "-" + to_string(col) + ", ";
           printNQueens(chess, val, row+1);
           chess[row][col]=0;
       }
   }
}