#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;  // no of vertices
int e;  // no of edges

void add_edge(int a, int b, bool bidir);
void topoBFS();

int main(){

    cin>>v>>e;
    graph.resize(v,list<int> ());
    while(e--){
        int x,y;
        cin>>x>>y;
        add_edge(x,y,false);
    }    

    topoBFS();
    // homework: Implement topological sorting using Depth First Search

    return 0;
}

void add_edge(int a, int b, bool bidir = true){
    graph[a].push_back(b);
    if(bidir) graph[b].push_back(a);
}

void topoBFS(){  // kahn's algorithem
    vector<int> indegree(v,0);
    for(int i=0; i<v; i++) for(auto neighbour : graph[i]) indegree[neighbour]++;
    queue<int> qu;
    unordered_set<int> visited;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            qu.push(i);
            visited.insert(i);
        }
    }
    while(!qu.empty()){  // multisource BFS
        int node = qu.front();
        cout<<node<<" ";
        qu.pop();
        for(auto neighbour : graph[node]){
            if(visited.count(neighbour) == 0){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    qu.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }
}