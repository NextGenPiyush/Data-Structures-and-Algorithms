#include<bits/stdc++.h>
using namespace std;

int min_value_1(int arr[], int n, int idx);
int min_value_2(int arr[], int n);
int min_value_3(int arr[], int n);
int sum_1(int arr[], int n);
int sum_2(int arr[], int n, int idx);
int find_ele(int arr[], int n, int idx, int k);
void reverse_order(int arr[], int n);
void helper(vector<vector<int>> &v, vector<int> ans, vector<int> arr, int idx);
void helper_2(vector<vector<int>> &v, vector<int> &ans, vector<int> arr, int idx);
vector<vector<int>> storing_subsets(vector<int> arr);  // retunr 2D vector
vector<vector<int>> subset_with_duplicate(vector<int> arr);
void helper_3(vector<int> arr, vector<vector<int>> &v, vector<int> &temp, int idx);

int main(){

//*******************************************************************************************************************//

    // // int arr[] = {100,240,30,64,58,64,75,58,94,100};
    // int arr[] = {100,240,-30,64,58,-64,75,58,94,-100};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // cout<<"Minimum element of the array: "<<min_value_1(arr,n,0)<<endl;
    // cout<<"Minimum element of the array: "<<min_value_2(arr,n)<<endl;
    // cout<<"Minimum element of the array: "<<min_value_3(arr,n)<<endl;

//*******************************************************************************************************************//

    // int arr[] = {1,2,3,4,5,6,7,8,9,10};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // cout<<"Sum of all the elements in the array: "<<sum_1(arr,n)<<endl;
    // cout<<"Sum of all the elements in the array: "<<sum_2(arr,n,0)<<endl;

//*******************************************************************************************************************//

    // int arr[] = {1,2,3,4,5,6,7,8,9,10};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int k;
    // cout<<"Enter element you want to search: ";
    // cin>>k;
    // if(find_ele(arr,n,0,k) == -1){
    //     cout<<"Element is absent in the array"<<endl;
    // }
    // else{
    //     cout<<"Element is present at "<<find_ele(arr,n,0,k)<<" idex in the array"<<endl;
    // }

//*******************************************************************************************************************//

    // int arr[] = {1,2,3,4,5,6,7,8,9,10};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // cout<<"printing in the actuall order: "<<endl;
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl; 
    // cout<<"printing in the reverse order:"<<endl;
    // reverse_order(arr,n);

//*******************************************************************************************************************//

    // vector<int> arr = {1,2,3};
    // vector<vector<int>> v = storing_subsets(arr);
    // for(int i=0; i<v.size(); i++){
    //     cout<<"[";
    //     for(int ele : v[i]){
    //         cout<<ele;
    //     }
    //     cout<<"]"<<endl;
    // }

//*******************************************************************************************************************//

    // vector<int> arr = {1,1,2};
    // vector<vector<int>> v = subset_with_duplicate(arr);
    // for(int i=0; i<v.size(); i++){
    //     cout<<"[";
    //     for(int ele : v[i]){
    //         cout<<ele;
    //     }
    //     cout<<"]"<<endl;
    // }
    
//*******************************************************************************************************************//

    return 0;
}

int min_value_1(int arr[], int n, int idx){  // if we use vector then there is no need for passing size of the array
    static int min_ele = INT_MAX;    // we can also do it by passing refference
    if(idx == n){
        return min_ele;
    }
    min_ele = min(min_ele,arr[idx]);
    return min_value_1(arr,n,idx+1);
}

int min_value_2(int arr[], int n){
    static int min_ele = INT_MAX;
    if(n < 0){
        return min_ele;
    }
    min_ele = min(min_ele,arr[n-1]);
    return min_value_2(arr,n-1);
}

int min_value_3(int arr[], int n){
    static int min_ele = arr[0];
    if(n < 0){
        return min_ele;
    }
    min_ele = min(arr[n-1],min_value_3(arr,n-1));
}

int sum_1(int arr[], int n){  // we can also do it by passing int idx;
    static int ele_sum;  // automatically intialize to zero
    if(n == 0) return ele_sum;
    ele_sum += arr[n-1]; 
    return sum_1(arr,n-1); 
}

int sum_2(int arr[], int n, int idx){
    if(idx == n-1) return arr[idx];
    return arr[idx] + sum_2(arr,n,idx+1);
}

int find_ele(int arr[], int n, int idx, int k){
    if(idx == n) return -1;
    if(arr[idx] == k)  return idx;
    return find_ele(arr,n,idx+1,k);
}

void reverse_order(int arr[], int n){    // can also be done by passing int idx;
    if(n < 1) return;
    cout<<arr[n-1]<<" ";
    reverse_order(arr,n-1);
}

void helper(vector<vector<int>> &v, vector<int> ans, vector<int> arr, int idx){
    if(idx == arr.size()){
        v.push_back(ans);
        return;
    }
    helper(v,ans,arr,idx+1);
    ans.push_back(arr[idx]);
    helper(v,ans,arr,idx+1);
}

void helper_2(vector<vector<int>> &v, vector<int> &ans, vector<int> arr, int idx){    // here ans is passed by refference
    if(idx == arr.size()){
        v.push_back(ans);
        return;
    }
    helper_2(v,ans,arr,idx+1);
    ans.push_back(arr[idx]);
    helper_2(v,ans,arr,idx+1);
    ans.pop_back();               // also dry run this code after commenting the ans.pop+back()
}

vector<vector<int>> storing_subsets(vector<int> arr){   // retunr 2D vector
    sort(arr.begin(),arr.end());
    vector<vector<int>> v;
    vector<int> ans;
    // helper(v,ans,arr,0);
    helper_2(v,ans,arr,0);
    return v;
}

// you can try to implement method for duplicate char in the string 
vector<vector<int>> subset_with_duplicate(vector<int> arr){ 
    vector<vector<int>> v;
    vector<int> temp;
    sort(arr.begin(),arr.end());
    helper_3(arr,v,temp,0);
    return v;
}

void helper_3(vector<int> arr, vector<vector<int>> &v, vector<int> &temp, int idx){      // space complexity O(2^n)
    v.push_back(temp);                                                                   // time complexity O(2^n)
    for(int i=idx; i<arr.size(); i++){
        if(i!=idx && arr[i]==arr[i-1]) continue;
        temp.push_back(arr[i]);
        helper_3(arr,v,temp,i+1);
        temp.pop_back();
    }
}