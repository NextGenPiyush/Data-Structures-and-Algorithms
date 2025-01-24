#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<char>>& board);  // Leetcode-130
void bfs(vector<vector<char>> &board, int i, int j);
void multi_source_bfs(vector<vector<char>> &board, queue<pair<int,int>> &q);
void dfs(vector<vector<char>> &board, int i, int j);

int main(){

    // do it yourself

    return 0;
}

void solve(vector<vector<char>>& board){
    int m = board.size();
    int n = board[0].size();

    // for(int i=0; i<m; i++){  // using nomal BFS approach
    //     if(board[i][0] == 'O') bfs(board,i,0);
    //     if(board[i][n-1] == 'O') bfs(board,i,n-1);
    // }
    // for(int j=0; j<n; j++){
    //     if(board[0][j] == 'O') bfs(board,0,j);
    //     if(board[m-1][j] == 'O') bfs(board,m-1,j);
    // }

    // queue<pair<int,int>> q;  // alternate approach using multisource BFS
    // for(int i=0; i<m; i++){
    //     if(board[i][0] == 'O'){ q.push({i,0}); board[i][0] = '1'; }
    //     if(board[i][n-1] == 'O'){ q.push({i,n-1}); board[i][n-1] = '1'; }
    // }
    // for(int j=0; j<n; j++){
    //     if(board[0][j] == 'O'){ q.push({0,j}); board[0][j] = '1'; }
    //     if(board[m-1][j] == 'O'){ q.push({m-1,j}); board[m-1][j] = '1'; }
    // }
    // multi_source_bfs(board,q);

    for(int i=0; i<m; i++){  // alternate approach using DFS 
        if(board[i][0] == 'O') dfs(board,i,0);
        if(board[i][n-1] == 'O') dfs(board,i,n-1);
    }
    for(int j=0; j<n; j++){
        if(board[0][j] == 'O') dfs(board,0,j);
        if(board[m-1][j] == 'O') dfs(board,m-1,j);
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == 'O') board[i][j] = 'X';
            if(board[i][j] == '1') board[i][j] = 'O';
        }
    }

}

void bfs(vector<vector<char>> &board, int i, int j){  // single source bfs
    int m = board.size();
    int n = board[0].size();
    queue<pair<int,int>> q;
    vector<pair<int,int>> direction = {{0,1},{1,0},{0,-1},{-1,0}};
    q.push({i,j});
    board[i][j] = '1';
    while(!q.empty()){
        pair<int,int> temp = q.front();
        q.pop();
        int currRow = temp.first;
        int currCol = temp.second;
        for(auto p: direction){
            int newRow = currRow + p.first;
            int newCol = currCol + p.second;
            if(newRow>=0 and newRow<m and newCol>=0 and newCol<n and board[newRow][newCol]=='O'){
                q.push({newRow,newCol});
                board[newRow][newCol] = '1';
            }
        }
    }
}

void multi_source_bfs(vector<vector<char>> &board, queue<pair<int,int>> &q){  // multi source bfs
    int m = board.size();
    int n = board[0].size();
    vector<pair<int,int>> direction = {{0,1},{1,0},{0,-1},{-1,0}};
    while(!q.empty()){
        pair<int,int> temp = q.front();
        q.pop();
        int currRow = temp.first;
        int currCol = temp.second;
        for(auto p: direction){
            int newRow = currRow + p.first;
            int newCol = currCol + p.second;
            if(newRow>=0 and newRow<m and newCol>=0 and newCol<n and board[newRow][newCol]=='O'){
                q.push({newRow,newCol});
                board[newRow][newCol] = '1';
            }
        }
    }
}

void dfs(vector<vector<char>> &board, int i, int j){ // using dfs
    int m = board.size();
    int n = board[0].size();
    if(i<0 || i>=m || j<0 || j>=n || board[i][j]!='O') return;
    board[i][j] = '1';
    dfs(board,i-1,j); // up
    dfs(board,i,j+1); // right
    dfs(board,i+1,j); // down
    dfs(board,i,j-1); // left
}