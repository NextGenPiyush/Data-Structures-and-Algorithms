#include <bits/stdc++.h>
#define ll long long int
#define pp pair<int, int>
using namespace std;

vector<list<pp >> graph;

void add_edge(int u, int v, int wt, bool bidir=true){
    graph[u].push_back({v, wt});
    if(bidir) graph[v].push_back({u, wt});
}

ll prims(int src, int n);

int main() {

// - DS - Visited set, priority_queue<pair> , unordered_map
// - insert the pair of <-1, src> in the pq.
// - one by one remove the root element of the pq
// - if the root element is already visited, then we will just continue.
// - we mark the root visited
// - we store the wt of the pair in the ans
// - update the mapping
// - go to every neighbour of the curr element, and only add those which are non visited and have a better wt proposition.

    int n, m;
    cin>>n>>m;
    graph.resize(n+1, list<pp > ());
    while(m--){
        int u, v, wt;
        cin>>u>>v>>wt;
        add_edge(u, v, wt);
    }

    int src;
    cin>>src;
    cout<<prims(src, n)<<endl;

    return 0;
}

ll prims(int src, int n){
    priority_queue<pp, vector<pp> , greater<pp> > pq; // {wt, node}
    unordered_set<int> vis;
    vector<int> par(n+1);
    unordered_map<int, int> mp;
    for(int i = 1; i <= n; i++) mp[i] = INT_MAX;
    pq.push({0, src});
    mp[src] = 0;
    int total_count = 0; // 0 -> n-1 edges
    int result = 0; // sum of wts
    while(total_count < n && !pq.empty()){
        pp curr = pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        total_count++;
        result += curr.first;
        pq.pop();

        for(auto neighbour : graph[curr.second]){
            if(!vis.count(neighbour.first) and mp[neighbour.first] > neighbour.second){
                pq.push({neighbour.second, neighbour.first});
                par[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second;
            }
        }

    }
    return result;
}