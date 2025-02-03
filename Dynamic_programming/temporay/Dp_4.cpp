#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int removingDigit(int num);
vector<int> getDigit(int n);
int function_top_down_1(int n);
int function_bottom_up_1(int n);
vector<int> dp_1;

int minimizingCoins(int target);
vector<int> coin;
int function_top_down_2(int target);
int function_bottom_up_2(int target);
vector<int> dp_2;

int diceCombination(int num);
int function_top_down_3(int n);
int function_bottom_up_3(int n);
vector<int> dp_3;

int numRollsToTarget(int n, int k, int target);  // Leetcode-1155
int function_top_down_4(int n, int k, int target);
int function_bottom_up_4(int n, int k, int target);
vector<vector<int>> dp_4;

int main(){

//**************************************************************************************************************//

    // Problem-1: Removing Digit CSES problem set (can we apply greedy here)
    // https://cses.fi/problemset/task/1637
    // int n;
    // cout<<"Enter your number: ";  cin>>n;
    // cout<<"Minimum number of steps to reduce it to zero: "<<removingDigit(n)<<endl;

//**************************************************************************************************************//

    // Problem-2: Minimizing Coins CSES problem set (try coin combination-1 and coin combination-2 CSES problem set)
    // https://cses.fi/problemset/task/1634
    // int n,target;
    // cout<<"Enter the number of coins: ";  cin>>n;
    // cout<<"Enter your target: ";  cin>>target;
    // cout<<"Enter coins: "; 
    // for(int i=0; i<n; i++){
    //     int x;
    //     cin>>x;
    //     coin.push_back(x);
    // }
    // if(minimizingCoins(target) == INT_MAX) cout<<-1<<endl;
    // else cout<<"minimum number of coins required to get target: "<<minimizingCoins(target)<<endl;

//**************************************************************************************************************//

    // Problem-3: Dice Combination CSES problem set
    // https://cses.fi/problemset/task/1633
    // int n;
    // cout<<"Enter number of dice: ";  cin>>n;
    // cout<<"Total number of ways we can get "<<n<<": "<<diceCombination(n)<<endl;

//**************************************************************************************************************//

    // Problem-4: (Leetcode-1155)
    // int n,k,target;
    // cout<<"Enter number of dice available: ";  cin>>n;
    // cout<<"Enter number of faces: ";  cin>>k;
    // cout<<"Enter your target: ";  cin>>target;
    // cout<<"number of ways of getting "<<target<<": "<<numRollsToTarget(n,k,target)<<endl;

//***********************************************************************************************************//


    return 0;
}

int removingDigit(int num){
    dp_1.clear();
    dp_1.resize(1000005,-1);
    return function_top_down_1(num);
    // return function_bottom_up_1(num);
}
vector<int> getDigit(int n){
    vector<int> result;
    while(n){
        if(n%10 != 0) result.push_back(n%10); // because we can't push zero as it will lead to infinite recursion
        n /= 10;                      
    }
    return result;
}
int function_top_down_1(int n){
    if(n == 0) return 0;
    if(n <= 9) return 1;
    if(dp_1[n] != -1) return dp_1[n]; 
    vector<int> digit = getDigit(n);
    int result = INT_MAX;
    for(int i=0; i<digit.size(); i++) result = min(result, function_top_down_1(n-digit[i]));
    return dp_1[n] = 1 + result;
}
int function_bottom_up_1(int n){
    dp_1[0] = 0;
    for(int i=1; i<=9; i++) dp_1[i] = 1;
    for(int i=10; i<=n; i++){
        vector<int> digit = getDigit(i);
        int result = INT_MAX;
        for(int j=0; j<digit.size(); j++) result = min(result, dp_1[i-digit[j]]);
        dp_1[i] = 1 + result;
    }
    return dp_1[n];
}

int minimizingCoins(int target){
    dp_2.clear();
    dp_2.resize(1000006,-1);
    // return function_top_down_2(target);
    return function_bottom_up_2(target);
}
int function_top_down_2(int target){
    if(target == 0) return 0;
    if(dp_2[target] != -1) return dp_2[target]; 
    int result = INT_MAX;
    for(int i=0; i<coin.size(); i++){
        if(target-coin[i] < 0) continue;
        result = min(result,function_top_down_2(target-coin[i]));
    }
    if(result == INT_MAX) return dp_2[target] = INT_MAX;  // means all coins value is greater than the target 
    return dp_2[target] = 1 + result;
}
int function_bottom_up_2(int target){
    dp_2[0] = 0;
    for(int i=1; i<=target; i++){
        int result = INT_MAX;
        for(int j=0; j<coin.size(); j++){
            if(i-coin[j] < 0) continue;
            result = min(result,dp_2[i-coin[j]]);
        }
        if(result == INT_MAX) return dp_2[i] = INT_MAX;
        dp_2[i] = 1 + result;
    }
    return dp_2[target];
}

int diceCombination(int num){
    dp_3.clear();
    dp_3.resize(num+1,-1);
    // return function_top_down_3(num);
    return function_bottom_up_3(num);
}
int function_top_down_3(int n){
    if(n == 0) return 1;
    if(dp_3[n] != -1) return dp_3[n];
    int result = 0;
    for(int i=1; i<=6; i++) if(n-i >= 0) result = (result%mod + function_top_down_3(n-i)%mod)%mod;
    return dp_3[n] = result%mod;
}
int function_bottom_up_3(int n){
    dp_3[0] = 1;
    for(int i=1; i<=n; i++){
        int result = 0;
        for(int j=1; j<=6; j++) if(i-j >= 0) result = (result%mod + dp_3[i-j]%mod)%mod;
        dp_3[i] = result%mod;
    }
    return dp_3[n]%mod;
}

int numRollsToTarget(int n, int k, int target){  // Leetcode-1155
    dp_4.clear();
    dp_4.resize(35,vector<int>(1005,-1));
    // return function_top_down_4(n,k,target);
    return function_bottom_up_4(n,k,target);
}
int function_top_down_4(int n, int k, int target){
    if(n == 0 and target == 0) return 1;
    if(n == 0) return 0; // it means target have not become zero yet but we have rolled all the dice
    if(dp_4[n][target] != -1) return dp_4[n][target];
    int result = 0;
    for(int i=1; i<=k; i++) if(target-i >= 0) result = (result%mod + function_top_down_4(n-1,k,target-i)%mod)%mod;
    return dp_4[n][target] = result%mod;
}
int function_bottom_up_4(int n, int k, int target){
    dp_4[0][0] = 1;
    for(int i=1; i<=target; i++) dp_4[0][i] = 0; // don,t need to do this as we have already initialized with zero
    for(int i=1; i<=n; i++){ // traverse into nummber of dice (rows)
        for(int j=0; j<=target; j++){ // traverse through number of targets (columns)
            int result = 0;
            for(int a=1; a<=k; a++) if(j-a >= 0) result = (result%mod + dp_4[i-1][j-a]%mod)%mod;
            dp_4[i][j] = result%mod;
        }
    }
    return dp_4[n][target];
}
