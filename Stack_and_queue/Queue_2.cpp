#include<bits/stdc++.h>
using namespace std;

class MyQueue{   // Leetcode-232 
    public:
        stack<int> st,helper;
        MyQueue(){
            // constructor
        }
        void push(int x){  // O(1) 
            st.push(x);    // This is push efficient appraoch 
            // we can also use PushAtBottom which result in pop efficient approach             
        }
        int pop(void){   // O(n)
            while(st.size()>0){
                helper.push(st.top());
                st.pop();
            }
            int x = helper.top();
            helper.pop();
            while(helper.size()>0){
                st.push(helper.top());
                helper.pop();
            }
        }
        int peek(void){   // O(n)
            while(st.size()>0){
                helper.push(st.top());
                st.pop();
            }
            int x = helper.top();
            while(helper.size()>0){
                st.push(helper.top());
                helper.pop();
            }
        }
        bool empty(void){
            if(st.empty()) return true;
            else return false;
        }
};

void display(queue<int> q){
    int n = q.size();
    for(int i=0; i<n; i++){
        int x = q.front();
        q.pop();
        q.push(x);
        cout<<x<<" ";
    }
    cout<<endl;
}

void reversing_first_k(queue<int> &q, int k);

int countStudents(vector<int> &students, vector<int> &sandwiches);  // Leetcode-1700

int main(){

//***********************************************************************************************************************//

    // queue<int> q;
    // int k;
    // q.push(1);  q.push(2);  q.push(3);  q.push(4);  q.push(5);  q.push(6);
    // display(q);
    // cout<<"Enter k: "; 
    // cin>>k;
    // cout<<"After reversing first K element of the queue: ";
    // reversing_first_k(q,k);
    // display(q);

//***********************************************************************************************************************//

    int arr[] = {3,-4,-7,30,7,-9,2,1,6,-1};
    int k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ans;
    queue<int> q;
    for(int i=0; i<n; i++) if(arr[i]<0) q.push(i);
    int i=0;
    while(i<=n-k){
        while(q.size()>0 && q.front()<i) q.pop();
        if(q.size()==0 || q.front()>=i+k) ans.push_back(0);
        else ans.push_back(arr[q.front()]);
        i++;
    }
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    cout<<endl;

//***********************************************************************************************************************//

    return 0;
}

void reversing_first_k(queue<int> &q, int k){
    stack<int> st;
    for(int i=0; i<k; i++){
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }
    int n = q.size();
    for(int i=0; i<n-k; i++){
        q.push(q.front());
        q.pop();
    }
}

int countStudents(vector<int> &students, vector<int> &sandwiches){  // Leetcode-1700
    queue<int> q;
    for(int i=0; i<students.size(); i++) q.push(students[i]);
    int i = 0, count = 0;
    while(q.size()>0 && count!=q.size()){
        if(q.front() == sandwiches[i]){
            count = 0;
            q.pop();
            i++;
        }
        else{
            q.push(q.front());
            q.pop();
            count++;
        }
    }
    return q.size();
}



