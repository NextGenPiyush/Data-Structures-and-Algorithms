#include<bits/stdc++.h>
using namespace std;

vector<unordered_map<int,int>> graph;  // vector of maps of pair (int,int)
int v; // no of vertices
int e; // no of edges

void add_edge(int src, int dest, int weight, bool bi_dir = true){
    graph[src][dest] = weight;  // it is jusl like insertion in maps --> map["Harry"] = 98;
    if(bi_dir) graph[dest][src] = weight;
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" --> { ";
        for(pair<int,int> ele : graph[i]) cout<<"{"<<ele.first<<","<<ele.second<<"}"<<"  ";
        cout<<"}"<<endl;
    }
}

int main(){

    cin>>v;
    graph.resize(v, unordered_map<int,int> ());  // we can use unordered_set for unweighted graph
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt);
        // add_edge(s,d,wt,false);
    }

    display();

    return 0;
}