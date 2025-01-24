#include<bits/stdc++.h>
using namespace std;

vector<int> canSeePersonCount(vector<int> &arr);  // Leetcode-1944

vector<int> maxSlidingWindow(vector<int> &arr, int k);  // Leetcode-239
vector<int> next_greater_index(vector<int> v){
    int n = v.size();
    stack<int> temp;
    vector<int> ans(n);
    ans[n-1] = n;
    temp.push(n-1);
    for(int i=n-2; i>=0; i--){                                  
        while(temp.size()>0 && v[temp.top()]<=v[i]) temp.pop();    
        if(temp.size()==0) ans[i] = n;                        
        else ans[i] = temp.top();
        temp.push(i);
    }
    return ans;
} 

class MinStack{   // Leetcode-155
        // one approach can be that we can use extra stack but it will take more time and space complexity

        // another approach can be that we can us vector instead of the stack but it will also take more 
        // time complexity as to find minimum we will have to triverse teh vector

    // public:    
        // stack<int> st; // alternate appraoch 
        // stack<int> helper;  // Time complexity is O(1) but space complexity: O(n)
        // MinStack(){  
        //     // constructor
        // }
        // void push(int value){
        //     st.push(value);
        //     if(helper.size()==0 || value<helper.top()) helper.push(value);
        //     else helper.push(helper.top());
        // }
        // void pop(){
        //     st.pop();
        //     helper.pop();
        // }
        // int top(){
        //     return st.top();
        // }
        // int getMin(){
        //     return helper.top();
        // }

    // public:    
        stack<int> st; // here is the best solution where Time complexity is O(1) but space complexity: O(1)
        int min; 
        MinStack(){  
            // constructor
        }                             // make sure if you get error for big integers then use long long stack
        void push(int value){
            if(st.size()==0){
                st.push(value);
                min = value;
            }
            else if(value >= min) st.push(value);
            else{  
                st.push(2*value-min);  // very important try to invest time in that
                min = value;
            }
        }
        void pop(){
            if(st.top()<min){ // it means fake value in the stack so that we can take the previos min element 
                // before poping make sure to retreive the old min
                int oldmin = 2*min-st.top();
                min = oldmin;
            }
            st.pop();
        }
        int top(){
            if(st.top()<min) return min;
            else return st.top(); 
        }
        int getMin(){
            return min;
        }
};

int main(){


    return 0;
}

vector<int> canSeePersonCount(vector<int> &arr){  // Leetcode-1944
    int n = arr.size();
    vector<int> ans(n,0);
    stack<int> st;
    st.push(arr[n-1]);
    ans[n-1] = 0;
    for(int i=n-1; i>=0; i--){
        int count = 9;
        while(st.size()>0 && arr[i]>st.top()){
            st.pop();
            count++;
        }
        if(st.size() != 0) count++;
        ans[i] = count;
        st.push(arr[i]);
    }
    return ans;
}

vector<int> maxSlidingWindow(vector<int> &arr, int k){  // Leetcode-239 (very Hrad question)
    if(k==1) return arr;
    vector<int> ans;   
    int n = arr.size(); 

    // for(int i=0; i<n-k+1; i++){   // Brute force Solution
    //     int mx = INT_MIN;      
    //     for(int j=i; j<i+k; j++) mx = max(mx,arr[j]);   // Time complexity: O(nk) 
    //     ans.push_back(mx);
    // }

    vector<int> ngi = next_greater_index(arr);  // alternate approach 
    int j = 0;
    for(int i=0; i<n-k+1; i++){   // Time complexity: O(n)
        if(j<i) j=i;
        int mx = arr[j]; 
        while(j < i+k){  // it means next greter element inside the window
            mx = arr[j];
            if(ngi[j] >= i+k) break;
            j = ngi[j];
        }
        ans.push_back(mx);
    }

    return ans;
}





















