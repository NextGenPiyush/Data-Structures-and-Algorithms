#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid); // Leetcode-994

int orangesRotting_2(vector<vector<int>>& grid);
void bfs(vector<vector<int>>& grid, queue<pair<int,int>> &q, int &count);

int main(){

    // calculate the time required in rotten of the fresh oranges (Leetcode-994)
    // it is a questionn of multi source Breadth first search

    return 0;
}

int orangesRotting(vector<vector<int>>& grid){ // Leetcode-994
    queue<pair<int,int>> qu;
    int fresh_orange = 0;
    int n = grid.size();
    int m = grid[0].size();
    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1) fresh_orange++;
            else if(grid[i][j] == 2) qu.push({i, j}); // multi source bfs step
        }
    }
    qu.push({-1, -1});  // indicate that we have traversed all the rotten oranges one time
    int mins = 0;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while(!qu.empty()) {
        auto cell = qu.front();
        qu.pop();
        if(cell.first == -1 && cell.second == -1){  // means we have rotten the particular set of oranges
            mins++;
            if(!qu.empty()) qu.push({-1, -1}); 
            else break;  // means we dont have to add {-1,-1} if we have reached to the end
        } 
        else{
            int i = cell.first;
            int j = cell.second;
            for(int d = 0; d < 4; d++) {
                int neighbour_row = i + dir[d][0];
                int neighbour_col = j + dir[d][1];
                if(neighbour_row < 0 || neighbour_col < 0 || neighbour_row >= n || neighbour_col >= m) continue;
                if(grid[neighbour_row][neighbour_col] == 2 || grid[neighbour_row][neighbour_col] == 0) continue;
                fresh_orange--;
                grid[neighbour_row][neighbour_col] = 2; // rottenn the orange
                qu.push({neighbour_row, neighbour_col});
            }
        }
    }
    return (fresh_orange == 0) ? mins-1 : -1; // we have write mins-1 because we have added extra 1 when there eas last {-1,-1}
}

int orangesRotting_2(vector<vector<int>>& grid){ // alternate approach
    int m = grid.size();
    int n = grid[0].size();
    int freshCount = 0;
    queue<pair<int,int>> q;
    for(int i=0; i<m; i++) for(int j=0; j<n; j++){
        if(grid[i][j]==2) q.push({i,j});
        if(grid[i][j]==1) freshCount++;
    }
    if(freshCount == 0) return 0;  // checking if fresh oranges is present or not 
    int count = 0;
    bfs(grid,q,count);
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) if(grid[i][j]==1) return -1;  // chekking if any fresh orange remaining
    return count;
}

void bfs(vector<vector<int>>& grid, queue<pair<int,int>> &q, int &count){
    int m = grid.size();
    int n = grid[0].size();
    vector<pair<int,int>> directions{{0,1},{0,-1},{1,0},{-1,0}};  // good practice 
    while(!q.empty()){
        int size = q.size();
        bool hasRotten = false;
        for(int i=0; i<size; i++){
            pair<int,int> temp = q.front();
            q.pop();
            int currRow = temp.first;
            int currCol = temp.second;
            grid[currRow][currCol] = 2;
            for(auto dir: directions){  // better way to appply bfs through direction vector 
                int newRow = currRow + dir.first;
                int newCol = currCol + dir.second;
                if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && grid[newRow][newCol]==1){
                    q.push({newRow, newCol});
                    grid[newRow][newCol] = '2'; // rotten the orange
                    hasRotten = true;
                }
            }
        }
        if(hasRotten) count++;            
    }
}


