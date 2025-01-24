#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k);  // Leetcode-239

string predictPartyVictory(string senate);  // Leetcode-649

void display(queue<int> q);
void reorder(queue<int> &q);

vector<int> deckRevealedIncreasing(vector<int> &deck);  // Leetcode-950

int main(){

//**********************************************************************************************************************// 

    // queue<int> q;
    // q.push(1);  q.push(2);  q.push(3);  q.push(4);  q.push(5);  q.push(6);  q.push(7);  q.push(8);  
    // display(q);  cout<<endl;
    // reorder(q);
    // display(q);

//**********************************************************************************************************************// 

    return 0;
}

vector<int> maxSlidingWindow(vector<int> &nums, int k){
    if(k==1) return nums; 
    int n = nums.size();
    deque<int> dq;  // decreasing order of indeces
    vector<int> ans;  // i should be min k-1
    for(int i=0; i<n; i++){
        while(dq.size()>0 && nums[i]>nums[dq.back()]) dq.pop_back();
        dq.push_back(i);
        int j = i-k+1;  // start of the window
        while(dq.front()<j) dq.pop_front();
        if(i>=k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}

string predictPartyVictory(string senate){  // Leetcode-649
    queue<int> q,r,d;
    for(int i=0; i<senate.length(); i++){
        q.push(i);
        if(senate[i] == 'R') r.push(i);
        else d.push(i);
    }
    while(q.size()>1){
        if(senate[q.front()] == 'X') q.pop();
        else if(senate[q.front()] == 'R'){
            if(d.size() == 0) return "Radiant";   // Check for victory
            else{     // takes rights of the D            
                senate[d.front()] = 'X';
                d.pop();
                q.push(q.front());
                q.pop();
                r.push(r.front());
                r.pop();
            }
        }
        else{   // senate[q.front()] == 'D'
            if(r.size() == 0) return "Dier";   // Check for victory
            else{     // takes rights of the R            
                senate[r.front()] = 'X';
                r.pop();
                q.push(q.front());
                q.pop();
                d.push(d.front());
                d.pop();
            }
        }
    }
    if(senate[q.front()] == 'R') return "Radient";
    else return "Dier";
}

void display(queue<int> q){
    int n = q.size();
    for(int i=0; i<n; i++){
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
    }
}

void reorder(queue<int> &q){
    stack<int> st;
    int n = q.size();
    for(int i=0; i<n/2; i++){  // pop 1st half of the queue to the stack
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){   // empty the stack into queue
        q.push(st.top());
        st.pop();
    }
    for(int i=0; i<n/2; i++){  // pop 2nd half of the queue to the stack
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){  // Most important step --> interleave one by one 
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
    while(q.size()>0){   // Reversing the queue using stack 
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }
}

vector<int> deckRevealedIncreasing(vector<int> &deck){  // Leetcode-950
    int n = deck.size();
    sort(deck.begin(),deck.end());
    queue<int> q;
    for(int i=0; i<n; i++) q.push(i);
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        int idx = q.front();
        q.pop();
        q.push(q.front());
        q.pop();
        ans[idx] = deck[i];
    }
    return ans;
}