#include<bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> graph;
int v; // no of vertices
int e; // no of edges

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].insert(dest);  // it is jusl like insertion in sets --> set.insert();
    if(bi_dir) graph[dest].insert(src); 
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" --> ";
        for(int ele : graph[i]) cout<<ele<<" , ";
        cout<<endl;
    }
}

int main(){

    cin>>v;
    graph.resize(v, unordered_set<int> ());  
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
        // add_edge(s,d,false);
    }

    display();

    return 0;
}