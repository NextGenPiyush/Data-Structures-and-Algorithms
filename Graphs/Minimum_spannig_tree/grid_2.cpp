#include <bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>>& grid);

int main(){

// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

// given an m*n grid with {L,R,U,D} on every cell and you are starting from top left. Now by spending one unit cost 
// we can replace the character of one cell.
// In what minimum cost we can reach the bottom right? (Leetcode-1368)

// you can first convert matrix into graph then apply dijkastra algorithem for shortest path containing minimum 1s
// we will use dequeue in this case of binary path length

    return 0;
}

int minCost(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int dist[n][m];
    for(int i =0; i < n; i++) for(int j = 0; j < m; j++) dist[i][j] = 1e9;
            
    deque<pair<int,int>> dq;
    dq.push_back({0, 0});
    dist[0][0] = 0; 
    
    while(not dq.empty()){
        auto curr = dq.front();
        dq.pop_front();
        int x = curr.first;
        int y = curr.second;
        int dir = grid[x][y];
            
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
                
            int edgewt = 1;
            if(i + 1 == dir) edgewt = 0;
            
            if(nx < n and ny < m and nx >= 0 and ny >= 0){  // next cell must lies in the grid
                if(dist[nx][ny] > dist[x][y] + edgewt){
                    dist[nx][ny] = dist[x][y] + edgewt;
                    if(edgewt == 1) dq.push_back({nx, ny});
                    else dq.push_front({nx, ny});
                }
            }
        }
    }
    return dist[n-1][m-1];
}
