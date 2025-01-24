#include<bits/stdc++.h>
using namespace std;

vector<long long> findPrefixScore(vector<int>& nums){ // Leetcode-2640
    int n = nums.size();
    vector<long long> v(n);
    int maxi = nums[0];
    v[0] = nums[0] + maxi;
    for(int i=1; i<n; i++){  // solved question in one pass only 
        maxi = max(maxi,nums[i]);
        v[i] = v[i-1] + nums[i] + maxi;
    }
    return v;
}

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n){ // Leetcode-1109
    vector<int> ans(n,0);
    int row = bookings.size();
    int col = bookings[0].size();
    for(int i=0; i<row; i++){  
        for(int j=bookings[i][0]; j<=bookings[i][1]; j++){  // without prefix sum
                ans[j-1] += bookings[i][2];
        }
        // if(bookings[i][0]-1 >= 0) ans[bookings[i][0]-1] += bookings[i][2];
        // if(bookings[i][1] < n) ans[bookings[i][1]] -= bookings[i][2];
    }
    // for(int i=1; i<n; i++) ans[i] += ans[i-1];  // with prefix sum
    return ans;
}

int main(){


    return 0;
}