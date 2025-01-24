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

void all_path(int src, int dest);
void dfs(int curr, int end, vector<int> &path);

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
    all_path(x,y);

    cout<<result.size();
    for(vector<int> path : result){
        for(int ele : path) cout<<ele<<" ";
        cout<<endl;
    }

    return 0;
} 

void all_path(int src, int dest){
    vector<int> v; // empty vector of integer
    dfs(src,dest,v);
}

void dfs(int curr, int end, vector<int> &path){
    if(curr == end){
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();  // we are poping to backtrack 
        return;
    }
    visited.insert(curr); // mark visited
    path.push_back(curr);
    for(int neighbour : graph[curr]) if(not visited.count(neighbour)) dfs(neighbour, end, path);
    path.pop_back();  // we are poping to backtrack 
    visited.erase(curr);  // we are erasing so that we can visit again on the node 
    return;
}




