#include<bits/stdc++.h>
using namespace std;
  
void wallsAndGate(vector<vector<int>> &rooms);  // Leetcode-286
void multi_source_bfs(vector<vector<int>> &rooms, queue<pair<int,int>> &q);

int main(){

    // empty room denoted by INT_MAX while gate and wall denoted by 0 and -1 respectively
    // we have find out the minimum no of steps to reach gate for every empty room

    return 0;
}

void wallsAndGate(vector<vector<int>> &rooms){  // Leetcode-286
    int m = rooms.size();
    int n = rooms[0].size();
    queue<pair<int,int>> q;
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) if(rooms[i][j] == 0) q.push({i,j});
    multi_source_bfs(rooms,q);
}

void multi_source_bfs(vector<vector<int>> &rooms, queue<pair<int,int>> &q){  // multi source bfs
    int m = rooms.size();
    int n = rooms[0].size();
    vector<pair<int,int>> direction = {{0,1},{1,0},{0,-1},{-1,0}};
    int a = 0;
    while(!q.empty()){
        int size = q.size();
        a++;
        for(int i=0; i<size; i++){
            pair<int,int> temp = q.front();
            q.pop();
            int currRow = temp.first;
            int currCol = temp.second;
            for(auto p: direction){
                int newRow = currRow + p.first;
                int newCol = currCol + p.second;
                if(newRow>=0 and newRow<m and newCol>=0 and newCol<n and rooms[newRow][newCol]==INT_MAX){
                    q.push({newRow,newCol});
                    rooms[newRow][newCol] = a;
                }
            }
        }
        
    }
}