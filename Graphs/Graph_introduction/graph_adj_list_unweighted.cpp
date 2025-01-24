#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;  // also try to implement from vector<vector<int>>
int v; // no of vertices  
int e; // no of edges

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);  // push_back() function is used to attach at the back of the LinkedList
    if(bi_dir) graph[dest].push_back(src);
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" --> ";
        for(int ele : graph[i]) cout<<ele<<" , ";
        cout<<endl;
    }
}

int main(){

    cin>>v;  // Enter the number of vectices
    graph.resize(v, list<int> ());  // vector of size v(vertices) containg empty LinkedList at each index 
    cin>>e; // Enter the number of edges
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);  // automatially bidirectional is true
        // add_edge(s,d,false); // edge will be created from source to destination
    }

    display();

    return 0;
}
