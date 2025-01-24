#include<bits/stdc++.h>
using namespace std;

string coinGame(int k, int l, vector<int> coin);
bool top_down_1(int n, int k, int l);
bool bottom_up_1(int n, int k, int l);
vector<bool> dp(1000001, false);

int c_vacation(int n, vector<vector<int>> v);
vector<vector<int>> dp_2;

int longestCommonSubSequence(string s1, string s2);
int top_down_2(string &s1, string &s2, int i, int j);
string ans = "";
vector<vector<int>> dp_3;
int printing_lcs(string &s1, string &s2, int i, int j, string output);
int bottom_up_2(string s1, string s2);

int main(){

//*********************************************************************************************************************//

    // Problem-1: MCOINS-coinGame (sphere online judge)
    // https://www.spoj.com/problems/MCOINS/
    // int k,l;
    // cout<<"Enter k: ";  cin>>k;
    // cout<<"Enter l: ";  cin>>l;
    // vector<int> coin = {3, 12, 113, 25714, 88888};  // do this qestion with bottom uo appraoch

    // cout<<"There are two players A and B"<<endl;
    // cout<<"Matchs won by the players: "<<coinGame(k,l,coin)<<endl;

//*********************************************************************************************************************//

    // Problem-2: C-Vacation (AtCoder) 
    // https://atcoder.jp/contests/dp/tasks/dp_c
    // int n;
    // cout<<"Enter number of days: ";  cin>>n;

    // vector<vector<int>> happiness(n,vector<int>(3)); 
    // for(int i=0; i<happiness.size(); i++) for(int j=0; j<happiness[0].size(); j++) cin>>happiness[i][j];
    // cout<<"Maximum possible happiness will be: "<<c_vacation(n,happiness)<<endl;

    // dp_2.resize(n,vector<int>(3,0));  // alternate method 
    // int a,b,c;  cin>>a>>b>>c;
    // dp_2[0][0] = a;
    // dp_2[0][1] = b;
    // dp_2[0][2] = c;
    // for(int i=1; i<n; i++){
    //     cin>>a>>b>>c;
    //     dp_2[i][0] = a + max(dp_2[i-1][1],dp_2[i-1][2]);
    //     dp_2[i][1] = b + max(dp_2[i-1][0],dp_2[i-1][2]);
    //     dp_2[i][2] = c + max(dp_2[i-1][0],dp_2[i-1][1]);
    // }
    // cout<<max({dp_2[n-1][2],dp_2[n-1][2],dp_2[n-1][2]})<<endl;

//*********************************************************************************************************************//

    // Problem-3: (Leetcode-1143) Lowest Common Subsequence (almost same as question-3)
    string s1,s2;
    cin>>s1;  cin>>s2;
    cout<<"Logest common subsequence will be of length: "<<longestCommonSubSequence(s1,s2)<<endl;

//*********************************************************************************************************************//

    // Problem-4: F-LCS (AtCoder)
    // https://atcoder.jp/contests/dp/tasks/dp_f
    // try to print the common subsequence by reading the dp 2d vector

//*********************************************************************************************************************//


    return 0;
}

string coinGame(int k, int l, vector<int> coin){
    int n = coin.size();
    string s = "";
    for(int i=0; i<n; i++){
        // if(top_down_1(coin[i],k,l)) s+="A";
        // else s+="B";
        if(bottom_up_1(coin[i],k,l)) s+="A"; // bottom up approach in this case is much easier to implement
        else s+="B";  // not able to run top down approach
    }
    return s;
}
bool top_down_1(int n, int k, int l){  // not able to run code with top down approach
    if(n<1) return false;
    if(n==1 || n==k || n==l) return true;
    if(dp[n]) return dp[n];
    return dp[n] = !(top_down_1(n-1,k,l) && ((n-k>=1)?top_down_1(n-k,k,l):true) && ((n-l>=1)?top_down_1(n-l,k,l):true)); 
}
bool bottom_up_1(int n, int k, int l){  // bottom up approach is working fine 
    dp[1] = dp[l] = dp[k] = 1;
    for(int i=2; i<=n; i++){
        if(i == k || i == l) continue;
        dp[i] = !(dp[i-1] && ((i-k>=1) ? dp[i-k] : 1) && ((i-l>=1) ? dp[i-l] : 1));
    }
    return dp[n];
}

int c_vacation(int n, vector<vector<int>> v){  // it a bottom_up approach 
    dp_2.resize(n,vector<int>(3,0));   // it  is not easy to think top_down approach in this case

    // dp_2[0][0] = v[0][0]; // base case
    // dp_2[0][1] = v[0][1];
    // dp_2[0][2] = v[0][2];
    // for(int i=1; i<n; i++){
    //     dp_2[i][0] = v[i][0] + max(dp_2[i-1][1],dp_2[i-1][2]); // ith day --> a
    //     dp_2[i][1] = v[i][1] + max(dp_2[i-1][0],dp_2[i-1][2]); // ith day --> b
    //     dp_2[i][2] = v[i][2] + max(dp_2[i-1][0],dp_2[i-1][1]); // ith day --> c
    // }
    // return max({dp_2[n-1][0],dp_2[n-1][1],dp_2[n-1][2]});

    dp_2[n-1][0] = v[n-1][0]; // we can also do it in a opposite way 
    dp_2[n-1][1] = v[n-1][1];
    dp_2[n-1][2] = v[n-1][2];
    for(int i=n-2; i>=0; i--){
        dp_2[i][0] = v[i][0] + max(dp_2[i+1][1],dp_2[i+1][2]); // ith day --> a
        dp_2[i][1] = v[i][1] + max(dp_2[i+1][0],dp_2[i+1][2]); // ith day --> b
        dp_2[i][2] = v[i][2] + max(dp_2[i+1][0],dp_2[i+1][1]); // ith day --> c
    }
    return max({dp_2[0][0],dp_2[0][1],dp_2[0][2]});
}

int longestCommonSubSequence(string s1, string s2){
    // dp_3.clear();
    // dp_3.resize(1005,vector<int>(1005,-1));
    // return top_down_2(s1,s2,0,0);
    return bottom_up_2(s1,s2);
}
int top_down_2(string &s1, string &s2, int i, int j){
    if(i >= s1.length() || j >= s2.length()) return 0;
    if(dp_3[i][j] != -1) return dp_3[i][j];
    if(s1[i] == s2[j]) return dp_3[i][j] = 1 + top_down_2(s1,s2,i+1,j+1);
    else return dp_3[i][j] = max(top_down_2(s1,s2,i+1,j),top_down_2(s1,s2,i,j+1));
}
int bottom_up_2(string s1, string s2){
    dp_3.clear();
    // dp_3.resize(1005,vector<int>(1005,-1));  
    // for(int i=0; i<=s1.length(); i++) dp_3[i][0] = 0;
    // for(int j=0; j<=s2.length(); j++) dp_3[0][j] = 0;
    dp_3.resize(1005,vector<int>(1005,-0));  // there is no need for base case as we have already initialized with 0
    for(int i = s1.size()-1; i>=0; i--) for(int j = s2.size()-1; j>=0; j--){
        if(s1[i] == s2[j]) dp_3[i][j] = 1 + dp_3[i+1][j+1];
        else dp_3[i][j] = max(dp_3[i+1][j],dp_3[i][j+1]);
    }
    return dp_3[0][0];
}




