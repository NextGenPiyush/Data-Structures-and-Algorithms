#include<bits/stdc++.h>
using namespace std;

void merge_1(vector<int> &v, vector<int> arr1, vector<int> arr2);  // work on two acsending order sorted array
void merge_2(vector<int> &v, vector<int> arr1, vector<int> arr2);  // work on two decsending order sorted array

void merge_sort_1(vector<int> &v);  // sort in acsending order
void merge_3(vector<int> &v, vector<int> arr1, vector<int> arr2);

void merge_sort_2(vector<int> &v);  // sort in descending order
void merge_4(vector<int> &v, vector<int> arr1, vector<int> arr2);

void count_inversion(vector<int> &v, int &count);
int helper(vector<int> a, vector<int> b);

int main(){

//****************************************************************************************************************//

    // vector<int> arr1 = {1,4,5,8};       // sorted vectors in ascending orders
    // vector<int> arr2 = {2,3,6,7,10,12};
    // vector<int> v;  // we have not defined the size so we will use pushback while adding elements in the vector
    // merge_1(v,arr1,arr2);
    // for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";  cout<<endl;        

//****************************************************************************************************************//

    // vector<int> arr1 = {8,5,4,1};   // sorted vectors in decreasing order
    // vector<int> arr2 = {12,10,7,6,3,2};   
    // vector<int> v;   // we have not defined the size so we will use pushback while adding elements in the vector
    // merge_2(v,arr1,arr2);
    // for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";  cout<<endl;                       

//****************************************************************************************************************//

    // int arr[] = {1,3,4,7,5,2,6,10,9,8};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // vector<int> v(arr,arr+n);  // we can convert array into vector 

    // cout<<"Orginal vector: ";
    // for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";  cout<<endl;

    // cout<<"sorted in increasing order: ";
    // merge_sort_1(v);
    // for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";  cout<<endl;

    // cout<<"sorted in decreasing order: ";
    // merge_sort_2(v);
    // for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";  cout<<endl;


//****************************************************************************************************************//

// Two elements of an array a, a[i] and a[j] form an inversion if a[i] > a[j] and i < j. Given an array of integers. 
// Find the Inversion Count in the array. (Count inversion problem)

    // vector<int> v = {5,1,3,0,4,9,6};
    // int count = 0;
    // count_inversion(v,count);
    // cout<<"Number of inversions: "<<count;

//****************************************************************************************************************//

    // can we implement merge sort function without using recursion

//****************************************************************************************************************//

    return 0;
}

void merge_1(vector<int> &v, vector<int> arr1, vector<int> arr2){
// there is an another iterative approach
//*********************************** ascending order ***********************************//
    int i=0, j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i] < arr2[j]) v.push_back(arr1[i++]);
        else v.push_back(arr2[j++]);
    }
    if(j == arr2.size()) while(i < arr1.size()) v.push_back(arr1[i++]);
    if(i == arr1.size()) while(j < arr2.size()) v.push_back(arr2[j++]);

//*********************************** descending order ***********************************//
    // int i=arr1.size()-1, j=arr2.size()-1;
    // while(i>=0 && j>=0){
    //     if(arr1[i] > arr2[j]) v.push_back(arr1[i--]);
    //     else v.push_back(arr2[j--]);
    // }
    // if(i<0) while(j>=0) v.push_back(arr2[j--]);
    // if(j<0) while(i>=0) v.push_back(arr1[i--]);
}

void merge_2(vector<int> &v, vector<int> arr1, vector<int> arr2){

//*********************************** ascending order ***********************************//
    int i=arr1.size()-1, j=arr2.size()-1;
    while(i>=0 && j>=0){
        if(arr1[i] < arr2[j]) v.push_back(arr1[i--]);
        else v.push_back(arr2[j--]);
    }
    if(i<0) while(j>=0) v.push_back(arr2[j--]);
    if(j<0) while(i>=0) v.push_back(arr1[i--]);

//*********************************** descending order ***********************************//
    // int i=0, j=0;
    // while(i<arr1.size() && j<arr2.size()){
    //     if(arr1[i] > arr2[j]) v.push_back(arr1[i++]);
    //     else v.push_back(arr2[j++]);
    // }
    // if(j == arr2.size()) while(i < arr1.size()) v.push_back(arr1[i++]);
    // if(i == arr1.size()) while(j < arr2.size()) v.push_back(arr2[j++]);
}

