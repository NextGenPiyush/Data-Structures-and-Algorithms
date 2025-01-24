#include<bits/stdc++.h>
using namespace std;

vector<int> missing_num(int arr[], int n);  // Leetcode-448
int first_missing_positive(vector<int> &v); // Leetcode-41

int main(){

//********************************************************************************************************************//

    // int arr[] = {6,4,5,1,3,2}; // contain element from 1 to n 
    // int n = sizeof(arr)/sizeof(arr[0]);
    // for(int i=0; i<n; i++) cout<<arr[i]<<" ";  cout<<endl;
    // int i=0;
    // while(i<n){                             // Time complexity: O(n)
    //     if(arr[i] == i+1) i++;                // cyclic sort algorithem
    //     else swap(arr[i],arr[arr[i]-1]);      // maximum to maximum (n-1) swaps as atmost n-1 numbers will be swaped
    // }                                         // in worst case 
    // cout<<"After sorting: "<<endl;
    // for(int i=0; i<n; i++) cout<<arr[i]<<" ";  cout<<endl;

//********************************************************************************************************************//

//***************************************** method-1 *****************************************//
    // int arr[] = {0,1,4,5,2,3,7};  // (Leetcode-268)
    // int n = sizeof(arr)/sizeof(arr[0]);
    // vector<bool> v(n+1,false);          // we have used extra space here space complexity = O(n)
    // for(int i=0; i<n; i++){             // but we have only traversed one time in the array 
    //     int ele = arr[i];               // Time complexity: O(n)
    //     cout<<arr[i]<<" ";  // we are using this for printing array only 
    //     v[ele] = true;
    // }
    // cout<<endl;
    // for(int i=0; i<=n; i++) if(v[i] == false) cout<<"Missing element in the array from 0 to n: "<<i<<endl;

//***************************************** method-2 *****************************************//
    // int arr[] = {0,1,4,5,2,3,7};  
    // int n = sizeof(arr)/sizeof(arr[0]);  
    // int sum = 0;      // sum of number present in the array                         
    // int tot_sum = 0;      // sum of all the numbers from zero to n+1                     
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";              // we can also calculate tot_sum = (n*(n+1))/2
    //     sum += arr[i];                   // space complexity O(1), no extra space is used
    //     tot_sum += i+1;
    // }
    // cout<<endl;
    // cout<<"Missing number from array: "<<tot_sum-sum<<endl;  // difference wilL return the missing number

//***************************************** method-3 *****************************************//
    // // int arr[] = {9,6,4,2,3,5,7,0,1}; // contain number from 0 to n
    // int arr[] = {8,6,4,2,3,5,7,0,1}; // contain number from 0 to n
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int i=0;                                                         // time complexity O(n)
    // bool flag = false;                                               // space complexity O(1)
    // while(i<n){
    //     if(arr[i] != i && arr[i] != n) swap(arr[i],arr[arr[i]]);
    //     else i++;  // arr[i]==i or arr[i]==n
    // }
    // for(int i=0; i<n; i++){       // we have traversed two time, one for sorting and one for checking 
    //     if(arr[i] != i){
    //         cout<<"Missing element in the array: "<<i<<endl;
    //         flag = true;
    //         break;
    //     } 
    // }
    // if(flag == false) cout<<"Missing element in the array: "<<n<<endl;

//********************************************************************************************************************//

//************************************** method-1 **************************************//
    // int arr[] = {3,1,3,4,2};  // one duplicate element only (Leetcode-287)
    // int n = sizeof(arr)/sizeof(arr[0]);
    // for(int i=0; i<n; i++) cout<<arr[i]<<" ";  cout<<endl;  // printing array
    // int i = 0;
    // while(1){                    // here we are modifying array although the Time complexuty: O(n)
    //     if(arr[i] != arr[arr[i]]) swap(arr[i],arr[arr[i]]);
    //     else{
    //         cout<<"Duplicate element in the array: "<<arr[i]<<endl;  // or we can also write 'i' in place of'arr[i]'
    //         break;
    //     }
    // }

//************************************** method-2 **************************************//
    // int arr[] = {3,1,4,4,2};   // Leetcode-287
    // int n = sizeof(arr)/sizeof(arr[0]);  
    // int sum = 0;                  // sum of number present in the array                         
    // int tot_sum = 0;              // sum of all the numbers from zero to n+1                     
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";              // we can also calculate tot_sum = (n*(n+1))/2
    //     sum += arr[i];                   // space complexity O(1), no extra space is used
    //     tot_sum += i+1;                 // here we are not modifying the array although the Time complexity: O(n)
    // }
    // cout<<endl;
    // cout<<"Duplicate element in the array: "<<n-(tot_sum-sum)<<endl;

//********************************************************************************************************************//

    // int arr[] = {4,3,2,7,8,2,3,1};         // element containing 1 to n elemnts find all missing number (Leetcode-448)
    // int n = sizeof(arr)/sizeof(arr[0]);
    // for(int i=0; i<n; i++) cout<<arr[i]<<" ";  cout<<endl;
    // vector<int> v = missing_num(arr,n);
    // cout<<"Missing elements from the array: "<<endl;
    // for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";  cout<<endl;

//********************************************************************************************************************//

    vector<int> v = {-1,2,5,0};  // Leetcode-41    
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";  cout<<endl;
    cout<<"First missing positive element in the array: "<<first_missing_positive(v)<<endl;

    cout<<"HelloWorld"<<endl;

//********************************************************************************************************************//

    return 0;
}

vector<int> missing_num(int arr[], int n){   // Leetcode-448
    vector<int> v;   
    int i = 0;
    while(i<n){       // Time complexity: O(n) ans space complexity: O(1)
        if(arr[i] != arr[arr[i]-1]) swap(arr[i],arr[arr[i]-1]);
        else i++;    // but we have modified our array  
    }
    for(int i=0; i<n; i++) if(i+1 != arr[i]) v.push_back(i+1);
    return v;   // there is an another method in which we will not modify the array (by the method of negative marking)
}

int first_missing_positive(vector<int> &v){  // Leetcode-41
    int n = v.size();   // we can easily solve it by using extra visit vector but then space complexity will be O(n)
    int i = 0;              // and Time cmplexity; O(n)
    while(i<n){
        if(v[i]<=0) i++;
        else if(v[i]>n || v[i]==i+1 || v[v[i]-1]==v[i]) i++;   // but here the space complexity: O(1)
        else swap(v[i],v[v[i]-1]); 
    }
    for(int i=0; i<n; i++) if(v[i]!=i+1) return i+1;
    return n+1;
}