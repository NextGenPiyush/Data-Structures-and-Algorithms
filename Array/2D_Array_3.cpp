#include<bits/stdc++.h>
using namespace std;
int main(){

//***************************************************************************************************************//

    // // vector<int> v{1,2,3,4,5,6,7,8,9,0};  // --> 1-D vector
    // // for(int i=0; i<v.size(); i++){
    // //     cout<<v[i]<<" ";
    // // }

    // vector<int> v1{1,2,3};
    // vector<int> v2{4,5};
    // vector<int> v3{6,7,8,9,0};
    // // vector<vector<int>> v{v1,v2,v3};  // we can also write that
    // vector<vector<int>> v{{1,2,3},{4,5},{6,7,8,9,0}};  // 2-D vector
    
    // // vector<vector<int>> v;  we can also do that 
    // // v.push_back(v1); 
    // // v.push_back(v2);
    // // v.push_back(v3);  similarly we can use pop_back also

    // for(int i=0; i<v.size(); i++){
    //     if(i==0){
    //         for(int j=0; j<v1.size(); j++){
    //             cout<<v[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     else if(i==1){
    //         for(int j=0; j<v2.size(); j++){
    //             cout<<v[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     else{
    //         for(int j=0; j<v3.size(); j++){
    //             cout<<v[i][j]<<" ";
    //         }
    //     }
    // }
    
//***************************************************************************************************************//

    // vector<vector<int>> v1;                
    // vector<vector<int>> v2(3); // can store 3 vectors of any size                
    // vector<vector<int>> v3(3,vector<int>(4)); // storing 3 vector each of size 4 amd 0 is present at every index              
    // vector<vector<int>> v4(3,vector<int>(4,2)); // storing 3 vector each of size 4 and 2 is present at every index 

    // // int row = v3.size();
    // // int column = v3[0].size();
    // for(int i=0; i<v3.size(); i++){
    //     for(int j=0; j<v3[0].size(); j++){
    //         cout<<v3[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // for(int i=0; i<v4.size(); i++){
    //     for(int j=0; j<v4[0].size(); j++){
    //         cout<<v4[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

//***************************************************************************************************************//

    // int m;
    // cout<<"Enter the number: ";
    // cin>>m;
    // vector<vector<int>> v;

    // // for(int i=0; i<m; i++){       // same loop 
    // //     vector<int> a(i+1);
    // //     v.push_back(a);         // a grid is formed where all the elemets are 0
    // // }
    // // for(int i=0; i<m; i++){        // same loop
    // //     for(int j=0; j<=i; j++){
    // //         if(j==0 || i==j){
    // //             v[i][j] = 1;
    // //         }
    // //         else{
    // //             v[i][j] = v[i-1][j] + v[i-1][j-1];
    // //         }
    // //     }
    // // }
    // // for(int i=0; i<m; i++){        // same loop
    // //     for(int j=0; j<=i; j++){
    // //         cout<<v[i][j]<<" ";
    // //     }
    // //     cout<<endl;
    // // }

    // for(int i=0; i<m; i++){       // single loop
    //     vector<int> a(i+1);
    //     v.push_back(a);                   // a grid is formed where all the elemets are 0
    //     for(int j=0; j<=i; j++){
    //         if(j==0 || i==j){
    //             v[i][j] = 1;
    //         }
    //         else{
    //             v[i][j] = v[i-1][j] + v[i-1][j-1];
    //         }
    //         cout<<v[i][j]<<"   ";
    //     }
    //     cout<<endl;
    // }

//***************************************************************************************************************//

    // vector<vector<int>> v{{0,0,1,1},{1,0,1,0},{1,1,0,0}};  // we cannot pass array like this 'arr[][]' error!!!
    // int row = v.size();                                    // we can pass array like this 'arr[4][5]' no error
    // int colm = v[0].size();
    // for(int i=0; i<row; i++){
    //     if(v[i][0] == 0){
    //         for(int j=0; j<colm; j++){
    //             if(v[i][j] == 0){
    //                 v[i][j] = 1;
    //             }
    //             else{
    //                 v[i][j] = 0;
    //             }
    //         }
    //     }
    // }
    // for(int j=0; j<colm; j++){
    //     int noz = 0;
    //     int noo = 0;
    //     for(int i=0; i<row; i++){
    //         if(v[i][j] == 0){
    //             noz++;
    //         }
    //         else{
    //             noo++;
    //         }
    //     }
    //     if(noz > noo){
    //         for(int i=0; i<row; i++){
    //             if(v[i][j] == 0){
    //                 v[i][j] = 1;
    //             }
    //             else{
    //                 v[i][j] = 0;
    //             }
    //         }
    //     }
    // }
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<colm; j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // int sum = 0;
    // for(int i=0; i<v.size(); i++){
    //     int x = 1;
    //     for(int j=colm-1; j>=0; j--){
    //         sum += (v[i][j]*x);
    //         x *= 2;
    //     }
    // }
    // cout<<"Maximum possible sum: "<<sum<<endl;

//***************************************************************************************************************//

    // vector<vector<int>> v{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    // for(int i=0; i<v.size(); i++){
    //     for(int j=0; j<v[0].size(); j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // int x;
    // cout<<"Enter the target: ";
    // cin>>x;
    // int i=0;
    // int j=v[0].size();
    // while(i<v.size() && j>=0){
    //     if(v[i][j] == x){
    //         cout<<"Found at ("<<i<<","<<j<<")"<<endl;
    //         break;
    //     }
    //     else if(v[i][j] < x){
    //         i++;
    //     }
    //     else{
    //         j--;
    //     }
    // }

//***************************************************************************************************************//

    return 0;
}
