#include<bits/stdc++.h>
using namespace std;

float min(float a, float b){
    if(a<b) return a;
    return b;
}
float max(float a, float b){
    if(a>b) return a;
    return b;
}

int main(){

//******************************************************************************************************************//

    // vector<int> v = {2,2,1,1,1,2,2};   // Leetcode-169 
    // int n = v.size();
    // // for(int i=0; i<n; i++){
    // //     int count = 1;
    // //     for(int j=i+1; j<n; j++){     // this is not a good method as time complexity: O(n^2)
    // //         if(v[i] == v[j]){
    // //             count++;               // there is an another algorithm in time complexity: O(n) 
    // //         }                          // which is called as voting algorithm
    // //     }
    // //     if(count>(n/2)){
    // //         cout<<v[i]<<" is the most occuring element in the array "<<endl;
    // //         break;
    // //     }
    // // }
    // sort(v.begin(),v.end());         // Time complexity: O(nlogn)
    // cout<<v[n/2]<<" is the most occuring element in the array"<<endl; // element will occure more than n/2

//******************************************************************************************************************//

// Given an array with N distinct elements, convert the given array to a form where all elements are in the range 
// from 0 to N-1. The order of elements is the same, i.e., 0 is placed in the place of the smallest element, 1 is placed 
// for the second smallest element, ... N-1 is placed for the largest element.

    //************************************** case-1 **************************************//
    // vector<int> v = {19,12,23,8,16};   // valid only for positive numbers
    // int n = v.size();
    // for(int i=0; i<n; i++) cout<<v[i]<<" ";  cout<<endl;   // printing the original vector 
    // for(int i=0; i>=(-n+1); i--){
    //     int min = INT_MAX;
    //     int index = -1;
    //     for(int j=0; j<n; j++){             // Time complexity: O(n^2)
    //         if(v[j]<min && v[j]>0){         // space complexity: O(1)
    //             min = v[j];
    //             index = j;
    //         }
    //     }                // we have written negative index so that they cannot again become min element of the vector  
    //     v[index] = i;    // re-writing the negative number at given index
    // }
    // for(int i=0; i<n; i++){
    //     v[i] = v[i]*(-1);   // make sure to make elements of vector positive number before printing 
    //     cout<<v[i]<<" ";
    // }

    //************************************** case-2 **************************************//
    // vector<int> v = {-19,-12,-23,-8,-16};   // valid for only negative numbers
    // int n = v.size();
    // for(int i=0; i<n; i++) cout<<v[i]<<" ";  cout<<endl;   // printing the original vector 
    // for(int i=0; i<n; i++){
    //     int min = INT_MAX;                 // Time complexity: O(n^2)
    //     int index = -1;                    // space comeplxity: O(1)
    //     for(int j=0; j<n; j++){
    //         // if(min>v[j] && v[j]<0){    
    //         if(min>v[j]){                 // because updated element will be greater than and equal to zero
    //             min = v[j];              // it means check only for negative number to find minimum
    //             index = j;  
    //         }
    //     }
    //     v[index] = i;   // no need to re-write with negative index as positive number among negative can't be minimum 
    // }
    // for(int i=0; i<n; i++) cout<<v[i]<<" ";

    //************************************** case-3 **************************************//
    // vector<int> v1 = {-19,12,-23,8,-16};  // valid for all type of entries
    // // vector<int> v1 = {19,12,23,8,16};  
    // // vector<int> v1 = {-19,-12,-23,-8,-16}; 
    // int n = v1.size();
    // for(int i=0; i<n; i++) cout<<v1[i]<<" ";  cout<<endl;   // printing the original vector 
    // vector<int> v2(n,0);    // visited vector it means visited index will be updates an one
    // for(int i=0; i<n; i++){
    //     int min = INT_MAX;                  // Time complexity: O(n^2)
    //     int index = -1;                     // space complexity: O(n)
    //     for(int j=0; j<n; j++){
    //         if(v2[j]==0 && min>v1[j]){   // cheching if the index is visited or not 
    //             min = v1[j];
    //             index = j;
    //         }
    //     }
    //     v1[index] = i;    // as soon as we update in original vector, update the visited vector
    //     v2[index] = 1;    // so that that index cant be checked again
    // }    // now you have the choise either you update number by negative or posotive as we will check visited vector 
    // for(int i=0; i<n; i++) cout<<v1[i]<<" ";  cout<<endl; 

    //************************************** case-3 **************************************//
    // we can also solve this with hashmaps, try to implement later
        // time complexity: O(nlogn)
        //  Space complexity: O(n)

//******************************************************************************************************************//

    // vector<int> greed = {7,11,15};     // Leetcode-455
    // vector<int> cokkie_size = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};  
    // sort(greed.begin(),greed.end());
    // sort(cokkie_size.begin(),cokkie_size.end());
    // int count = 0; int i = 0; int j = 0;
    // while(i<greed.size() && j<cokkie_size.size()){  // loop run for minimum of size of both the vectors
    //     if(greed[i] <= cokkie_size[j]){ count++;  i++;  j++; }   // most optimized approach
    //     else j++;
    // }
    // cout<<count<<" childern get their cokkie"<<endl;

//******************************************************************************************************************//

    // :Given an array, arr[] containing ‘n’ integers, the task is to find an integer (say K) such that after 
    // replacing each and every index of the array by |ai – K| where ( i ∈ [1, n]), results in a sorted array. 
    // If no such integer exists that satisfies the above condition then return -1.

    // int arr[] = {5,3,10};   // very good question 
    // int arr[] = {5,3,10,6};
    // int arr[] = {5,3,7};
    int arr[] = {5,3,10,3};  // try to think about this case    // this question is more about mathematics 
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";  cout<<endl;

    float kmin = float(INT_MIN), kmax = float(INT_MAX);
    bool flag = true;
    for(int i=0; i<n-1; i++){
        if(arr[i] >= arr[i+1]) kmin = max(kmin,(arr[i]+arr[i+1])/2.0);  // try to implement the mathematical operation
        else kmax = min(kmax,(arr[i]+arr[i+1])/2.0);                    // using pen and paper
        if(kmin>kmax){
            flag = false;
            break;
        }
    }

    if(flag == false) cout<<"value of k is not possible"<<endl;
    else if(kmin == kmax){
        if(kmin-int(kmin) == 0) cout<<"there is only one value of k: "<<kmin<<endl;  // kmin and kmax both are integer
        else cout<<"value of k is not possible"<<endl;
    }
    else{
        if(kmin-int(kmin)>0) kmin = int(kmin) + 1;
        cout<<"Range of k is: ["<<kmin<<","<<int(kmax)<<"]"<<endl;
    }

//******************************************************************************************************************//

    return 0;
}