#include<bits/stdc++.h>
using namespace std;

int main(){

//********************************************************************************************************************//

    int arr[] = {5,3,1,4,2,-9,0,10,-45,-30,67};   // selection sorting (Minimum no of swaps required in this sorting)
    int n = sizeof(arr)/sizeof(arr[0]);           
    for(int ele: arr) cout<<ele<<" "; cout<<endl;  // printing elements before applying selection sort 

    int index = -1;   // Time complexity: O(n^2) in all the average, worst and best case while space complexity: O(1) 

        // ************************** method_1 ************************** //
        // for(int i=0; i<n-1; i++){     // do not run for i=n-1 as last element will be its right position
        // int min_ele = INT_MAX;        // for sorting in ascending order 
        // for(int j=i; j<n; j++){
        //     if(min_ele > arr[j]){      // calculating minimum element in the array 
        //         min_ele = arr[j];
        //         index = j;
        //     }                          // Unstable sorting  
        // }
        // swap(arr[i],arr[index]); // swapping min element with corresponding first element of array in each iteration 
        // // after each iteration elements starts arranging in increasing order from the starting
        // }

        // ************************** method_2 ************************** //
        // for(int i=0; i<n-1; i++){     // do not run for i=n-1 as last element will be its right position
        // int min_ele = INT_MIN;        // for sorting in descending order 
        // for(int j=i; j<n; j++){
        //     if(min_ele < arr[j]){      // calculating maximum element in the array 
        //         min_ele = arr[j];
        //         index = j;
        //     }
        // }
        // swap(arr[i],arr[index]); // swapping max element with corresponding first element of array in each iteration 
        // // after each iteration elements starts arranging in decreasing order from the starting
        // }

        // ************************** method_3 ************************** //
        // for(int i=n-1; i>0; i--){     // do not run for i=0 as last element will be its right position
        // int min_ele = INT_MIN;        // for sorting in ascending order 
        // for(int j=i; j>=0; j--){
        //     if(min_ele < arr[j]){      // calculating maximum element in the array 
        //         min_ele = arr[j];
        //         index = j;
        //     }
        // }
        // swap(arr[i],arr[index]); // swapping max element with corresponding last element of array in each iteration 
        // // after each iteration elements starts arranging in ascending order from the ending
        // }

        // ************************** method_4 ************************** //
        for(int i=n-1; i>0; i--){     // do not run for i=0 as last element will be its right position
        int min_ele = INT_MAX;        // for sorting in descending order 
        for(int j=i; j>=0; j--){
            if(min_ele > arr[j]){      // calculating min element in the array 
                min_ele = arr[j];
                index = j;
            }
        }
        swap(arr[i],arr[index]); // swapping min element with corresponding last element of array in each iteration 
        // after each iteration elements starts arranging in descending order from the ending
        }

    for(int i=0; i<n; i++) cout<<arr[i]<<" "; cout<<endl;

//********************************************************************************************************************//

    // can we write selection sort code using recursion? if yes then try to implemet code.

//********************************************************************************************************************//

    int arr[] = {5,3,1,4,2,0,-9,-10,11};       // Insertion sort
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++) cout<<arr[i]<<" "; cout<<endl;  // Before sorting

    for(int i=1; i<n; i++){          // We can also write like this, it will also have 4 cases but this is not a optimized
        for(int j=i; j>0; j--){      // code as for best case inner loop will run but no swapping will be take place 
            // if(arr[j]<=arr[j-1]) swap(arr[j],arr[j-1]);  // Unstable sorting 
            if(arr[j]<arr[j-1]) swap(arr[j],arr[j-1]);     // stable sorting
            else break;
        }                      // Time complexity: O(n^2) in all 3 cases, but can optimize code 
    }                          // space complexity: O(1)

    // ******************************  method_1 ****************************** //
    for(int i=1; i<n; i++){       // Optimized insertion sort, best case time complexity: O(n)           
        int j = i;                          // sorting in ascending order
        while(j>=1 && arr[j]<arr[j-1]){    
            swap(arr[j],arr[j-1]);        // minimum element keep swaping toward starting position in every iteration
            j--;                       // it means we tries to sort in ascending order from the start
        }
    }        

    // ******************************  method_2 ****************************** //
    // for(int i=1; i<n; i++){
    //     int j = i;                            // sorting in descending order
    //     while(j>=1 && arr[j]>arr[j-1]){   
    //         swap(arr[j],arr[j-1]);        // maximum element keep swaping toward starting position in every iteration
    //         j--;                          // it means we tries to sort in descending order from the start
    //     }
    // }    // In worst case total number of operation and swapping will be n(n-1)/2

    // ******************************  method_3 ****************************** //
    // for(int i=n-2; i>=0; i--){
    //     int j = i;                              // sorting in ascending order
    //     while(j<n-1 && arr[j]>arr[j+1]){   
    //         swap(arr[j],arr[j+1]);           // maximum element keep swaping toward ending position in every iteration
    //         j++;                              // it means we tries to sort in ascending order from the end
    //     }
    // }

    // ******************************  method_4 ****************************** //
    // for(int i=n-2; i>=0; i--){
    //     int j = i;                               // sorting in descending order
    //     while(j<n-1 && arr[j]<arr[j+1]){   
    //         swap(arr[j],arr[j+1]);          // minimum element keep swaping toward ending position in every iteration
    //         j++;                             // it means we tries to sort in descending order from the end
    //     }
    // }

    for(int i=0; i<n; i++) cout<<arr[i]<<" "; cout<<endl;  // After sorting

//********************************************************************************************************************//

    // can we write Insertion sort code using recursion? if yes then try to implemet code.

//********************************************************************************************************************//

    // Given an array of digits (values are from 0 to 9), the task is to find the minimum possible sum of
    // two numbers formed from digits of the array. Please note that all digits of the given array must be
    // used to form the two numbers.

//********************************************************************************************************************//

    return 0;
}
