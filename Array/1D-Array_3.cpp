#include<bits/stdc++.h>
using namespace std;

void display_vector(vector<int> v);
void initialize_vector(vector<int> &v);
void initialize_vector(vector<int> &v, int size);
void display(int a[], int size);

int main(){
    
//******************************************************************************************************************//

    // vector<int> v;
    // int zeros = 0;
    // initialize_vector(v);
    // display_vector(v);
    // for(int i=0; i<v.size(); i++){
    //     if(v[i] == 0){
    //         zeros++;
    //     }
    // }
    // for(int i=0; i<v.size(); i++){
    //     if(i < zeros){
    //         v[i] = 0;
    //     }
    //     else{
    //         v[i] = 1;
    //     }
    // }
    // display_vector(v);

//******************************************************************************************************************//

    // vector<int> v;
    // initialize_vector(v);
    // display_vector(v);
    // int i=0;
    // int j=v.size()-1;
    // while(i<j){
    //     if((v[i] == 1) && (v[j] == 0)){
    //         swap(v[i],v[j]);
    //         i++;
    //         j--;
    //     }
    //     if(v[i] == 0){
    //         i++;
    //     }
    //     if(v[j]== 1){
    //         j--;
    //     }
    // }
    // cout<<"Sorted array: ";
    // display_vector(v);

//******************************************************************************************************************//

    // int arr[8] = {1,2,-3,4,-5,-6,7,-8};
    // display(arr,8);
    // int i=0;
    // int j=7;
    // while(i<j){
    //     if((arr[i] > 0) && (arr[j] < 0)){
    //         swap(arr[i],arr[j]);
    //         i++;
    //         j--;
    //     }
    //     if(arr[i] < 0){
    //         i++;
    //     }
    //     if(arr[j] > 0){
    //         j--;
    //     }
    // }
    // display(arr,8);

//******************************************************************************************************************//

    // int arr[6] = {2,0,2,1,1,0};
    // display(arr,6);
    // int zeros = 0;
    // int ones = 0;
    // int twos = 0;
    // for(int i=0; i<6; i++){
    //     if(arr[i] == 0){
    //         zeros++;
    //     }
    //     else if(arr[i] == 1){
    //         ones++;
    //     }
    //     else{
    //         twos++;
    //     }
    // }
    // for(int i=0; i<6; i++){
    //     if(i<zeros){
    //         arr[i] = 0;
    //     }
    //     else if(i<(zeros+ones)){
    //         arr[i] = 1;
    //     }
    //     else{
    //         arr[i] = 2;
    //     }
    // }
    // display(arr,6);

//******************************************************************************************************************//

    // // int arr[] = {2,0,2,1,0,1};
    // int arr[] = {0,0,2,1,2,1};
    // int n = 6;
    // int low = 0;
    // int mid = 0;
    // int high = n-1;
    // display(arr,6);
    // while(mid < high){
    //     if(arr[mid] == 2){
    //         swap(arr[high],arr[mid]);
    //         high--;
    //     }
    //     if(arr[mid] == 0){
    //         swap(arr[low],arr[mid]);
    //         low++; mid++;
    //     }
    //     if(arr[mid] == 1){
    //         mid++;
    //     }
    // }
    // display(arr,6);

//******************************************************************************************************************//

    // vector<int> v1,v2;
    // cout<<"Initialize vector-1: ";
    // initialize_vector(v1,4);
    // cout<<"Initialize vector-2: ";
    // initialize_vector(v2,5);
    // display_vector(v1);
    // display_vector(v2);

    // vector<int> v(9);
    // int i=0;
    // int j=0;
    // int k=0;
    // while(i<v1.size() && j<v2.size()){
    //     if(v1[i] < v2[j]){
    //         v[k] = v1[i];
    //         i++;
    //         // k++;  redundancy
    //     }
    //     else{
    //         v[k] = v2[j];
    //         j++;
    //         // k++;  redundance
    //     }
    //     k++; // no redundancy
    // }
    // if(i == v1.size()){
    //     while(j<v2.size()){
    //         v[k] = v2[j]; 
    //         k++;
    //         j++;
    //     }
    // }
    // if(j == v2.size()){
    //     while(i<v1.size()){
    //         v[k] = v1[i]; 
    //         k++;
    //         i++;
    //     }
    // }
    // display_vector(v);

//******************************************************************************************************************//

    // vector<int> v1,v2;
    // cout<<"Initialize vector-1: ";
    // initialize_vector(v1,4);
    // cout<<"Initialize vector-2: ";
    // initialize_vector(v2,5);
    // display_vector(v1);
    // display_vector(v2);

    // vector<int> v(9);
    // int i=v1.size()-1;
    // int j=v2.size()-1;
    // int k=v.size()-1;
    // while(i>=0 && j>=0){
    //     if(v1[i] < v2[j]){
    //         v[k] = v2[j];
    //         j--;
    //     }
    //     else{
    //         v[k] = v1[i];
    //         i--;
    //     }
    //     k--;
    // }
    // if(i<0){
    //     while(j>=0){
    //         v[k] = v2[j];
    //         j--;
    //         k--;
    //     }
    // }
    // if(j<0){
    //     while(i>=0){
    //         v[k] = v1[i];
    //         i--;
    //         k--;
    //     }
    // }
    // display_vector(v);

//******************************************************************************************************************//

    // vector<int> v1;
    // v1.push_back(1); v1.push_back(2); v1.push_back(3); v1.push_back(0); v1.push_back(0); v1.push_back(0);
    // int n = v1.size();
    // display_vector(v1);

    // vector<int> v2;
    // v2.push_back(1); v2.push_back(2); v2.push_back(3); 
    // int m = v2.size();
    // display_vector(v2);

    // // int i=v1.size()-1-(v1.size()/2), j=v2.size()-1, k=v1.size()-1;
    // int i=v1.size()-1-v2.size(), j=v2.size()-1, k=v1.size()-1;         // it will ne more better 
    // while(i>=0 && j>=0){
    //     if(v1[i] < v2[j]){
    //         v1[k] = v2[j];
    //         j--; k--;
    //     }
    //     else{
    //         v1[k] = v1[i];
    //         i--; k--;
    //     }
    // }
    // if(i<0){
    //     while(j>=0){
    //         v1[k] = v2[j];
    //         j--; k--;
    //     }
    // }
    // if(j<0){
    //     while(i>=0){
    //         v1[k] = v1[i];
    //         i--; k--;
    //     }
    // }
    // display_vector(v1);

//******************************************************************************************************************//

//    vector<int> v;
//     initialize_vector(v);
//     int n = v.size();
//     int idx = -1;
//     for(int i=n-1; i>0; i--){
//         if(v[i-1] < v[i]){
//             idx = i-1;
//             break;
//         }
//     }
//     if(idx == -1){
//         reverse(v.begin(),v.end());
//     }
//     else{
//         reverse(v.begin()+idx+1,v.end());
//         for(int i=1; i<n; i++){
//             if(v[idx] < v[idx+i]){
//                 swap(v[idx],v[idx+i]);
//                 break;
//             }
//         }
//     }
//     display_vector(v);

//******************************************************************************************************************//

    // Trapping rain water problem  

//******************************************************************************************************************//

    return 0;
}

void display_vector(vector<int> v){
    cout<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void initialize_vector(vector<int> &v){
    cout<<"Enter the number of element in the vector: ";
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
}

void initialize_vector(vector<int> &v, int size){
    for(int i=0; i<size; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
}

void display(int a[], int size){  
    for(int i=0; i<size; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

