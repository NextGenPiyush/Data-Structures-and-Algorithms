#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int idx, int end){
    int i = idx;
    int j = end;
    while(i<=j) if(s[i++] != s[j--]) return false;
    return true;
}

vector<vector<string>> partition(string s); // Leetcode-131
void func(string &s, int idx, vector<string> &v, vector<vector<string>> &ans);

int main(){

    return 0;
}

vector<vector<string>> partition(string s){  // Leetcode-131
    vector<vector<string>> ans;
    vector<string> v;
    func(s,0,v,ans);
    return ans;
}

void func(string &s, int idx, vector<string> &v, vector<vector<string>> &ans){
    int n = s.length();
    if(idx == n){
        ans.push_back(v);  // Try to attempt this question againg latter
        return;
    }
    for(int i=idx; i<=n; i++){
        if(isPalindrome(s,idx,i)){
            v.push_back(s.substr(idx,i-idx+1)); // first parameter is the index and second is the length
            func(s,i+1,v,ans);
            v.pop_back(); //backtraking
        } 
    }
}