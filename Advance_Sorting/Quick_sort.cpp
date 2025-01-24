#include<bits/stdc++.h>
using namespace std;

void quick_sort(int arr[], int stidx, int endidx);
int partition(int arr[], int stidx, int endidx);

int quick_select(int arr[], int stidx, int endidx, int k);

int main(){

//********************************************************************************************************************//   

    int arr[] = {5,1,8,2,7,6,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";  cout<<endl;
    quick_sort(arr,0,n-1);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";  cout<<endl;

//********************************************************************************************************************//   

// Write a Program to find Kth smallest element in an array using QuickSort.
    // we can done it using selection sort om Time complexity: O(k*n) and it can also be done by bubble and insertion sort
    // with merge sort Time complexity: O(nlogn)
    // with quick sort Time complexity: O(n) --> average case 

    // int arr[] = {5,1,8,2,7,6,3,4};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int k;
    // for(int i=0; i<n; i++) cout<<arr[i]<<" ";  cout<<endl;
    // quick_sort(arr,0,n-1);
    // for(int i=0; i<n; i++) cout<<arr[i]<<" ";  cout<<endl;
    // cout<<"Enter which smallest number you want: ";
    // cin>>k;
    // cout<<"Answer is: "<<quick_select(arr,0,n-1,k)<<endl;

//********************************************************************************************************************//   

    // can we implement quick sort function without recursion 

//********************************************************************************************************************//   

    return 0;
}

int partition(int arr[], int stidx, int endidx){ 

//************************************ method-1 ************************************// 
    int pivot = arr[(stidx+endidx)/2];  // Randomized pivot point 
    // int pivot = arr[stidx]; // we can take another element as pivot element but make sure not to visit the element
    int count = 0;       // in the for loop while calculating smaller elements in the array 
    
    // for(int i=stidx+1; i<=endidx; i++) if(arr[i] <= pivot) count++;   // hence loop will start from i=stidx+1 
    // int pivotidx = count+stidx;                                 
    // swap(arr[stidx], arr[pivotidx]);

    for(int i=stidx; i<=endidx; i++){      // Randomized pivot element reduce the time complexity in worst case
        if(i == (stidx+endidx)/2) continue;            // Time complexity: O(nlogn)
        if(arr[i] <= pivot) count++;           // space complexity: O(1) in partition
    } 
    int pivotidx = count+stidx;   
    swap(arr[(stidx+endidx)/2],arr[pivotidx]);
    
    int i = stidx, j = endidx;
    while(i<pivotidx && j>pivotidx){
        if(arr[i]>pivot && arr[j]<=pivot) swap(arr[i++], arr[j--]);  // we want the same element to the left of pivot
        if(arr[i]<=pivot) i++;                    // that's why we have taken '=' in the if  condition
        if(arr[j]>pivot) j--;
    }
    return pivotidx;    // also try to implement this method if we take last element of vector as pivot element

//************************************ method-2 ************************************// 
    // int pivot = arr[stidx];     // here is the another approach of finding the pivot index in the partition method 
    // int i = stidx, j = endidx;   // here I have choosen the first element as pivot element
    // while(i<j){
    //     while(arr[i] <= pivot && i <= endidx-1) i++;   
    //     while(arr[j] > pivot && j >= stidx+1) j--;
    //     if(i<j) swap(arr[i],arr[j]);
    // }
    // swap(arr[stidx],arr[j]);
    // return j;

//************************************ method-3 ************************************// 
    // int pivot = arr[endidx];     
    // int i = stidx, j = endidx;   // here I have choosen the last element as pivot element
    // while(i<j){
    //     while(arr[i] < pivot && i <= endidx-1) i++;   
    //     while(arr[j] >= pivot && j >= stidx+1) j--;
    //     if(i<j) swap(arr[i],arr[j]);
    // }
    // swap(arr[endidx],arr[i]);
    // return i;
}
void quick_sort(int arr[], int stidx, int endidx){  // internal sorting using variation of quick sort 
    if(stidx>=endidx) return;                       // Quick sort is an unstable sorting algorithem 
    int pivotidx = partition(arr,stidx,endidx);         // Time complexity: O(nlogn)  --> average case 
    quick_sort(arr,stidx,pivotidx-1);            // Time complexity: O(n^2)  --> worst case
    quick_sort(arr,pivotidx+1,endidx);                  // space comlexity: O(logn) we can also called it inplace sorting
}   // whenever there is no need of stability we use quick sort because it is faster than seletion sort algorithm


int quick_select(int arr[], int stidx, int endidx, int k){   // try ro solve kth smallest element on leetcode
    // if(stidx>=endidx) return; // no base case required
    int pivotidx = partition(arr,stidx,endidx);  // Tme complexity: O(n)   
    if(pivotidx+1 == k) return arr[pivotidx];   // we pivot+1 is equal to k then we get out kth smallest element 
    if(pivotidx+1 > k) return quick_select(arr,stidx,pivotidx-1,k);   // if pivotidx+1 is greater than call left function 
    else return quick_select(arr,pivotidx+1,endidx,k);  // if pivotidx+1 is smaller than call right function
}   // it can also be solve using heap but extra space used 