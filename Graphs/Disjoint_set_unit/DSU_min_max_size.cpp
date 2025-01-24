#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &parent, int x);
void Union(vector<int> &parent, vector<int> &size, vector<int> mini, vector<int> maxi, vector<int> &rank, int a, int b);

void file_i_o(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

int main(){

    file_i_o();
    int n,m;
    cin>>n>>m; 
    // n --> no of elements
    // m --> no of queries
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);
    vector<int> size(n+1,1);
    vector<int> minimal(n+1);
    vector<int> maximal(n+1);
    for(int i=0; i<=n; i++) parent[i] = minimal[i] = maximal[i] = i;

    while(m--){
        string str;
        cin>>str;
        if(str == "union"){ // we can also take union by size to do this question
            int x,y;
            cin>>x>>y;
            Union(parent,size,minimal,maximal,rank,x,y);
        }
        else{
            int x;
            cin>>x;
            x = find(parent,x);
            cout<<minimal[x]<<" "<<maximal[x]<<" "<<size[x]<<endl;
        }
    }


    return 0;
}

int find(vector<int> &parent, int x){  // time complexity: log*n
    // this method return which group or cluster x belong to
    return parent[x] = (parent[x] == x) ? x : find(parent,parent[x]);
}

void Union(vector<int> &parent, vector<int> &size, vector<int> mini, vector<int> maxi, vector<int> &rank, int a, int b){  
    a = find(parent,a);
    b = find(parent,b);
    if(a == b) return; // both a and b are in same set. also try to dry run without writting this line
    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
        size[a] += size[b];
        maxi[a] = max(maxi[a], maxi[b]);
        mini[a] = min(mini[a], mini[b]);
    }
    else{
        rank[b]++;
        parent[a] = b;
        size[b] += size[a];
        maxi[b] = max(maxi[a], maxi[b]);
        mini[b] = min(mini[a], mini[b]);
    }
}

