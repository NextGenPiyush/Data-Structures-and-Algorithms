#include<bits/stdc++.h>
using namespace std;

int minRabbits(vector<int> ans);  // Leetcode-781

int minMeetingRooms(vector<vector<int>> interval);  // Leetcode-253 (go to lint-code and search for question)

int main(){

//********************************************************************************************************************//

    vector<vector<int>> interval = {{1,10},{2,7},{3,19},{8,12},{10,20},{11,30}};
    for(int i=0; i<interval.size(); i++){
        for(int j=0; j<interval[0].size(); j++){
            cout<<interval[i][j]<<" ";
        }
        cout<<"   ";
    }
    cout<<endl;
    cout<<"Minimum number of meeting rooms required for the meetings will be: "<<minMeetingRooms(interval)<<endl;

//********************************************************************************************************************//

    return 0;
}

int minRabbits(vector<int> ans){  // Leetcode-781   
    unordered_map<int,int> mp;
    int result = 0;
    for(int i=0; i<ans.size(); i++){
        if(!mp[ans[i]+1]){   // if ans[i]+1 is not exist in the map 
            result += ans[i]+1;  // then we started a new color group
            if(ans[i] == 0) continue;
            mp[ans[i]+1] = 1;
        }
        else{                         // Time complexity: O(n)
            mp[ans[i]+1]++;           // space complexity: O(n)
            int key = ans[i]+1;
            int val = mp[key];
            if(key == val){  // that means we found all the rabits of that group hence eliminate the group 
                mp.erase(key);
            }
        }
    }
    return result;
}

int minMeetingRooms(vector<vector<int>> interval){  // Leetcode-253
    if(interval.size() == 0) return 0;
    vector<int> start,end;      // space complexity: o(n)
    for(auto ele : interval){
        start.push_back(ele[0]);  
        end.push_back(ele[1]);
    }
    sort(start.begin(),start.end());  // Time complexity: O(logn)
    sort(end.begin(),end.end());
    int ans = 0, room = 0;
    int i=0,j=0;
    while(i < start.size() and j < end.size()){
        if(start[i] < end[j]){  // a meeting started 
            room++;
            ans = max(ans,room);
            i++;
        } 
        else if(start[i] > end[j]){  // a meeting ended
            room--;
            j++;
        }
        else{
            i++; 
            j++;
        }
    }
    return ans;
}





