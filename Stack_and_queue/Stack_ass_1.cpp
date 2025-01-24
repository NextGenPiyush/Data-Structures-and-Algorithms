#include<bits/stdc++.h>
using namespace std;

void print(stack<int> st);
void remove_from_top(stack<int> &s, int k);

int main(){

//*****************************************************Question-2*****************************************************//

    // Remove Kth element from the top

    // stack<int> st;
    // int k;
    // st.push(10); st.push(20); st.push(30); st.push(40); st.push(50); st.push(60); st.push(70); st.push(80);
    // cout<<"Printing stack: "<<endl;
    // print(st);
    // cout<<"we are removing the kth element from the top: "<<endl;
    // cout<<"Enter the value of k: ";
    // cin>>k;
    // remove_from_top(st,k);
    // print(st);

//*****************************************************Question-3*****************************************************//

    // Binary representation using stack

    stack<int> st;
    int n;
    cout<<"Enter your number: "<<endl;
    cin>>n;
    while(n>0){
        st.push(n%2);
        n /= 2;
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop(); 
    }

//********************************************************************************************************************//

    return 0;
}

void print(stack<int> st){
    stack<int> temp;         // space complexity: O(n)  taking extra stack to store the elements in reverse order
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
    }
    while(temp.size()>0){
        cout<<temp.top()<<" ";
        st.push(temp.top());
        temp.pop();
    }
    cout<<endl;
}

void remove_from_top(stack<int> &s, int k){
    if(k==0) return;
    if(k>s.size()){
        cout<<"There are total "<<s.size()<<" elements only!! "<<endl;
        return;
    }
    int n = s.size();
    stack<int> temp;

    // while(s.size() > (n-k+1)){
    //     temp.push(s.top());
    //     s.pop();
    // }

    k--;
    while(k--){
        temp.push(s.top());
        s.pop();
    }
    s.pop();
    while(temp.size() > 0){   // while(!temp.empty())
        s.push(temp.top());
        temp.pop();
    }
}











