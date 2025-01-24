#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int func(string s1,string s2, int idx1, int idx2){   // bottom down approach 
    if(idx1 == s1.size() || idx2 == s2.size()) return 0;
    if(dp[idx1][idx2] != -1) return dp[idx1][idx2]; 
    if(s1[idx1] == s2[idx2]) return dp[idx1][idx2] =  1 + func(s1,s2,idx1+1,idx2+1);  
    return dp[idx1][idx2] = max(func(s1,s2,idx1+1,idx2),func(s1,s2,idx1,idx2+1));
}

int LCS(string s1, string s2){
    int n = s1.size();
    int m = s2.size();  // Time complexity: O(2^(m+n)) without using dp
    dp.resize(n+5,vector<int>(m+5,-1));  // Time complexity: O(nm) with dp
    return func(s1,s2,0,0);  // space complexity: O(mn) + O(n+m) 
}

int main(){

    string s1 = "";
    string s2 = "";




    return 0;
}