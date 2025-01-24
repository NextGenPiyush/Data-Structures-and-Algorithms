#include<bits/stdc++.h>
using namespace std;

void display_vector(vector<int> v){
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
}

int vector_max(vector<int> v){
    int ans = INT_MIN;
    int n = v.size();
    for(int i=0; i<n; i++) if(ans<v[i]) ans = v[i];
    return ans;
}

bool isBalanced(string s);
void remove_consecutive_duplicate(string &s);
vector<int> next_greater_element_1(vector<int> v);  
vector<int> next_greater_element_2(vector<int> v);
vector<int> prev_greater_element(vector<int> v);
vector<int> prev_smaller_element(vector<int> v);
vector<int> next_smaller_element(vector<int> v);
vector<int> prev_smaller_element_idx(vector<int> v);
vector<int> next_smaller_element_idx(vector<int> v);

int main(){

//********************************************************************************************************************//    

    // string s = "((()))";
    // string s = "()()()";
    // string s = ")())()((";
    // string s = ")()(";
    // if(isBalanced(s)) cout<<"given string is a balanced string"<<endl;
    // else cout<<"given string is a unbalanced string"<<endl;

//********************************************************************************************************************//    

    // string s = "aaabbcddaabffffgg";  
    // cout<<"before removing duplicated: "<<s<<endl;
    // remove_consecutive_duplicate(s);
    // cout<<"after removing duplicated: "<<s<<endl;

//********************************************************************************************************************//    

    // vector<int> v = {3,1,2,5,4,6,2,3};
    // cout<<"Printing vector: "<<endl;
    // display_vector(v);

    // // vector<int> ans = next_greater_element_1(v);
    // vector<int> ans_1 = next_greater_element_2(v);
    // cout<<"Printing next greater element: "<<endl;
    // display_vector(ans_1);

    // vector<int> ans_2 = prev_greater_element(v);
    // cout<<"Printing previous greater element: "<<endl;
    // display_vector(ans_2);

    // vector<int> ans_3 = next_smaller_element(v);
    // cout<<"Printing next smaller element: "<<endl;
    // display_vector(ans_3);

    // vector<int> ans_4 = prev_smaller_element(v);
    // cout<<"Printing previous smaller element: "<<endl;
    // display_vector(ans_4);

//********************************************************************************************************************//    

    // int arr[] = {100,80,60,81,70,60,75,85};    // stockes price
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int ans[n];
    // stack<int> temp;
    // ans[0] = 1;
    // temp.push(0);
    // for(int i=1; i<n; i++){
    //     while(temp.size()>0 && arr[temp.top()]<=arr[i]) temp.pop();    // time complexity: O(n) how??
    //     if(temp.size()==0) ans[i] = i+1;
    //     else ans[i] = i-temp.top();
    //     // ans[i] = i-ans[i];  // we can also do this separately
    //     temp.push(i);
    // }
    // // for(int i=0; i<n; i++) ans[i] = i-ans[i];  // we can also do this by using separate loop 
    // for(int i=0; i<n; i++) cout<<arr[i]<<" "; cout<<endl;
    // for(int i=0; i<n; i++) cout<<ans[i]<<" "; cout<<endl;   // stock spam 

//********************************************************************************************************************//    

    vector<int> v = {2,1,5,6,2,3};                  // Leetcode-84 (Largest Rectangle in Histogram)
    vector<int> v = {2,4};
    int n = v.size();
    vector<int> area(n);
    vector<int> nsei = next_smaller_element_idx(v);
    vector<int> psei = prev_smaller_element_idx(v);
    for(int i=0; i<n; i++) area[i] = v[i]*(nsei[i]-psei[i]-1);
    cout<<"Maximum area possible: "<<vector_max(area)<<endl;  // we can do it without taking vector

//********************************************************************************************************************//    

    return 0;
}

bool isBalanced(string s){
    if(s.length()%2 != 0) return false;  // as number of '(' and ')' must be same to return true
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(') st.push(s[i]);
        else{
            if(st.size()==0) return false;
            else st.pop();
        }
    }
    if(st.size()==0) return true;
    else return false;
}

