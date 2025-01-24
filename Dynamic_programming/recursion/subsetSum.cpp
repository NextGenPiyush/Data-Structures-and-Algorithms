#include<bits/stdc++.h>
using namespace std;

vector<int> subsetSums(vector<int>& arr);
void func(vector<int> &arr, int idx, int sum, vector<int> &ans);

vector<vector<int>> subset_without_duplicate(vector<int>& nums); // Leetcode-90
void func(vector<int> &nums, int idx, vector<int> &sub, vector<vector<int>> &ans);

int main(){

    return 0;
}

vector<int> subsetSums(vector<int>& arr){
    vector<int> ans;
    func(arr,0,0,ans);
    return ans;
}

void func(vector<int> &arr, int idx, int sum, vector<int> &ans){
    if(idx == arr.size()){
        ans.push_back(sum);
        return;
    }
    func(arr,idx+1,sum+arr[idx],ans);
    func(arr,idx+1,sum,ans);
}

vector<vector<int>> subset_without_duplicate(vector<int>& nums){ // Leetcode-90
    vector<vector<int>> ans;
    vector<int> sub;   // attempt this question again latter 
    sort(nums.begin(),nums.end());
    func(nums,0,sub,ans);
    return ans;
}

void func(vector<int> &nums, int idx, vector<int> &sub, vector<vector<int>> &ans){
    ans.push_back(sub);
    for(int i=idx; i<nums.size(); i++){
        if(i != idx and nums[i] == nums[i-1]) continue;
        sub.push_back(nums[i]);
        func(nums,i+1,sub,ans);
        sub.pop_back();
    }
}