void merge_sort_1(vector<int> &v){  // this function sort in ascending order 
    int n = v.size();   // this sorting is used in sorting of linked list 
    if(n==1) return;    // base case
          
    int n1 = n/2, n2 = n-n/2;             // Time complexity: O(2nlogn)
    vector<int> a(n1),b(n2);              // space complexity: O(nlogn)
    for(int i=0; i<n1; i++) a[i] = v[i];     // dividing original vector into two new vectors
    for(int i=0; i<n2; i++) b[i] = v[i+n1];

    merge_sort_1(a);    // recursive call
    merge_sort_1(b);    // here remember one thing first problem divided into smaller parts then work done to merge 

    merge_3(v,a,b);  // operation to be performed (for sorting in ascending order)
    a.clear(); b.clear();  // due to this space complexity: O(n)
}
void merge_3(vector<int> &v, vector<int> arr1, vector<int> arr2){
    int i=0, j=0, k=0;
    while(i<arr1.size() && j<arr2.size()){
        // if(arr1[i] < arr2[j]) v[k++] = arr1[i++];  // unstable sort
        if(arr1[i] <= arr2[j]) v[k++] = arr1[i++];  // stable sort
        else v[k++] = arr2[j++];
    }
    if(j == arr2.size()) while(i < arr1.size()) v[k++] = arr1[i++];
    if(i == arr1.size()) while(j < arr2.size()) v[k++] = arr2[j++];
}

void merge_sort_2(vector<int> &v){  //there is another way of doing merge sorting by passing the index of original vectors
    int n = v.size();                // will discuss later in assignment solutions 
    if(n==1) return;     // base case

    int n1 = n/2, n2 = n-n/2;                // Time complexity: O(2nlogn)
    vector<int> a(n1),b(n2);                 // space complexity: O(nlogn)
    for(int i=0; i<n1; i++) a[i] = v[i];      // dividing original vector into two new vectors
    for(int i=0; i<n2; i++) b[i] = v[i+n1];

    merge_sort_2(a);   // recursive call
    merge_sort_2(b);  // here remember one thing first problem divided into smaller parts then work done to merge 

    merge_4(v,a,b);        // operation to be performed (for sorting in descending order)
    a.clear(); b.clear();  // due to this space complexity: O(n)
} 
void merge_4(vector<int> &v, vector<int> arr1, vector<int> arr2){
    int i=0, j=0, k=0;
    while(i<arr1.size() && j<arr2.size()){
        // if(arr1[i] < arr2[j]) v[k++] = arr2[j++];  // unstable sort
        if(arr1[i] <= arr2[j]) v[k++] = arr2[j++];  // stable sort
        else v[k++] = arr1[i++];
    }
    if(j == arr2.size()) while(i < arr1.size()) v[k++] = arr1[i++];
    if(i == arr1.size()) while(j < arr2.size()) v[k++] = arr2[j++];
}

void count_inversion(vector<int> &v, int &count){  // very good approach 
    int n = v.size();       // we can also do it by brute force algorithm in Time complexity: O(n^2) easily
    if(n==1) return;        // Base case
        
    int n1 = n/2, n2 = n-(n/2);        // Time complexity: O(nlogn)
    vector<int> a(n1),b(n2);
    for(int i=0; i<n1; i++) a[i] = v[i];     // copying the elements of originall vector into two sub vectors
    for(int i=0; i<n2; i++) b[i] = v[i+n1];

    count_inversion(a,count);  // recursive approach as in merge sorting 
    count_inversion(b,count);

    count += helper(a,b);  // count is passed by refference so it will keep on increasing
    merge_3(v,a,b);   // merging two sorted arrays
    a.clear();  b.clear();  // make space complexity efficient 
}
int helper(vector<int> a, vector<int> b){
    int count = 0, i = 0, j = 0;
    while(i<a.size() && j<b.size()){
        if(a[i]>b[j++]) count += (a.size()-i);   // is a[i] > b[i] then a[i+1],a[i+2]... will be greater 
        else i++;
    }
    return count;
}
