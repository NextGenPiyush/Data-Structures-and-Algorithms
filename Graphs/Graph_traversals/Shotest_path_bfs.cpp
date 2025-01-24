#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v; // no of vertices
int e; // no of edges
unordered_set<int> visited;
vector<vector<int>> result;

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

void bfs(int src, vector<int> &dist);

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

    int source;
    cin>>source;
    vector<int> v;
    bfs(source,v);
    for(auto ele: v) cout<<ele<<" ";

    display();

    return 0;
} 

void bfs(int src, vector<int> &dist){
    queue<int> q;
    visited.clear();
    dist.resize(v,INT_MAX);
    dist[src] = 0;  // distance from source to source is zero
    visited.insert(src);
    q.push(src);
    while(not q.empty()){
        int curr = q.front();
        cout<<curr<<" ";
        q.pop();
        for(int neighbour : graph[curr]){
            if(not visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour] = dist[curr] + 1;
            }
        }
    }
    cout<<endl;
}





