#include<bits/stdc++.h>
using namespace std;

// typedef priority_queue<int,vector<int>,greater<int>> minHeap;
// typedef priority_queue<int> maxHeap;

int largestSumAfterKNegations(vector<int> &nums, int k);  // Leetcode 1005

double fractionalKnapsack(vector<int> &profit, vector<int> &weight, int n, int capacity);
bool cmp(pair<int,int> &p1, pair<int,int> &p2);

int maximumUnits(vector<vector<int>> boxType, int truckSize);  // Leetcode-1710
bool cmp2(vector<int> &p1, vector<int> &p2);

int maxRescueBoat(vector<int> &people, int limit);  // Leetcode-881\

int min_product(vector<int> v);

// #define ll long long int;
typedef long long int ll;
ll minCostToBreakGrid(int n, int m, vector<ll> vertical, vector<ll> horizontal);
bool cmp_3(int x, int y);

string repeatLimitedString(string s, int repeatLimit);

int main(){

//*****************************************************************************************************//

    // vector<int> profit = {60,100,120};
    // vector<int> weight = {10,20,30};
    // int capacity = 50;
    // int n = 3;
    // cout<<fractionalKnapsack(profit,weight,n,capacity)<<endl;

//*****************************************************************************************************//

    // vector<vector<int>> v = {{1,3},{2,2},{3,1}};  // Leetcode-1710
    // int trucksize = 4;
    // cout<<"Total number of maximum units can be loaded: "<<maximumUnits(v,trucksize)<<endl;

//*****************************************************************************************************//

    // vector<int> v = {-2,-3,1,4,-2};
    // for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";  cout<<endl;
    // cout<<"Minimum product possible in this case: "<<min_product(v)<<endl;

//*****************************************************************************************************//

    string str = "ccccccccccccccaaaaaaaaaaaaaabbbbbbbb";
    int repeatLimit = 3;
    cout<<str<<endl;
    cout<<repeatLimitedString(str,repeatLimit)<<endl;
    cout<<"Length of original string: "<<str.length()<<endl;
    cout<<"Length of ans string: "<<repeatLimitedString(str,repeatLimit).length()<<endl;

//*****************************************************************************************************//


    return 0;
}

int largestSumAfterKNegations(vector<int> &nums, int k){  // Leetcode-1005
    int n = nums.size();
    priority_queue<int,vector<int>,greater<int>> minHeap(nums.begin(),nums.end()); // O(n)
    // for(int i=0; i<n; i++) minHeap.push(nums[i]); // don't do like this as it take more time complexity

    // for(int i=0; i<k; i++){
    //     int minele = minHeap.top();  minHeap.pop();  
    //     if(minele != 0) minHeap.push(minele*(-1));
    //     else break;
    // }
    // int maxSum = 0;
    // while(minHeap.size()>0){
    //     maxSum += minHeap.top();
    //     minHeap.pop();
    // }

    int maxSum = 0;  // better approach 
    for(int i=0; i<n; i++) maxSum += nums[i]; // O(n) calculating sum before negations
    while(k--){  // O(klogn)
        int minele = minHeap.top();
        if(minele == 0) break;
        minHeap.pop();
        maxSum -= minele;
        minHeap.push(-1*minele);
        maxSum += (-minele);
    }

    return maxSum;
}

double fractionalKnapsack(vector<int> &profit, vector<int> &weight, int n, int capacity){
    vector<pair<int,int>> arr;
    for(int i=0; i<n; i++) arr.push_back({profit[i],weight[i]});
    sort(arr.begin(),arr.end(),cmp);  // vector is now sorted in descending order based on the ratio (profit/weight)
    double result = 0;
    for(int i=0; i<n; i++){
        if(arr[i].second <= capacity){
            result += arr[i].first;     // all over Time complexity: O(nlogn)
            capacity -= arr[i].second;
        }
        else{
            result += ((arr[i].first*1.0)/(arr[i].second*1.0))*capacity;
            capacity = 0;
            break;
        }
    }
    return result;
}
bool cmp(pair<int,int> &p1, pair<int,int> &p2){
    double r1 = (p1.first*1.0)/(p1.second*1.0);
    double r2 = (p2.first*1.0)/(p2.second*1.0);
    return r1 > r2;
}

