#include<bits/stdc++.h>
using namespace std;

vector<int> dp_1;
int fib(int n);

vector<int> height;
int k;
vector<int> dp_2;
int minCostToReach_1(int i); // top down approach  A-Frog_2 problem at ATcoder
int minCostToReach_2();  // bottom up approach

vector<int> h;
vector<int> dp(h.size()+1,-1);
int mincost(int i, int k);

int main(){

//*************************************************************************************************************//

    int n = 7;
    // dp_1.resize(n+1,-1); 
    cout<<"5th fibonachi number is: "<<fib(n)<<endl;

//*************************************************************************************************************//

    // int n;
    // cin>>n>>k;
    // height.resize(n);
    // dp_2.resize(n,-1);  // dp[i] = -1, it means ith state not yet completed
    // for(int i=0; i<n; i++) cin>>height[i];
    // cout<<"Minimum cost by frog to reach the last stone will be: "<<minCostToReach_1(0)<<endl;
    // cout<<"Minimum cost by frog to reach the last stone will be: "<<minCostToReach_2()<<endl;
    // // try to solve A-Frog_1 problem at ATcoder (k=2)

//*************************************************************************************************************//


    return 0;
}

int fib(int n){

    if(n==0 || n==1) return n;  

    return fib(n-1) + fib(n-2); // top down approach without dynamic programming 
       
    if(dp_1[n] != -1) return dp_1[n];  // top down approach with dynamic programming
    else return dp_1[n] = fib(n-1) + fib(n-2);

    // dp_1.resize(n+1,-1);   // bottom up approach  
    // dp_1[0] = 0;     // Time complexity: O(n)
    // dp_1[1] = 1;
    // for(int i=2; i<=n; i++) dp_1[i] = dp_1[i-1] + dp_1[i-2];
    // return dp_1[n];

    // int a = 0, b = 1, c = 0;  // Time complexity: O(n)
    // int i = 2;   // bottom up approach
    // while(i <= n){  // more space optimized code 
    //     c = a + b;
    //     a = b;
    //     b = c;
    //     i++;
    // }
    // return c;

}

int minCostToReach_1(int i){
    if(i >= height.size()) return INT_MAX; // frog crossed the last stone now it's not possible to find cost 
    if(i == height.size()-1) return 0;  // means frog is already at last stone
    if(dp_2[i] != -1) return dp_2[i]; // recursive approach with dp 
    int ans = INT_MAX;
    for(int j=1; j<=k; j++){    // top down approach
        if(i+j >= height.size()) break;
        ans = min(ans, abs(height[i]-height[j])+minCostToReach_1(i+j));  
    }   // Time comlexity: O(nk) and space complexity: O(n) in recursive approach with dp
    // return ans;
    return dp_2[i] = ans;
}

int minCostToReach_2(){
    int n = height.size();  // Time comlexity: O(nk) and space complexity: O(n)
    dp_2[n-1] = 0;  // base case: mim cost to reach the last stone if you already at last stone 
    for(int i=n-2; i>=0; i--){
        for(int j=1; j<=k; j++){    // bottom up approach
            if(i+j >= height.size()) break;
            dp_2[i] = min(dp_2[i], abs(height[i]-height[j])+dp_2[i+j]);
        }
    }
    return dp_2[0];
}


int mincost(int i, int k){
    if(i >= h.size()) return INT_MAX;
    if(i == h.size()-1) return 0;
    if(dp[i] != -1) return dp[i];
    int ans = INT_MAX;
    for(int j=1; j<=k; j++){
        if(i+j >= height.size()) break;
        ans = min(ans,abs(h[i]-h[i+j])+mincost(i+j,k));
    } 
    return dp[i] = ans;
}

int mincost(int i, int k){
    int n = h.size();
    dp[n-1] = 0;
    for(int j=n-2; j>=0; j--){
        int ans = INT_MAX;
        for(int m=1; m<=k; m++){
            if(j+m >= h.size()) break;
            ans = min(ans,abs(h[j]-h[j+m])+dp[j+m]);
        }
        dp[j] = ans;
    }
    return dp[0];
}

int mincost(int i, int k){
    if(i<0) return INT_MAX;
    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];
    int ans = INT_MAX;  
    for(int j=1; j<=k; j++){
        if(i-j < 0) break;
        ans = min(ans, abs(h[i]-h[i-j])+mincost(i-j,k));
    }
    return dp[i] = ans;
}

int mincost(int i, int k){
    int n = h.size();
    dp[0] = 0;
    for(int j=1; j<n; j++){
        int ans = INT_MAX;
        for(int m=1; m<=k; m++){
            if(j-m < 0) break;
            ans = min(ans, abs(h[j]-h[j-m])+dp[j-m]);
        }
        dp[j] = ans;
    }
    return dp[i];
}






