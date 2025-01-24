#include<bits/stdc++.h>
using namespace std;

unordered_set<pair<int,int>> visited;
vector<pair<int,int>> direction = {{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};

int knight_1(int A, int B, int C, int D, int E, int F); // here A*B is the dimention of the matrix 
// (c,d) is the initiall position of the knight and (e,f) is the destination position

int minimum_knight_move(int x, int y); // Leetcode-1197  

int main(){

    // we have to return minimum moves taken by knight to reach to the destination where dimensions,
    // start point and destination point are given (Knight_1) 

    // in other question of minimum_knight_move function starting position is (0,0) and destination is (x,y) 
    // also the matrix is infinite but the constraint is |x|+|y|<=300 

    return 0;
}

int knight_1(int A, int B, int C, int D, int E, int F){
    if (C == E && D == F) return 0; // if starting point is the destination point then return 0
    int count = 0;
    queue<pair<int,int>> q;
    q.push({C,D});
    visited.clear();
    visited.insert({C,D});  // mark it visited
    while(!q.empty()){
        count++;  // Increment at the start of processing this BFS level
        int size = q.size();
        for(int i=0; i<size; i++){
            pair<int,int> temp = q.front();
            q.pop();
            int currRow = temp.first;
            int currCol = temp.second;
            for(pair<int,int> p: direction){
                int newRow = currRow + p.first;
                int newCol = currCol + p.second;
                if(newRow==E and newCol==F) return count;  // means we have reahced to the final destination
                if(newRow>=0 and newRow<A and newCol>=0 and newCol<B and (visited.find({newRow,newCol})==visited.end()) ){
                    q.push({newRow,newCol});
                    visited.insert({newRow,newCol});
                }
            }
        }
    }
    return -1;
}

int minimum_knight_move(int x, int y){  // Leetcode 1197
    if(x == 0 and y == 0) return 0;
    int count = 1;  // make sure if you are intializing count as 0 then you have to do count++ in the start of bfs
    queue<pair<int,int>> q;
    q.push({0,0}); // insert the starting point of the knight which is (0,0) in this case 
    visited.clear();
    visited.insert({0,0});
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            pair<int,int> temp = q.front();
            q.pop();
            int currRow = temp.first;
            int currCol = temp.second;
            for(pair<int,int> p: direction){
                int newRow = currRow + p.first;
                int newCol = currCol + p.second;
                if(newRow==x and newCol==y) return count;  // means we have reahced to the final destination
                if((abs(newRow)+abs(newCol)<=300) and (visited.find({newRow,newCol})==visited.end())){
                    q.push({newRow,newCol});         
                    visited.insert({newRow,newCol});
                }
            }   
        }
        count++;
    }
    return -1;
}