int maximumUnits(vector<vector<int>> boxType, int truckSize){  // Leetcode-1710
    sort(boxType.begin(),boxType.end(),cmp2);  // Time complexity: O(nlogn)
    int profit = 0;
    for(int i=0; i<boxType.size(); i++){
        if(boxType[i][0] <= truckSize){
            profit += boxType[i][0]*boxType[i][1];
            truckSize -= boxType[i][0];
        }
        else{
            profit += truckSize*boxType[i][1];
            truckSize = 0;
            break;
        }
    }
    return profit;
}
bool cmp2(vector<int> &p1, vector<int> &p2){
    return p1[1] > p2[1];
}

int maxRescueBoat(vector<int> &people, int limit){  // Leetcode-881
    sort(people.begin(),people.end());  // Time complexity: O(nlogn)
    int i=0, j=people.size()-1;
    int boat = 0;
    while(i<=j){
        if(people[i] + people[j] <= limit){
            i++; j--;
            boat++;  // allocate boat to the pair 
        }
        else{
            j--; 
            boat++;  // allocate boat to the single
        }
    }
    return boat;
}

int min_product(vector<int> v){
    int positive=0, negative=0, zero=0;
    int product_pos=1, product_neg=1;
    int largest_negative = INT_MIN;
    for(int i=0; i<v.size(); i++){
        if(v[i] < 0){
            negative++;
            product_neg *= v[i];
            largest_negative = max(largest_negative,v[i]);
        }
        else if(v[i] == 0) zero++;
        else{
            positive++;
            product_pos *= v[i];
        }
    }
    if(negative == 0){
        if(zero > 0) return 0;
        else{
            auto it = min_element(v.begin(), v.end());  // return minimum element from the vector 
            return *it;
        }
    }
    else{
        if(negative % 2 == 0) return (product_neg/largest_negative)*product_pos;
        else return product_neg * product_pos;
    }
}

ll minCostToBreakGrid(int n, int m, vector<ll> vertical, vector<ll> horizontal){
    sort(vertical.begin(),vertical.end(),cmp_3);
    sort(vertical.begin(),vertical.end(),cmp_3);
    int h_cut = 1;
    int v_cut = 1;
    int h = 0, v = 0;
    ll ans = 0;
    while(h<horizontal.size() && v<vertical.size()){
        if(vertical[v] > horizontal[h]){
            ans += vertical[v]*v_cut;
            h_cut++;
            v++;
        }
        else{
            ans += horizontal[v]*h_cut;
            v_cut++;
            h++;
        }
    }
    while(h < horizontal.size()){
        ans += horizontal[v]*h_cut;
        v_cut++;
        h++;
    }
    while(v < vertical.size()){
        ans += vertical[v]*v_cut;
        h_cut++;
        v++;
    }
    return ans;
}
bool cmp_3(int x, int y){
    return x>y;
}

string repeatLimitedString(string s, int repeatLimit){
    unordered_map<char,int> mp;
    for(int i=0; i<s.length(); i++) mp[s[i]]++;
    priority_queue<pair<char,int>> pq;
    for(auto p : mp) pq.push(p);
    string result = "";
    while(!pq.empty()){
        auto largest = pq.top();
        pq.pop();
        int len = min(repeatLimit,largest.second);
        for(int i=0; i<len; i++) result += largest.first;
        pair<char,int> secondLargest;
        if(largest.second - len > 0){
            if(!pq.empty()){
                secondLargest = pq.top();
                pq.pop();
                result += secondLargest.first;
            }
            else return result;
            if(secondLargest.second - 1 > 0) pq.push({secondLargest.first,secondLargest.second-1});
            pq.push({largest.first,largest.second-len});
        }
    }
    return result;
}


