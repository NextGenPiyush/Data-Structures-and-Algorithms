#include<bits/stdc++.h>
using namespace std;

void display(vector<int> &arr){  // Time complexity: O(n)
    if(arr.size() == 0){
        cout<<"{}";
        return;
    }
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<endl;
}

void print_subsequence(vector<int> &arr, int idx, vector<int> &sub){
    if(idx == arr.size()){
        display(sub);
        return;
    }
    sub.push_back(arr[idx]);         // Time complexity: O(2^n * n) 
    print_subsequence(arr,idx+1,sub);  // space complexity: O(n) 
    sub.pop_back();   // Backtraking            
    print_subsequence(arr,idx+1,sub);
}

int main(){

    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements:"<<endl;
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<"Printing all the subsequence if the given array: "<<endl;
    vector<int> sub;
    print_subsequence(arr,0,sub);



    return 0;
}