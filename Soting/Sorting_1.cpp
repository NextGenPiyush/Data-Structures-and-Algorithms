#include<bits/stdc++.h>
using namespace std;

int main(){

//***************************************************************************************************************//

    vector<int> v = {5,3,1,4,2,-9,0,10,-45,-30,67};        // Bubble sort 
    int n = v.size();
    for(int i=0; i<n; i++) cout<<v[i]<<" "; cout<<endl;
    // sort(v.begin(),v.end()); // in inbuilt sorting the time complexity will be: O(nlogn)

    for(int i=0; i<n-1; i++){            // max no of swapping = max no of operations = n(n-1)/2 in worst case 
        bool flag = false;               // where n is the size of the given array 

        // *******************************  Method_1 ******************************* //
        for(int j=0; j<n-1-i; j++){    // use j<n-1-i for more optimization
            if(v[j] > v[j+1]){         // stable sorting in ascending order
            // if(v[j] >= v[j+1]){           // unstable sorting in ascending order
                swap(v[j],v[j+1]);      // sorting start from starting of the array
                flag = true;              
            }                             
        }                              // Space complexity: O(1)

        // *******************************  Method_2 ******************************* //
        // for(int j=0; j<n-1-i; j++){    
        //     if(v[j] < v[j+1]){         // sorting in descending order
        //         swap(v[j],v[j+1]);     // sorting start from starting of the array
        //         flag = true;             
        //     }                           // Time Complexity: O(n^2) in average and worst case   
        // }                               // Time Complexity: O(n) in best case 

        // *******************************  Method_3 ******************************* //
        // for(int j=n-1; j>=i+1; j--){    
        //     if(v[j] > v[j-1]){         // sorting in ascending order
        //         swap(v[j],v[j-1]);     // sorting start from ending of the array
        //         flag = true;             
        //     }                    // best case: array already sorted, them in one traversal flag remian false           
        // }                        // that's why loop break (Time complexity: O(n))

        // *******************************  Method_4 ******************************* //
        // for(int j=n-1; j>=i+1; j--){    
        //     if(v[j] < v[j-1]){         // sorting in descending order
        //         swap(v[j],v[j-1]);     // sorting start from ending of the array
        //         flag = true;             
        //     }                              
        // }

        if(flag == false) break;  // is means no swapping, array is already sorted, no need to perform further iterations
    }

    for(int i=0; i<n; i++) cout<<v[i]<<" ";   // array is sorted now  

//***************************************************************************************************************//

    // string s = "AZYZXBYDXJK";    // Sort a String in decreasing order of values
    // string str;                  // associated after removal of values smaller than X
    // for(int i=0; i<s.length(); i++) if(s[i] >= 'X') str.push_back(s[i]);
    // cout<<s<<endl;
    // cout<<str<<endl;
    // int n = str.length();
    // for(int i=0; i<n-1; i++){                // Bubble Sorting 
    //     bool flag = false;
    //     for(int j=n-1; j>=i+1; j--){         // here we have start checking from the end 
    //         // if(str[j] > str[j-1]){        // sorting will be done in decreasing order
    //         if(str[j] < str[j-1]){           // sorting will be done in ascending order order
    //             swap(str[j],str[j-1]);
    //             flag = true;
    //         }
    //     }
    //     if(flag == false) break;
    // }  
    // cout<<str<<endl;

//***************************************************************************************************************//

    // int arr[] = {5,0,1,2,0,0,4,0,3};     // Push zeroes to end while maintaining the
    // int n = sizeof(arr)/sizeof(arr[0]);  // relative order of other elements.
    // for(int i=0; i<n-1; i++){
    //     bool flag = true;
    //     for(int j=0; j<n-1-i; j++){
    //         if(arr[j] == 0 && arr[j+1] != 0){   // here in this question we will only change condition 
    //             swap(arr[j],arr[j+1]);          // moving zeros to the end without breaking relative order of the array
    //             flag = false;
    //         }
    //     }
    //     if(flag == true) break;  // it means all the zeros are at end and no need to perform further iterations
    // }
    // for(int i=0; i<n; i++) cout<<arr[i]<<" ";  // all the zeros are at end without disturbing the relative order

//***************************************************************************************************************//

    // can we write bubble sort code using recursion? if yes then try to implemet code.

//***************************************************************************************************************//

    // Check if the given array is almost sorted. (elements are at-most one position away)

//***************************************************************************************************************//


    return 0;
}

