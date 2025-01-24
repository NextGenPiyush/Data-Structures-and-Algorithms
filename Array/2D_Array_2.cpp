#include<bits/stdc++.h>
using namespace std;
int main(){

//****************************************************************************************************************//  

    // int m1,n1,m2,n2;
    // cout<<"Enter no of rows for matrix-1: "; cin>>m1;
    // cout<<"Enter no of columns for matrix-1: "; cin>>n1;
    // int arr1[m1][n1];
    // for(int i=0; i<m1; i++){
    //     for(int j=0; j<n1; j++){
    //         cin>>arr1[i][j];
    //     }
    // }
    // cout<<"Enter no of rows for matrix-2: "; cin>>m2;
    // cout<<"Enter no of columns for matrix-2: "; cin>>n2;
    // int arr2[m2][n2];
    // for(int i=0; i<m2; i++){
    //     for(int j=0; j<n2; j++){
    //         cin>>arr2[i][j];
    //     }
    // }

    // if(n1 == m2){
    //     int arr[m1][n2];
    //     for(int i=0; i<m1; i++){
    //         for(int j=0; j<n2; j++){
    //             arr[i][j] = 0;
    //             for(int k=0; k<n1; k++){
    //                 arr[i][j] += (arr1[i][k] * arr2[k][j]);
    //             }
    //         }
    //     }
    //     for(int i=0; i<m1; i++){
    //         for(int j=0; j<n2; j++){
    //             cout<<arr[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }
    // else{
    //     cout<<"Matrix multiplication is not possible in this case"<<endl;
    // }

//****************************************************************************************************************//

    // int m,n;
    // cout<<"Enter the number of rows: ";
    // cin>>m; 
    // cout<<"Enter the number of columns: ";
    // cin>>n;
    // int arr[m][n];
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         cin>>arr[i][j];
    //     }
    // }
    // cout<<endl;

    // cout<<"Wave patter-1: ";
    // for(int i=0; i<m; i++){
    //     if(i%2 == 0){
    //         for(int j=0; j<n; j++){
    //             cout<<arr[i][j]<<" ";
    //         }
    //     }
    //     else{
    //         for(int j=n-1; j>=0; j--){
    //             cout<<arr[i][j]<<" ";
    //         }
            
    //     }
    // }
    // cout<<endl;

    // cout<<"Wave patter-2: ";
    // for(int i=0; i<m; i++){
    //     if(i%2 != 0){
    //         for(int j=0; j<n; j++){
    //             cout<<arr[i][j]<<" ";
    //         }
    //     }
    //     else{
    //         for(int j=n-1; j>=0; j--){
    //             cout<<arr[i][j]<<" ";
    //         }
            
    //     }
    // }
    // cout<<endl;
    
    // cout<<"Wave patter-3: ";
    // for(int i=m-1; i>=0; i--){
    //     if(i%2 != 0){
    //         for(int j=0; j<n; j++){
    //             cout<<arr[i][j]<<" ";
    //         }
    //     }
    //     else{
    //         for(int j=n-1; j>=0; j--){
    //             cout<<arr[i][j]<<" ";
    //         }
            
    //     }
    // }
    // cout<<endl;

    // cout<<"Wave patter-4: ";
    // for(int i=m-1; i>=0; i--){
    //     if(i%2 == 0){
    //         for(int j=0; j<n; j++){
    //             cout<<arr[i][j]<<" ";
    //         }
    //     }
    //     else{
    //         for(int j=n-1; j>=0; j--){
    //             cout<<arr[i][j]<<" ";
    //         }
            
    //     }
    // }
    // cout<<endl;

    // cout<<"Wave patter-5: ";
    // for(int j=0; j<n; j++){
    //     if(j%2 == 0){
    //         for(int i=0; i<m; i++){
    //             cout<<arr[i][j]<<" ";
    //         }
    //     }
    //     else{
    //         for(int i=n-1; i>=0; i--){
    //             cout<<arr[i][j]<<" ";
    //         }
    //     }
    // }
    // cout<<endl;

    // cout<<"Wave patter-6: ";
    // for(int j=0; j<n; j++){
    //     if(j%2 != 0){
    //         for(int i=0; i<m; i++){
    //             cout<<arr[i][j]<<" ";
    //         }
    //     }
    //     else{
    //         for(int i=n-1; i>=0; i--){
    //             cout<<arr[i][j]<<" ";
    //         }
    //     }
    // }
    // cout<<endl;

    // cout<<"Wave patter-7: ";
    // for(int j=n-1; j>=0; j--){
    //     if(j%2 != 0){
    //         for(int i=0; i<m; i++){
    //             cout<<arr[i][j]<<" ";
    //         }
    //     }
    //     else{
    //         for(int i=n-1; i>=0; i--){
    //             cout<<arr[i][j]<<" ";
    //         }
    //     }
    // }
    // cout<<endl;

    // cout<<"Wave patter-8: ";
    // for(int j=n-1; j>=0; j--){
    //     if(j%2 == 0){
    //         for(int i=0; i<m; i++){
    //             cout<<arr[i][j]<<" ";
    //         }
    //     }
    //     else{
    //         for(int i=n-1; i>=0; i--){
    //             cout<<arr[i][j]<<" ";
    //         }
    //     }
    // }
    // cout<<endl;

//****************************************************************************************************************//

    // int m,n;
    // cout<<"Enter the number of rows: ";
    // cin>>m; 
    // cout<<"Enter the number of columns: ";
    // cin>>n;
    // int arr[m][n];
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         cin>>arr[i][j];
    //     }
    // }

    // cout<<endl<<"Spiral form-1: "<<endl;
    // int minr=0, maxr=m-1;
    // int minc=0, maxc=n-1;
    // int count = 0;

    // // while(minr<=maxr && minc<=maxc){      
    // //     for(int j=minc; j<=maxc; j++){
    // //         cout<<arr[minr][j]<<" ";
    // //     }
    // //     minr++;
    // //     if(maxc<minc || maxr<minr){
    // //         break;
    // //     }
    // //     for(int i=minr; i<=maxr; i++){
    // //         cout<<arr[i][maxc]<<" ";
    // //     }
    // //     maxc--;
    // //     if(maxr<minr || maxr<minr){
    // //         break;
    // //     }
    // //     for(int j=maxc; j>=minc; j--){
    // //         cout<<arr[maxr][j]<<" ";
    // //     }
    // //     maxr--;
    // //     if(maxc<minc || maxr<minr){
    // //         break;
    // //     }
    // //     for(int i=maxr; i>=minr; i--){
    // //         cout<<arr[i][minc]<<" ";
    // //     }
    // //     minc++;
    // // }

    // while(minr<=maxr && minc<=maxc){      // we can also use count and when count become no of element then break loop
    //     for(int j=minc; j<=maxc && count<(m*n); j++){
    //         cout<<arr[minr][j]<<" ";
    //         count++;
    //     }
    //     minr++;
    //     for(int i=minr; i<=maxr && count<(m*n); i++){
    //         cout<<arr[i][maxc]<<" ";
    //         count++;
    //     }
    //     maxc--;
    //     for(int j=maxc; j>=minc && count<(m*n); j--){
    //         cout<<arr[maxr][j]<<" ";
    //         count++;
    //     }
    //     maxr--;
    //     for(int i=maxr; i>=minr && count<(m*n); i--){
    //         cout<<arr[i][minc]<<" ";
    //         count++;
    //     }
    //     minc++;
    // }

//****************************************************************************************************************//

    return 0;
}