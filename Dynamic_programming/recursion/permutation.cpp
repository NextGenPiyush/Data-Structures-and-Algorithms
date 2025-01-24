#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> premutations(vector<int> nums); 
void func_2(vector<int> &nums, int idx, vector<vector<int>> &ans);
void func_1(vector<int> &nums, vector<bool> &visited, vector<int> &v, vector<vector<int>> &ans);

int main(){

    return 0;
}

vector<vector<int>> premutations(vector<int> nums){  
    vector<vector<int>> ans;
    vector<bool> visited(nums.size(),false);
    vector<int> v;
    func_1(nums,visited,v,ans);
    // func_2(nums,0,ans);
    return ans;
}

void func_1(vector<int> &nums, vector<bool> &visited, vector<int> &v, vector<vector<int>> &ans){
    if(v.size() == nums.size()){
        ans.push_back(v);
        return;
    }
    for(int i=0; i<nums.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            v.push_back(nums[i]);
            func_1(nums,visited,v,ans);
            v.pop_back();
            visited[i] = false;
        }
    }
}

void func_2(vector<int> &nums, int idx, vector<vector<int>> &ans){
    if(idx == nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=idx; i<nums.size(); i++){
        swap(nums[idx],nums[i]);
        func_2(nums,i+1,ans);
        swap(nums[idx],nums[i]);
    }
}