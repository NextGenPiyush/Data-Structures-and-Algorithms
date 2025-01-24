#include<bits/stdc++.h>
using namespace std;

vector<int> dp;

int fibonachi_1(int n){                    
    if(n == 1 || n == 0) return n;       // space complexity: O(n) --> due to call stack
    if(dp[n]!=-1) return dp[n];
    return dp[n] = fibonachi_1(n-1)+fibonachi_1(n-2);  // top-down approach
}

int fibonachi_2(int n){
    dp.resize(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;                       // time complexity: O(n)
    for(int i=2; i<n+1; i++) dp[i] = dp[i-1]+dp[i-2];
    return dp[n];
}

int fibonachi_3(int n){
    int a = 0;
    int b = 1;                       // time complexity: O(n)
    int i = 2;                       // space complexity: O(1)
    int ans;
    while(i<=n){
        ans = a+b;
        a = b;
        b = ans;
        i++;
    }
    return ans;
}

int main(){

    dp.resize(100,-1);
    cout<<fibonachi_1(6);

    // cout<<fibonachi_2(6);

    // cout<<fibonachi_3(6);



    return 0;
}