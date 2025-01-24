#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v; // no of vertices
int e; // no of edges
unordered_set<int> visited;

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" --> ";
        for(auto ele : graph[i]) cout<<ele<<" , ";
        cout<<endl;
    }
}

bool any_path(int src, int dest);
bool dfs(int curr, int end);

int main(){

    cin>>v;
    graph.resize(v, list<int> ());
    visited.clear(); 
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
        // add_edge(s,d,false);
    }

    display();

    int x,y;
    cin>>x>>y;
    cout<<any_path(x,y);

    return 0;
} 

bool any_path(int src, int dest){
    return dfs(src,dest);
}

bool dfs(int curr, int end){
    if(curr == end) return true;
    visited.insert(curr); // mark visited
    for(int neighbour : graph[curr]){
        if(visited.count(neighbour) == 0){ 
            bool result = dfs(neighbour,end);
            if(result) return true;
        }
    }
    return false;
}




