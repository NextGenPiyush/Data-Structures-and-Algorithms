#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> visited;
int numIslands(vector<vector<char>>& grid); // Leetcode-200
void dfs(vector<vector<char>> &grid, int i, int j);
void bfs(vector<vector<char>> &grid, int i, int j);

int main(){

    // Calculate the number of islands where the land is denoted by '1' and water is denoted by '0' (Leetcode-200)

    return 0;
}

int numIslands(vector<vector<char>>& grid){   // Leetcode-200
        visited.resize(grid.size(),vector<int>(grid[0].size(),0)); 
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // if(visited[i][j] == 0 and grid[i][j] == '1'){
                //     count++;
                //     dfs(grid,i,j);  // by depth first search
                // }
                if(grid[i][j] == '0') continue;
                count++;
                bfs(grid,i,j);  // by breadth first search
            }
        }
        return count; 
}

void dfs(vector<vector<char>> &grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || visited[i][j]==1 || grid[i][j]=='0') return;
        visited[i][j] = 1;
        dfs(grid,i-1,j); // up
        dfs(grid,i,j+1); // right
        dfs(grid,i+1,j); // down
        dfs(grid,i,j-1); // left
}

void bfs(vector<vector<char>> &grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j]='0';
        vector<pair<int,int>> directions{{0,1},{0,-1},{1,0},{-1,0}};  // good practice 
        while(!q.empty()){
            pair<int,int> temp = q.front();
            q.pop();
            int currRow = temp.first;
            int currCol = temp.second;

            for(auto dir: directions){  // better way to appply bfs through direction vector 
                int newRow = currRow + dir.first;
                int newCol = currCol + dir.second;
                if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && grid[newRow][newCol]=='1'){
                    q.push({newRow, newCol});
                    grid[newRow][newCol] = '0'; // Mark as visited
                }
            }

            // if(currRow-1>=0 and grid[currRow-1][currCol]=='1'){  // up
            //     q.push({currRow-1,currCol});
            //     grid[currRow-1][currCol]='0';
            // }
            // if(currRow+1<m and grid[currRow+1][currCol]=='1'){  // down
            //     q.push({currRow+1,currCol});
            //     grid[currRow+1][currCol]='0';
            // }
            // if(currCol-1>=0 and grid[currRow][currCol-1]=='1'){  // left
            //     q.push({currRow,currCol-1});
            //     grid[currRow][currCol-1]='0';
            // }
            // if(currCol+1<n and grid[currRow][currCol+1]=='1'){  // right
            //     q.push({currRow,currCol+1}); 
            //     grid[currRow][currCol+1]='0';
            // }
        }
}