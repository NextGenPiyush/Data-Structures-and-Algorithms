#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int val){
            this->val = val;
            next = NULL;
        }
};

class ListNode{       
    public:
        int value;
        ListNode *next;  
        ListNode *prev;  
        ListNode(int value){    
            this->value = value;
            next = NULL;
            prev = NULL;
        }
};

// class Queue{    // queue implementation using array/vector
//     public:
//         int front;
//         int back;
//         vector<int> arr;
//         int n = arr.size();
//         Queue(int size){
//             vector<int> v(size);
//             arr = v;
//             front = 0;
//             back = 0;
//         }
//         void push(int val){
//             if(back == n){
//                 cout<<"Queue is full"<<endl;
//                 return;
//             }
//             arr[back] = val;
//             back++;
//         }
//         void pop(void){
//             if(front-back == 0){   // if size = zero
//                 cout<<"Queue is empty"<<endl;
//                 return;
//             }
//             front++;   // not proper utilization of space in array implementation
//         }
//         int front(void){
//             if(front-back == 0){   
//                 cout<<"Queue is empty"<<endl;
//                 return -1;
//             }
//             return arr[front];
//         }
//         int back(void){
//             if(front-back == 0){  
//                 cout<<"Queue is empty"<<endl;
//                 return -1;
//             }
//             return arr[back-1];
//         }
//         int size(void){
//             return back-front;
//         }
//         bool empty(void){
//             if(back-front == 0) return true;
//             return false;
//         }
//         void display(void){
//             for(int i=front; i<back; i++) cout<<arr[i]<<" ";
//             cout<<endl;
//         }
// };

class Queue{                // queue implementation using Linked List
    public:
        Node* head;
        Node* tail;
        int size;
        Queue(void){
            head = tail = NULL;
            size = 0;
        }
        void push(int value){
            Node *temp = new Node(value);
            if(size == 0) head = tail = temp; 
            else{
                tail->next = temp;
                tail = temp;
            }
            size++;
        }
        void pop(){
            if(size==0){
                cout<<"Queue is empty!!"<<endl;
                return;
            }
            Node* temp =  head;
            head = head->next;
            size--;
            delete temp;  // Space optimization in linkedlist implementation
        }
        int front(){
            if(size==0){
                cout<<"Queue is empty!!"<<endl;
                return -1;
            }
            return head->val;
        }
        int back(){
            if(size==0){
                cout<<"Queue is empty!!"<<endl;
                return -1;
            }
            return tail->val;
        }
        void display(){
            Node *temp = head;
            while(temp != NULL){
                cout<<temp->val<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
        bool empty(void){
            if(size==0) return true;
            else return false;
        }
};

class Deque{    // Deque implementation with doubly LinkedList   
    public:
        ListNode *head;
        ListNode *tail;   
        int size;
        Deque(){
            head = tail = NULL;
            size = 0;
        }
        
        void push_back(int value){
            ListNode *temp = new ListNode(value);
            if(size == 0) head = tail = temp; 
            else{
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }
            size++;
        }

        void push_front(int value){
            ListNode *temp = new ListNode(value);
            if(size == 0) head = tail = NULL;
            else{
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
            size++;
        }

        void pop_front(){
            if(size==0) return;  // list is empty
            head = head->next;
            if(head != NULL) head->prev = NULL;
            if(head == NULL) tail = NULL;
            size--;
        }

        void pop_back(){
            if(size==0) return;  // list is empty
            else if(size==1){  // we can also handle the single node in the list by this way 
                pop_front();
                return;
            }
            ListNode* temp = tail->prev;
            temp->next = NULL;
            tail = temp;
        }   

        int front(){
            if(size==0){
                cout<<"Queue is empty!!"<<endl;
                return -1;
            }
            return head->value;
        }
        
        int back(){
            if(size==0){
                cout<<"Queue is empty!!"<<endl;
                return -1;
            }
            return tail->value;
        }

        void display(){
            ListNode *temp = head;
            while(temp != NULL){
                cout<<temp->value<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};

class MyCircularQueue{    // Leetcode-622 CircularQueue implementation using array/vector
    public:
        int front;
        int back;
        int capacity;  // capacity
        int size;  // size 
        vector<int> arr;
        int n = arr.size();
        MyCircularQueue(int size){
            vector<int> v(size);
            arr = v;
            front = 0;
            back = 0;
            capacity = size;
            size = 0;
        }
        bool enQueue(int val){   // Push_back   return true if element can be pushed bach else return false 
            if(size == capacity) return false;  
            arr[back] = val;
            back++;
            if(back == capacity) back=0;
            size++;
            return true;
        }
        bool deQueue(void){    // Pop_back
            if(size == 0) return false;
            front++;
            if(front == capacity) front=0;
            size--;
            return true;
        }
        int front(void){
            if(size == 0) return -1;
            return arr[front];
        }
        int back(void){
            if(size == 0) return -1;
            if(back == 0) return arr[capacity-1];
            return arr[back-1];
        }
        bool isempty(void){
            if(size == 0) return true;
            return false;
        }
        bool isFull(void){
            if(size == capacity) return true;
            return false;
        }
        // try to implement display function
};

void display(queue<int> q);
void reverse_queue(queue<int> &q);
void remove_from_even_index(queue<int> &q);

int main(){

//********************************************************************************************************************//   

    // queue<int> q;
    // q.push(10);
    // q.push(20);
    // q.push(30);    // time complexity: O(1)
    // q.push(40);
    // q.push(50);
    // cout<<q.size()<<endl;   
    // cout<<q.back()<<endl;    // time complexity: O(1)
    // q.pop();                  // time complexity: O(1)
    // cout<<q.size()<<endl;
    // cout<<q.front()<<endl;    // time complexity: O(1)
    // cout<<q.empty()<<endl;   // return true if queue is empty

//********************************************************************************************************************//   

    // queue<int> q;
    // q.push(10); q.push(20); q.push(30); q.push(40); q.push(50); q.push(60); q.push(70); q.push(80);
    // display(q);
    // reverse_queue(q);
    // display(q);
    // reverse_queue(q);
    // remove_from_even_index(q);
    // display(q);

//********************************************************************************************************************//   

    // implement reverse display function without changing the original queue 

//********************************************************************************************************************//   

    // deque<int> dq;   // #include<deque>
    // dq.push_back(10); dq.push_back(20); dq.push_back(30);
    // dq.push_front(40); dq.push_front(50); dq.push_front(60);
    // // display(dq); try to implement display function withous using linked list
    // dq.pop_back();  dq.pop_front();
    // // for more function reffer the online source 

//********************************************************************************************************************//   



    return 0;
}

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

void reverse_queue(queue<int> &q){
    stack<int> size;
    int n = q.size();
    for(int i=0; i<n; i++){    // we can also use while(q.size()>0)
        size.push(q.front());
        q.pop();
    }
    while(!size.empty()){
        q.push(size.top());
        size.pop();
    } 
}

void remove_from_even_index(queue<int> &q){
    int n = q.size();
    for(int i=0; i<n; i++){
        int x = q.front();
        q.pop();
        if(i%2 != 0) q.push(x);
        // if(i%2 == 0) q.push(x);  // remove_from_odd_index
    }
}






