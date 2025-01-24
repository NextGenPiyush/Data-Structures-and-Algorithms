#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> direction = {{0,1},{1,0},{-1,0},{0,-1}};
int shortestBridge(vector<vector<int>>& grid);  // Leetcode-934
int multiBFS(vector<vector<int>>& grid, queue<pair<int,int>> &q);
void markIslandAndCollectBorders(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& borders);

int main(){

    // Return the smallest number of 0's you must flip to connect the two islands.

    return 0;
}

int shortestBridge(vector<vector<int>>& grid){  // Leetcode-934
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> borders;
    bool found = false;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1){   
                markIslandAndCollectBorders(grid,i,j,borders);  // making one land initialized with -1
                found = true;
                break;
            }
        }
        if(found) break;
    }
    return multiBFS(grid,borders);
}

void markIslandAndCollectBorders(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& borders){
    int m = grid.size();
    int n = grid[0].size();  
    queue<pair<int, int>> q;
    q.push({i, j});
    grid[i][j] = -1; // Mark the cell as part of the first island
    while (!q.empty()){
        auto temp = q.front();
        q.pop();
        int currRow = temp.first;
        int currCol = temp.second;
        bool isBorder = false;
        for(auto p: direction){
            int newRow = currRow + p.first;
            int newCol = currCol + p.second;
            if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n){
                if(grid[newRow][newCol] == 0) isBorder = true; // It's a border if adjacent to water
                else if(grid[newRow][newCol] == 1){
                    q.push({newRow, newCol});
                    grid[newRow][newCol] = -1; // Mark as visited
                }
            }
        }
        if(isBorder) borders.push({currRow, currCol}); // Add only border cells to the queue
    }
}

int multiBFS(vector<vector<int>>& grid, queue<pair<int,int>> &q){
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            pair<int,int> temp = q.front();
            q.pop();
            int currRow = temp.first;
            int currCol = temp.second;
            for(auto p: direction){
                int newRow = currRow + p.first;
                int newCol = currCol + p.second;
                if(newRow>=0 and newRow<m and newCol>=0 and newCol<n){
                    if(grid[newRow][newCol] == 1) return count;
                    if (grid[newRow][newCol] == 0){
                        q.push({newRow, newCol});
                        grid[newRow][newCol] = 2; // Mark as visited
                    }
                }
            }
        }
        count++;
    }
    return -1;
}

