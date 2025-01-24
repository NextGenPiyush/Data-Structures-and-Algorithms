#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> distMatrix;
vector<vector<int>> visited;
vector<vector<int>> updateMatrix(vector<vector<int>>& mat);
void bfs(vector<vector<int>>& mat, queue<pair<int,int>> &q);

int main(){

    // Tell the minimum distance  (Leetcode-542)

    return 0;
}

vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
    int m = mat.size();
    int n = mat[0].size();
    visited.clear();
    visited.resize(m,vector<int>(n,0));
    distMatrix.clear();
    distMatrix.resize(m,vector<int>(n,0));
    queue<pair<int,int>> q;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j]==0){
                q.push({i,j});
                distMatrix[i][j] = 0;
                visited[i][j] = 1;
            }
        }
    }
    bfs(mat,q);   
    return distMatrix;        
}

void bfs(vector<vector<int>>& mat, queue<pair<int,int>> &q){
    int m = mat.size();
    int n = mat[0].size();
    vector<pair<int,int>> direction = {{0,1},{1,0},{0,-1},{-1,0}};
    int a = 1;  // we can think of alternate approach of adding {-1,-1} in the end of the queue as set completes
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
                if(newRow>=0 and newRow<m and newCol>=0 and newCol<n and visited[newRow][newCol]!=1){
                    q.push({newRow,newCol});
                    visited[newRow][newCol] = 1;
                    distMatrix[newRow][newCol] = a;
                }
            }
        }
        a++;
    }
}