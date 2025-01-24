#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &interval); // Leetcode-56
bool cmp(vector<int> a, vector<int> b);
bool cmp_1(vector<int> a, vector<int> b);

int eraseOverlapInterval(vector<vector<int>> &interval); // Leetcode-435

int minArrow(vector<vector<int>> &points); // Leetcode-452

int activitySelection(vector<int> start, vector<int> end, int n); // try to do it yourself

vector<double> medianSlidingWindow(vector<int> &nums, int k);  // Leetcode-480 try to do it yourself (Hard Question)

int main(){

//********************************************************************************************************************//

    // int activitySelection(vector<int> start, vector<int> end, int n); // try to do ot yourself
    // similar to non overlapping interval problem 

//********************************************************************************************************************//

    // vector<double> medianSlidingWindow(vector<int> &nums, int k); eetcode-480 try to do it yourself (Hard Question)
    // it can be solvee by using min and max Heap
    // Last question of greedy lecture 3

//********************************************************************************************************************//


    return 0;
}

vector<vector<int>> merge(vector<vector<int>> &interval){  // Leetcode-56

    // sort(interval.begin(),interval.end(),cmp);  // sorting vectors according to the ending time
    // vector<vector<int>> result;
    // int n = interval.size();
    // result.push_back(interval[n-1]); // push_back last vector
    // for(int i=n-2; i>=0; i--){
    //     vector<int> lastInterval = result[result.size()-1];
    //     vector<int> curentInterval = interval[i];
    //     if(curentInterval[1] >= result[result.size()-1][0]){  // overlapping 
    //         result[result.size()-1][0] = min(result[result.size()-1][0],curentInterval[0]);
    //         result[result.size()-1][1] = max(result[result.size()-1][1],curentInterval[1]);
    //     }
    //     else result.push_back(interval[i]);
    // }
    // reverse(result.begin(),result.end());

    sort(interval.begin(),interval.end(),cmp_1);  // sorting vectors according to the starting time
    vector<vector<int>> result;
    int n = interval.size();
    result.push_back(interval[0]); // push_back last vector
    for(int i=1; i<n; i++){
        vector<int> lastInterval = result[result.size()-1];
        vector<int> curentInterval = interval[i];
        if(curentInterval[1] >= result[result.size()-1][1]){  // overlapping 
            result[result.size()-1][0] = min(result[result.size()-1][0],curentInterval[0]);
            result[result.size()-1][1] = max(result[result.size()-1][1],curentInterval[1]);
        }
        else result.push_back(interval[i]);
    }

    return result;
}
bool cmp(vector<int> a, vector<int> b){
    return a[1]<b[1];
}
bool cmp_1(vector<int> a, vector<int> b){
    return a[0]<b[0];
}

int eraseOverlapInterval(vector<vector<int>> &interval){
    int ans = 0;

    sort(interval.begin(),interval.end(),cmp);  // sorting vectors according to the ending time
    int lastEndTime = interval[0][1];
    for(int i=1; i<interval.size(); i++){
        if(interval[i][0] < lastEndTime) ans++;
        else lastEndTime = interval[i][1];
    }

    // sort(interval.begin(),interval.end(),cmp_1);  // sorting vectors according to the starting time
    // int lastEndTime = interval[0][1];
    // for(int i=1; i<interval.size(); i++){
    //     if(interval[i][0] < lastEndTime){
    //         ans++;
    //         lastEndTime = min(lastEndTime,interval[i][1]);
    //     }
    //     else lastEndTime = interval[i][1];
    // }

    return ans;
}

int minArrow(vector<vector<int>> &points){  // Leetcode-452
    int ans = 0;
    sort(points.begin(),points.end(),cmp);  // sorting vectors according to the ending time
    int lastEndTime = points[0][1];
    for(int i=1; i<points.size(); i++){
        if(points[i][0] <= lastEndTime) ans++;
        else lastEndTime = points[i][1];
    }
    return points.size()-ans;
}
