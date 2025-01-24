#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
bool func(vector<int> &v, int idx, int target);
bool isSubsetSum(vector<int>& arr, int target);

int main(){

    // generate all the subsequece and check if sum is equal to target or not
    // now there are two methods of generating all the subsequence first ony by using bit manipulation and 
    // second one by using recursion 
    // 1. open power_set.cpp 
    // 2. string_subsequence.cpp or array_subsequence.cpp

    // now in subsequence_sum_k.cpp we have find all the subsequence with sum k but here we have to find only
    // if there is any subset with sum k 



    return 0;
}

bool func(vector<int> &v, int idx, int target){  
    if(target == 0) return true;  /// try to implement bottom up approach
    if(idx == v.size() || target < 0) return false;
    if(dp[idx][target] != -1) return dp[idx][target];
    return dp[idx][target] = func(v,idx+1,target-v[idx]) or func(v,idx+1,target);
}

bool isSubsetSum(vector<int>& arr, int target){  
    int n = arr.size();  // Time complexity: O(nm)
    int m = target;      // space complexity; O(nm)+stack
    dp.resize(n+5,vector<int>(m+5,-1));
    return func(arr,0,target);
}

