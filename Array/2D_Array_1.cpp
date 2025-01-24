#include<bits/stdc++.h>
using namespace std;
int main(){

//***********************************************************************************************************//

    // int arr1[4][2] = {{1,2},{3,4},{5,6},{7,8}};
    // int arr2[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    // int arr3[][3] = {1,2,3,4,5,6,7,8,9,10,11,12};  // this means arr3[4][3] 
    // // it is necessary to initialize arr3[][3] at the time of decleration
    // // int arr4[4][]; --> this is not correct 

    // // 2d array is the array of array
    // int m = 3; // rows
    // int n = 4; // column
    // int arr[3][4]; // a matrix of 3*4 is created 

    // for(int i=0; i<3; i++){
    //     for(int j=0; j<4; j++){
    //         cin>>arr[i][j];
    //     }
    // }
    // for(int i=0; i<3; i++){
    //     for(int j=0; j<4; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

//***********************************************************************************************************//

    // 4 student --> roll numbers and marks

//***********************************************************************************************************//

    // int m,n;
    // cout<<"Enter the number of rows: ";
    // cin>>m; 
    // cout<<"Enter the number of columns: ";
    // cin>>n;
    // int arr[m][n];
    // int max = INT_MIN;

    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         cin>>arr[i][j];
    //     }
    // } 
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         if(max < arr[i][j]){
    //             max = arr[i][j];
    //         }
    //     }
    // } 
    // cout<<"Maximum element in the matrix: "<<max<<endl;
    
//***********************************************************************************************************//

    // int m,n;
    // cout<<"Enter the number of rows: ";
    // cin>>m; 
    // cout<<"Enter the number of columns: ";
    // cin>>n;
    // int arr[m][n];
    // int sum = 0;
    // int product = 1;

    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         cin>>arr[i][j];
    //     }
    // } 
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         sum += arr[i][j];
    //         product *= arr[i][j];
    //     }
    // } 
    // cout<<"Sum of all the elements in the matrix: "<<sum<<endl;
    // cout<<"Product of all the elements in the matrix: "<<product<<endl;

//***********************************************************************************************************//

    // int m1,n1;
    // int m2,n2;

    // cout<<"Enter the number of rows of matrix-1: ";
    // cin>>m1; 
    // cout<<"Enter the number of columns of matrix-1: ";
    // cin>>n1;
    // int arr1[m1][n1];
    // for(int i=0; i<m1; i++){
    //     for(int j=0; j<n1; j++){
    //         cin>>arr1[i][j];
    //     }
    // } 

    // cout<<"Enter the number of rows of matrix-2: ";
    // cin>>m2; 
    // cout<<"Enter the number of columns of matrix-1: ";
    // cin>>n2;
    // int arr2[m2][n2];
    // for(int i=0; i<m2; i++){
    //     for(int j=0; j<n2; j++){
    //         cin>>arr2[i][j];
    //     }
    // } 

    // if((m1 == m2) && (n1 == n2)){
    //     int arr3[m1][n1];               // we don't need to creat a ner array
    //     cout<<"After addition: "<<endl;
    //     for(int i=0; i<m1; i++){
    //         for(int j=0; j<n1; j++){
    //             arr3[i][j] = arr1[i][j] + arr2[i][j];  // we can also do that arr1[i][j] += arr2[i][j];
    //             cout<<arr3[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }
    // else{
    //     cout<<"Matrix addition is not possible in this case"<<endl;
    // }

//***********************************************************************************************************//

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
    // for(int j=0; j<n; j++){
    //     for(int i=0; i<m; i++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

//***********************************************************************************************************//

    // int m,n;
    // cout<<"Enter the number of rows: ";
    // cin>>m; 
    // cout<<"Enter the number of columns: ";
    // cin>>n;
    // int arr[m][n];
    // int trans[n][m];
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         cin>>arr[i][j];
    //     }
    // }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         trans[i][j] = arr[j][i];
    //     }
    // }
    // cout<<endl<<"Transpose: "<<endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<trans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

//***********************************************************************************************************//

    // int m;
    // cout<<"Enter the order of matrix: ";
    // cin>>m; 
    // int arr[m][m];
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<m; j++){
    //         cin>>arr[i][j];
    //     }
    // }
    // for(int i=0; i<m; i++){
    //     for(int j=i+1; j<m; j++){
    //         swap(arr[i][j],arr[j][i]);
    //     }
    // }
    // cout<<endl<<"Transpose: "<<endl;
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
//***********************************************************************************************************//

    // int m;
    // cout<<"Enter the order of matrix: ";
    // cin>>m; 
    // int arr[m][m];
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<m; j++){
    //         cin>>arr[i][j];
    //     }
    // }
    // for(int i=0; i<m; i++){
    //     for(int j=i+1; j<m; j++){
    //         swap(arr[i][j],arr[j][i]);
    //     }
    // }
    // // for(int k=0; k<m; k++){
    // //     int i=0;
    // //     int j=m-1;
    // //     while(i<j){
    // //         swap(arr[k][i],arr[k][j]);
    // //         i++;
    // //         j--;
    // //     }
    // // }
    // // cout<<endl<<"After rotating by 90 degree clockwise: "<<endl;
    // // for(int i=0; i<m; i++){
    // //     for(int j=0; j<m; j++){
    // //         cout<<arr[i][j]<<" ";
    // //     }
    // //     cout<<endl;
    // // }

    // for(int k=0; k<m; k++){
    //     int i=0;
    //     int j=m-1;
    //     while(i<j){
    //         swap(arr[i][k],arr[j][k]);
    //         i++;
    //         j--;
    //     }
    // }
    // cout<<endl<<"After rotating by 90 degree anticlockwise: "<<endl;
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

//***********************************************************************************************************//

    return 0;
}