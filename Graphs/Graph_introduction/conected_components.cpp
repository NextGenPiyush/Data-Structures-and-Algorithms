#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;  // adjacency list representation 
int v; // no of vertices
int e; // no of edges

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void dfs(int node, unordered_set<int> &visited) {
    visited.insert(node);
    for(int neighbor : graph[node]) if(visited.count(neighbor) == 0) dfs(neighbor, visited);
}

int connected_components(){
    int result = 0;
    unordered_set<int> visited;
    for(int i=0; i<v; i++){ //O(v)
        if(visited.count(i) == 0){  // means we have to start dfs from here as it is not visited
            result++;
            dfs(i, visited); //total O(v+E)
        }  // we can also apply bfs algorithem to calculate connected component
    }
    return result;
}

int main() {

    cin>>v;
    graph.resize(v, list<int> ());
    cin>>e;
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s, d, false);
    }

    cout<<"Number of connected components: "<<connected_components()<<endl;

    return 0;
}
