#include<bits/stdc++.h>
using namespace std;

void display(vector<int> &arr){
    if(arr.size() == 0){
        cout<<"{}"<<endl;
        return;
    }
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<endl;
}

void func(vector<int> &arr, int idx, int sum, int &target, vector<int> &sub);
bool get_only_one(vector<int> &arr, int idx, int sum, int &target, vector<int> &sub);
int no_of_subsequence(vector<int> &arr, int idx, int sum, int &target);

int main(){

    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements:"<<endl;
    for(int i=0; i<n; i++) cin>>arr[i];
    int target;
    cout<<"Enter your target sum: ";
    cin>>target;
    vector<int> sub;

    cout<<"no of subsequence: "<<no_of_subsequence(arr,0,0,target)<<endl;
    func(arr,0,0,target,sub);

    // get_only_one(arr,0,0,target,sub);  // print only one required subsequence


    return 0;
}

void func(vector<int> &arr, int idx, int sum, int &target, vector<int> &sub){
    if(sum == target){
        display(sub);
        return;
    }
    if(idx == arr.size() || sum > target) return; // sum>target is for only if there are +ive elements in array
    sub.push_back(arr[idx]);
    func(arr,idx+1,sum+arr[idx],target,sub);
    sub.pop_back();
    func(arr,idx+1,sum,target,sub);
}

bool get_only_one(vector<int> &arr, int idx, int sum, int &target, vector<int> &sub){
    if(sum == target){  // this function print only one subsequence with target sum
        display(sub);
        return true;
    }
    if(idx == arr.size() || sum > target) return false; 
    sub.push_back(arr[idx]);
    if(get_only_one(arr,idx+1,sum+arr[idx],target,sub)) return true;
    sub.pop_back();
    if(get_only_one(arr,idx+1,sum,target,sub)) return true;
    return false;
}

int no_of_subsequence(vector<int> &arr, int idx, int sum, int &target){
    if(sum == target) return 1;
    if(idx == arr.size() || sum > target) return 0;
    return no_of_subsequence(arr,idx+1,sum+arr[idx],target) + no_of_subsequence(arr,idx+1,sum,target);
}