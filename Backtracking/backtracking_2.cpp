#include<bits/stdc++.h>
using namespace std;

void SudokuSolver(vector<vector<char>> &board);  // Leetcode-37
bool func(vector<vector<char>> &board, int row, int col);
bool isSafe(vector<vector<char>> &board, int row, int col, int ele);

vector<vector<int>> result;
vector<vector<int>> combinationSum2(vector<int> &candidates, int target); // Leetcode-40
void func(vector<int> &candidates, int target, int idx, vector<int> &subset);
// Try Leetcode-39 Combination sum

void KnightsTour(int n, int i, int j);
bool isSafe(vector<vector<int>> &grid, int i, int j, int n);
void func(vector<vector<int>> &grid, int i, int j, int n, int count);
void display(vector<vector<int>> &grid, int n);
int dx[8] = {-2,-1,-2,-1,2,1,2,1};
int dy[8] = {1,2,-1,-2,1,2,-1,-2};

int main(){

    KnightsTour(5,0,0);
    
    
    return 0;
}

void SudokuSolver(vector<vector<char>> &board){  // Leetcode-37
    func(board,0,0);
}
bool func(vector<vector<char>> &board, int row, int col){
    if(row == 9) return true;
    if(col == 9) return func(board,row+1,0);
    if(board[row][col] != '.') return func(board,row,col+1);
    for(int j=1; j<=9; j++){
        if(isSafe(board,row,col,j)){
            board[row][col] = '0' + j;
            bool retval = func(board,row,col+1);
            if(retval) return true;
            board[row][col] = '.';
        }
    }
    return false;
}
bool isSafe(vector<vector<char>> &board, int row, int col, int ele){
    for(int j=0; j<9; j++) if(board[row][j]-'0' == ele) return false;  // checking the row
    for(int i=0; i<9; i++) if(board[i][col]-'0' == ele) return false;  // checking the column
    
    int x = (row/3)*3, y = (col/3)*3;  // checking the block 
    for(int i=x; i<x+3; i++) for(int j=y; j<y+3; j++) if(board[i][j]-'0' == ele) return false;
    
    return true;
}


vector<vector<int>> combinationSum2(vector<int> &candidates, int target){  // Leetcode-40
    sort(candidates.begin(),candidates.end());
    vector<int> subset;
    func(candidates,target,0,subset);
    return result;
}
void func(vector<int> &candidates, int target, int idx, vector<int> &subset){
    if(target == 0){
        result.push_back(subset);
        return;
    }
    if(idx == candidates.size()) return;
    if(candidates[idx] <= target){  // pick 
        subset.push_back(candidates[idx]);
        func(candidates,target-candidates[idx],idx+1,subset);
        subset.pop_back();
    }
    int j = idx+1;
    while(j<candidates.size() and candidates[j]==candidates[j-1]) j++;  // this is done for duplicates  
    func(candidates,target,j,subset);  // not pick  
}


void KnightsTour(int n, int i, int j){
    vector<vector<int>> grid(n,vector<int>(n,-1));
    func(grid,i,j,n,0);
}
bool isSafe(vector<vector<int>> &grid, int i, int j, int n){
    return i>=0 and j>=0 and i<n and j<n and grid[i][j] == -1;
}
void func(vector<vector<int>> &grid, int i, int j, int n, int count){
    if(count == (n*n)-1){
        grid[i][j] = count;
        display(grid,n);
        cout<<"***********************************************"<<endl<<endl;
        grid[i][j] = -1;
        return;
    }
    for(int k=0; k<8; k++){
        if(isSafe(grid,i+dx[k],j+dy[k],n)){
            grid[i][j] = count;
            func(grid,i+dx[k],j+dy[k],n,count+1);
            grid[i][j] = -1;
        }
    }
}
void display(vector<vector<int>> &grid, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout<<grid[i][j]<<"    ";
        cout<<endl;
    }
}