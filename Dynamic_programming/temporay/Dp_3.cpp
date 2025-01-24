#include<bits/stdc++.h>
using namespace std;

int rob(vector<int> nums);  // Leetcode-198
int helper_top_down_1(vector<int> arr, int i);
int helper_top_down_2(vector<int> arr, int i);
int helper_with_DP_1(vector<int> arr, int i);
int helper_with_DP_2(vector<int> arr, int i);
int helper_bottom_up_1(vector<int> arr);
int helper_bottom_up_2(vector<int> arr);
vector<int> dp_1;

int minStepToReduce(int n);
int top_down(int i);
int top_down_with_DP(int i);
int bottom_up(int i);
vector<int> dp_2;

int main(){

//************************************************************************************************************//

    // question_1 (Leetcode-198)

//************************************************************************************************************//

    // question_2 minimum number of steps required to reduce a number to 1 by the operation of subtracting -1, 
    // dividing by 2 and dividing by 3
    int n = 15;
    cout<<"Minimum number of steps to reduce "<<n<<" into 1: "<<minStepToReduce(n)<<endl;

//************************************************************************************************************//



    return 0;
}


int rob(vector<int> nums){  // Leetcode-198
    // dp_1.clear();  // good practive to clear when we are using global variable 
    // dp_1.resize(nums.size()-1);
    // return helper_with_DP_1(nums,0); // top down approach with dp  
    // return helper_with_DP_2(nums,0);   

    // return helper_top_down_1(nums,0); // top down approach without dp 
    // return helper_top_down_2(nums,0); 

    // return helper_bottom_up_1(nums); // bottom up approach
    return helper_bottom_up_2(nums); 
}
int helper_top_down_1(vector<int> arr, int i){ 
    int n = arr.size(); 
    if(i == n-1) return arr[i]; // last single house
    if(i == n-2) return max(arr[i],arr[i+1]);  // last two house
    return max(arr[i] + helper_top_down_1(arr,i+2), helper_top_down_1(arr,i+1)); 
}
int helper_top_down_2(vector<int> arr, int i){ 
    int n = arr.size(); 
    if(i == 0) return arr[i]; // first single house
    if(i == 1) return max(arr[i],arr[i-1]);  // first two house
    return max(arr[i] + helper_top_down_2(arr,i-2), helper_top_down_2(arr,i-1)); 
}
int helper_with_DP_1(vector<int> arr, int i){
    int n = arr.size();  
    if(i == n-1) return arr[i]; 
    if(i == n-2) return max(arr[i],arr[i+1]);  
    if(dp_1[i] != -1) return dp_1[i]; // ith state already computer
    return dp_1[i] = max(arr[i] + helper_with_DP_1(arr,i+2), helper_with_DP_1(arr,i+1)); 
}
int helper_with_DP_2(vector<int> arr, int i){
    int n = arr.size();  
    if(i == 0) return arr[i]; 
    if(i == 1) return max(arr[i],arr[i+1]);  
    if(dp_1[i] != -1) return dp_1[i]; // ith state already computer
    return dp_1[i] = max(arr[i] + helper_with_DP_2(arr,i-2), helper_with_DP_2(arr,i-1)); 
}
int helper_bottom_up_1(vector<int> arr){
    int n = arr.size();
    if(n == 1) return arr[0];
    dp_1.clear();
    dp_1.resize(n,-1);  // we can also use three variable to compute our ans without using full space 
    dp_1[n-1] = arr[n-1];   // as we have done in fibonaci series 
    dp_1[n-2] = max(arr[n-1],arr[n-2]);  
    for(int i=n-3; i>=0; i--) dp_1[i] = max(dp_1[i+1], dp_1[i+2]+arr[i]);
    return dp_1[0];
}
int helper_bottom_up_2(vector<int> arr){
    int n = arr.size();
    if(n == 1) return arr[0];
    dp_1.clear();
    dp_1.resize(n,-1); // we can also use three variable to compute our ans without using full space 
    dp_1[0] = arr[0];   // as we have done in fibonaci series 
    dp_1[1] = max(arr[0],arr[1]);  
    for(int i=3; i<n; i++) dp_1[i] = max(dp_1[i-1], dp_1[i-2]+arr[i]);
    return dp_1[n];
}


int minStepToReduce(int n){
    // return top_down(n);

    // dp_2.clear();
    // dp_2.resize(n+1,-1);
    // return top_down_with_DP(n);

    return bottom_up(n);
}
int top_down(int i){
    // Time complexity: O(n) and space complexiy: O(n)
    if(i == 1) return 0;
    if(i == 2 || i == 3) return 1;
    return 1 + min({top_down(i-1), (i%2==0)?top_down(i/2):INT_MAX, (i%3==0)?top_down(i/3):INT_MAX});
}
int top_down_with_DP(int i){
    // Time complexity: O(n) and space complexiy: O(n)
    if(i == 1) return 0;
    if(i == 2 || i == 3) return 1;
    if(dp_2[i] != -1) return dp_2[i];
    return dp_2[i] = 1 + min({top_down_with_DP(i-1), (i%2==0)?top_down_with_DP(i/2):INT_MAX, 
    (i%3==0)?top_down_with_DP(i/3):INT_MAX});
}
int bottom_up(int i){
    // Time complexity: O(n) and space complexiy: O(n)
    dp_2.clear();
    dp_2.resize(i+1,-1);
    dp_2[1] = 0;
    dp_2[2] = dp_2[3] = 1;
    for(int j=4; j<=i; j++) dp_2[j] = 1 + min({dp_2[j-1], (j%2==0)?dp_2[j/2]:INT_MAX, (j%3==0)?dp_2[j/3]:INT_MAX});
    return dp_2[i];
}




