#include<bits/stdc++.h>
using namespace std;

int KorderLCS(vector<int> a, vector<int> b, int i, int j, int k);
int top_down(vector<int> a, vector<int> b, int i, int j, int k);
int dp_1[2005][2005][8];

int max_profit(int k, vector<int> prices);  // Leetcode-188
int top_down_2(vector<int> prices, int i, int k, bool on);
int dp_2[1005][105][2];

int top_down_3(int n, int k, int last);
int dp_3[105][105][2];

int minTaps(int n, vector<int> ranges);

int main(){

//*******************************************************************************************************************//

    // Problem-1: https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
    // it is not possible to think bottom up solution as it will become very complicated when 3d dp_1 array come in picture 

//*******************************************************************************************************************//

    // Problem-2: (Leetcode-188) 
    // after solving above question try leetcode-123, leetcode-122 and leetcode-121

//*******************************************************************************************************************//

    // Problem-3: https://www.spoj.com/problems/GNYR09F/
    // int t; cin>>t;
    // while(t--){
    //     int num,n,k;
    //     cin>>num>>n>>k;
    //     memset(dp_1, -1, sizeof dp_1);
    //     int ans = top_down_3(n,k,0) + top_down_3(n,k,1);
    //     cout<<num<<" "<<ans<<endl;
    // }

//*******************************************************************************************************************//

    // Problem-4: (Leetcode-1326)
    

//*******************************************************************************************************************//



    return 0;
}

int KorderLCS(vector<int> a, vector<int> b, int i, int j, int k){
    return top_down(a,b,i,j,k);
}
int top_down(vector<int> a, vector<int> b, int i, int j, int k){
    if(i == a.size() || j == b.size()) return 0;
    if(dp_1[i][j][k] != -1) return dp_1[i][j][k];
    int result = 0;
    if(a[i] == b[j]) result = 1 + top_down(a,b,i+1,j+1,k);
    else{
        if(k>0) result = 1 + top_down(a,b,i+1,j+1,k-1);
        result = max(result, top_down(a,b,i+1,j,k));
        result = max(result, top_down(a,b,i,j+1,k));
    }
    return dp_1[i][j][k] = result;
}

int max_profit(int k, vector<int> prices){  // Leetcode-188
    memset(dp_2,-1,sizeof(dp_1));
    return top_down_2(prices,0,k,false);
}
int top_down_2(vector<int> prices, int i, int k, bool on){
    if(i == prices.size()) return 0;
    if(dp_2[i][k][on] != -1) return dp_2[i][k][on]; 
    int ans = INT_MIN;
    ans = top_down_2(prices,i+1,k,on); // avoid
    if(on) ans = max(ans, prices[i] + top_down_2(prices,i+1,k-1,false));
    else if(!on && k>0) ans = max(ans, top_down_2(prices,i+1,k,true) - prices[i]);
    return dp_2[i][k][on] = ans;
}

int top_down_3(int n, int k, int last){
    if(n == 0) return 0;
    if(n == 1){
        if(k == 0) return 1;
        else return 0;
    }
    if(dp_3[n][k][last] != -1) return dp_3[n][k][last];
    if(last == 1) return dp_3[n][k][last] = top_down_3(n-1,k,0) + top_down_3(n-1,k-1,1); 
    else return dp_3[n][k][last] = top_down_3(n-1,k,0) + top_down_3(n-1,k,1); 
}

int minTaps(int n, vector<int> ranges){
    int n = ranges.size();
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int i=0; i<=n; i++){
        int start = max(0, i-ranges[i]);
        int end = min(n, i+ranges[i]);
        int ans = INT_MAX;
        for(int j = start; j<=end; j++) ans = min(ans, dp[j]);
        if(ans != INT_MAX) dp[end] = min(dp[end], ans+1);
    }
    return dp[n] == INT_MAX ? -1 : dp[n];
}

