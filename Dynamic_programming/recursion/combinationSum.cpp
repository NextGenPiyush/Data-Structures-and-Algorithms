#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target); // Leetcode-39
void func(vector<int>& candidates, int idx, int sum ,int &target, vector<int> &sub, vector<vector<int>> &ans);

vector<vector<int>> combinationSum2(vector<int>& candidates, int target); // Leetcode-40
void func(vector<int>& candidates, int idx, int target, vector<int> &v, vector<vector<int>> &ans);

int main(){

    
    return 0;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){  // Leetcode-39
    vector<vector<int>> ans;
    vector<int> sub;                      // Time complexity: O(2^t * k) 
    func(candidates,0,0,target,sub,ans);  // where t is the target and k is length
    return ans; 
}

void func(vector<int>& candidates, int idx, int sum ,int &target, vector<int> &sub, vector<vector<int>> &ans){
    if(sum == target){
        ans.push_back(sub);
        return;
    }
    if(idx == candidates.size() || sum > target) return;
    sub.push_back(candidates[idx]);
    func(candidates,idx,sum+candidates[idx],target,sub,ans);
    sub.pop_back();
    func(candidates,idx+1,sum,target,sub,ans);

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target){ // Leetcode-40
    int n = candidates.size();                     // good questoin attempt again latter
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> ans;
    vector<int> v;
    func(candidates,0,target,v,ans);
    return ans;
}

void func(vector<int>& candidates, int idx, int target, vector<int> &v, vector<vector<int>> &ans){
    int n = candidates.size();
    if(target == 0){
        ans.push_back(v);
        return;
    }
    for(int i=idx; i<n; i++){
        if(i>idx and candidates[i]==candidates[i-1]) continue;  
        if(candidates[i]>target) break; // no need to check further as array is sorted
        v.push_back(candidates[i]);
        func(candidates,i+1,target-candidates[i],v,ans);
        v.pop_back(); //  backtraking 
    }
}