#include<bits/stdc++.h>  // #include<stack> is must for working with stacks
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int val){          
            this->val = val;
            next = NULL;
        }
        Node(){               // constructor overloading 
            val = 0;
            next = NULL;
        }
};

class Stack_1{          // implementation of stack using array
    public:
        int idx = -1;
        int arr[10];  // we can also run constructor to take input of the size of array 
        void push(int val){
            if(idx == 9){
                cout<<"Stack is full --overflow-- "<<endl;
                return;
            }
            idx++;
            arr[idx] = val;
        }
        void pop(){
            if(idx == -1){
                cout<<"Stack is empty --underflow-- "<<endl;
                return;
            }
            idx--;
        }
        int top(){
            if(idx == -1){
                cout<<"Stack is empty --underflow-- "<<endl;
                return -1;
            }
            return arr[idx];
        }
        int size(){
            return idx+1;
        }
};

class Stack_2{          // implementation of stack using vector
    public:
        vector<int> v;
        void push(int val){   // --overflow-- condition never ocuur in the case of vector implementation 
            v.push_back(val);
        }
        void pop(){
            if(v.size() == 0){
                cout<<"Stack is empty --underflow-- "<<endl;
                return;
            }
            v.pop_back();
        }
        int top(){
            if(v.size() == 0){
                cout<<"Stack is empty --underflow-- "<<endl;
                return -1;  // It means empty
            }
            return v[v.size()-1];
        }
        int size(){
            return v.size();
        }
};

class Stack_3{          // implementation of stack using LinkedList
    public:
        Node *head = NULL;
        int size = 0;
        void push(int val){    // --overflow-- condition never ocuur in the case of LinkedList implementation 
            Node *temp = new Node(val);
            temp->next = head;
            head = temp;
            size++;
        }
        void pop(){
            if(head == NULL){
                cout<<"Stack is empty --underflow-- "<<endl;
                return;
            }
            head = head->next;
            size--;
        }
        int top(){
            if(head == NULL){
                cout<<"Stack is empty --underflow-- "<<endl;
                return -1;
            }
            return head->val;
        }
        void display_rev(){
            Node *temp = head;
            while(temp != NULL){        // Normal traversing in the linked list 
                cout<<temp->val<<" ";   
                temp = temp->next;
            }
            cout<<endl;
        }
        void display(){
            Node *temp = head;
            print(temp);
            cout<<endl;
        }  
        void print(Node *temp){           // Recursive approach 
            if(temp == NULL) return;
            print(temp->next);
            cout<<temp->val<<" ";
        }
};

void print_rev(stack<int> st);  // print top to bottom (reverse order)
void print(stack<int> st);      // print bottom to top (correct order)
void reverse(stack<int> &st);
void pushAtBottom(stack<int> &st, int val);
void pushAtIdx(stack<int> &st, int idx, int val);   
void display_rec_rev(stack<int> &st);                  // recursing algorithem to display in reverse order
void display_rec(stack<int> &st);

int main(){

//*********************************************************************************************************************//

/*
The functions associated with stack are: 
empty() – Returns whether the stack is empty – Time Complexity : O(1) 
size() – Returns the size of the stack – Time Complexity : O(1) 
top() – Returns a reference to the top most element of the stack – Time Complexity : O(1) 
push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1) 
pop() – Deletes the most recent entered element of the stack – Time Complexity : O(1) 
*/
    // stack<int> st;
    // st.push(10); st.push(20); st.push(30); st.push(40); st.push(50); st.push(60); st.push(70); st.push(80);
    // cout<<"Size of the stack is: "<<st.size()<<endl;
    // cout<<"Top element in the stack is: "<<st.top()<<endl;
    // cout<<"Printing stack: "<<endl;
    // print(st);   cout<<endl;
    // cout<<"Printing stack in revrese order: "<<endl;
    // print_rev(st);   cout<<endl;

//*********************************************************************************************************************//

    // stack<int> st;
    // st.push(10); st.push(20); st.push(30); st.push(40); st.push(50); st.push(60); st.push(70); st.push(80);
    // cout<<"Before reversing the stack: "<<endl;
    // print(st);
    // cout<<"After reversing the satck: "<<endl;
    // reverse(st);
    // print(st);

//*********************************************************************************************************************//

    // try to implement a reverse function which uses linkedlist or vector/array to reverse the stack
    // copy data of one stack to another stack in same order

//*********************************************************************************************************************//

    stack<int> st;
    st.push(10); st.push(20); st.push(30); st.push(40); st.push(50); st.push(60); st.push(70); st.push(80);
    cout<<"Before pushing element at the bottom: "<<endl;
    print(st);
    cout<<"After pushing element at the bottom: "<<endl;
    pushAtBottom(st,90);
    print(st);
    cout<<"After pushing 100 at 5th index: "<<endl;
    pushAtIdx(st,5,100);
    print(st);

//*********************************************************************************************************************//

    return 0;
}

void print_rev(stack<int> st){        // Only display stack, not making any change to the original stack
    while(st.size()>0){            // Iterative approach
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    // if(st.size()==0) return;   // Recursive approach
    // cout<<st.top()<<" ";
    // int x = st.top();
    // st.pop();
    // print_rev(st);   
    // st.push(x);
}

void print(stack<int> st){      // stack is here passed by value
    // stack<int> temp;         // Iterative approach
    // while(st.size()>0){
    //     temp.push(st.top());
    //     st.pop();
    // }
    // while(temp.size()>0){
    //     cout<<temp.top()<<" ";
    //     st.push(temp.top());
    //     temp.pop();
    // }
    // cout<<endl;

    if(st.size()==0) return;   // Recursive approach
    int x = st.top();
    st.pop();
    print(st);
    st.push(x);
    cout<<x<<" ";
}

void reverse(stack<int> &st){
    // stack<int> temp1,temp2;     // reverse stack using 2 extra empty stacks, Iterative approach
    // while(st.size()>0){        // we can also do it by using extra one array/vectoe 
    //     temp1.push(st.top());
    //     st.pop();
    // }
    // while(temp1.size()>0){
    //     temp2.push(temp1.top());
    //     temp1.pop();
    // }
    // while(temp2.size()>0){
    //     st.push(temp2.top());
    //     temp2.pop();
    // }

    if(st.size()==1) return;    // reversing recursively 
    int x = st.top();
    st.pop();
    reverse(st);
    pushAtBottom(st,x);
}

void pushAtBottom(stack<int> &st, int val){
    // stack<int> temp;                        
    // while(st.size()>0){
    //     temp.push(st.top());      // iterative approach
    //     st.pop();
    // }
    // st.push(val);
    // while(temp.size()>0){
    //     st.push(temp.top());
    //     temp.pop();
    // }

    if(st.size()==0){    // recursive approach
        st.push(val);
        return;
    }
    int x = st.top();
    st.pop();
    pushAtBottom(st,val);
    st.push(x);
}

void pushAtIdx(stack<int> &st, int idx, int val){
    // stack<int> temp;
    // while(st.size()>idx){
    //     temp.push(st.top());           // Iterative approach
    //     st.pop();
    // }
    // st.push(val);
    // while(temp.size()>0){
    //     st.push(temp.top());
    //     temp.pop();
    // }

    if(st.size()==idx){    // recursive approach
        st.push(val);
        return;
    }
    int x = st.top();
    st.pop();
    pushAtIdx(st,idx,val);
    st.push(x);
}