#include<bits/stdc++.h>
using namespace std;

vector<list<pair<int,int>>> graph; // here we have used vector of list of pair of (int,int)
int v; // no of vertices
int e; // no of edges

void add_edge(int src, int dest, int weight, bool bi_dir = true){
    graph[src].push_back({dest,weight});
    if(bi_dir) graph[dest].push_back({src,weight});
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" --> ";
        for(pair<int,int> ele : graph[i]) cout<<"{"<<ele.first<<","<<ele.second<<"}"<<" , ";
        cout<<endl;
    }
}

int main(){

    cin>>v;
    graph.resize(v, list<pair<int,int>> ()); // size of grpah vector is v(vectices) including empty list of pair(int,int)
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
