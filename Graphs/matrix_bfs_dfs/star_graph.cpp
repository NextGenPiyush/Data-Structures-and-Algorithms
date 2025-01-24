#include<bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>>& edges){  // Leetcode-1791
    int a = edges[0][0];
    int b = edges[0][1];
    int c = edges[1][0];
    int d = edges[1][1];
    return (c == a || c == b) ? c : d;
}

int main(){

    return 0;
}