void remove_consecutive_duplicate(string &s){
    string new_s;
    stack<char> temp;
    temp.push(s[0]);
    for(int i=1; i<s.length(); i++) if(temp.top()!=s[i]) temp.push(s[i]);
    while(!temp.empty()){
        new_s.push_back(temp.top());
        temp.pop();
    }
    reverse(new_s.begin(),new_s.end());
    s = new_s;
}

vector<int> next_greater_element_1(vector<int> v){   
    int n = v.size();
    vector<int> ans(n);
    ans[n-1] = -1;                  // simple brute force algorithem
    for(int i=0; i<n-1; i++){       // Time complexity: O(n^2);
        ans[i] = -1;                // space complexity: O(n)
        for(int j=i+1; j<n; j++){
            if(v[j]>v[i]){
                ans[i] = v[j];
                break; 
            }
        }
    }
    return ans;
}

vector<int> next_greater_element_2(vector<int> v){
    int n = v.size();
    stack<int> temp;
    vector<int> ans(n);
    ans[n-1] = -1;
    temp.push(v[n-1]);
    for(int i=n-2; i>=0; i--){                                  // Time complexity: O(n)
        while(temp.size()>0 && temp.top()<=v[i]) temp.pop();    // as every element is poped and pushed ones
        if(temp.size()==0) ans[i] = -1;                         // space complexity: O(n)
        else ans[i] = temp.top();
        temp.push(v[i]);
    }
    return ans;
}   

vector<int> prev_greater_element(vector<int> v){
    int n = v.size();
    stack<int> temp;
    vector<int> ans(n);
    ans[0] = -1;
    temp.push(v[0]);
    for(int i=1; i<n; i++){                                      // Time complexity: O(n)   
        while(temp.size()>0 && temp.top()<=v[i]) temp.pop();
        if(temp.size()==0) ans[i] = -1;
        else ans[i] = temp.top();
        temp.push(v[i]);
    }
    return ans;
}

vector<int> prev_smaller_element(vector<int> v){
    int n = v.size();
    stack<int> temp;
    vector<int> ans(n);
    ans[0] = -1;
    temp.push(v[0]);
    for(int i=1; i<n; i++){                                      // Time complexity: O(n)   
        while(temp.size()>0 && temp.top()>=v[i]) temp.pop();
        if(temp.size()==0) ans[i] = -1;
        else ans[i] = temp.top();
        temp.push(v[i]);
    }
    return ans;
}

vector<int> next_smaller_element(vector<int> v){
    int n = v.size();
    stack<int> temp;
    vector<int> ans(n);
    ans[n-1] = -1;
    temp.push(v[n-1]);
    for(int i=n-2; i>=0; i--){                                  // Time complexity: O(n)
        while(temp.size()>0 && temp.top()>=v[i]) temp.pop();    // as every element is poped and pushed ones
        if(temp.size()==0) ans[i] = -1;                         // space complexity: O(n)
        else ans[i] = temp.top();
        temp.push(v[i]);
    }
    return ans;
}   

vector<int> prev_smaller_element_idx(vector<int> v){
    int n = v.size();
    vector<int> ans(n);
    stack<int> temp;
    ans[0] = -1;
    temp.push(0);
    for(int i=1; i<n; i++){
        while(temp.size()>0 && temp.top()>=v[i]) temp.pop();
        if(temp.size()==0) ans[i] = -1;
        else ans[i] = temp.top();
        temp.push(i); 
    }
    return ans;
}

vector<int> next_smaller_element_idx(vector<int> v){
    int n = v.size();
    vector<int> ans(n);
    stack<int> temp;
    ans[n-1] = n;
    temp.push(n-1);
    for(int i=n-2; i>=0; i--){
        while(temp.size()>0 && v[temp.top()]>=v[i]) temp.pop();
        if(temp.size()==0) ans[i] = n;
        else ans[i] = temp.top();
        temp.push(i); 
    }
    return ans;
}

