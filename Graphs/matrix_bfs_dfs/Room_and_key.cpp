#include<bits/stdc++.h>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms);  // Leetcode-841

int main(){

    

    return 0;
}

bool canVisitAllRooms(vector<vector<int>>& rooms){  // Leetcode-841
    unordered_set<int> visited;
    queue<int> qu;
    qu.push(0);  visited.insert(0);
    while(!qu.empty()) {
        int curr = qu.front();
        qu.pop();
        for(int neighbour: rooms[curr]){
            if(visited.count(neighbour) == 0){ // neighbour not yet visited
                qu.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }
    return visited.size() == rooms.size();
}