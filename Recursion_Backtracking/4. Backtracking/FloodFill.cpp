#include<iostream>
#include<vector>

using namespace std;

void floodfill(vector<vector<int>> maze, int row, int col, string asf, vector<vector<bool>> visited) {
    
    // Negative base case
    if(row<0 || col<0 || row>=maze.size() 
        || col>=maze[0].size() 
        || maze[row][col]==1 
        || visited[row][col]==true) {
        return;
    }

    // Positive base case
    if(row==maze.size()-1 && col==maze[0].size()-1) {
        cout << asf << endl;
        return;
    }

    visited[row][col] = true;
    floodfill(maze, row-1, col, asf + "t", visited);
    floodfill(maze, row, col-1, asf + "l", visited);
    floodfill(maze, row+1, col, asf + "d", visited);
    floodfill(maze, row, col+1, asf + "r", visited);
    visited[row][col] = false;
}
