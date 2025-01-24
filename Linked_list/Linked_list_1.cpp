#include<bits/stdc++.h>
using namespace std;

class Node{       // user defined data type
    public:
        int value;
        Node *next;  // pointer to the next node
        Node(int value){    // constructor 
            this->value = value;
            next = NULL;
            // this->next = NULL;  // we can also do that 
        }
        Node(){
            value = 0;
            next = NULL;
        }
};

class LinkedList{    // user defined data structure 
    public:
        Node *head;
        Node *tail;    
        int size;
        LinkedList(){
            head = tail = NULL;
            size = 0;
        }
        
        void insertAtTail(int value){
            Node *temp = new Node(value);
            if(size == 0) head = tail = temp; 
            else{
                tail->next = temp;
                tail = temp;
            }
            size++;
        }

        void insertAtHead(int value){
            Node *temp = new Node(value);
            if(size == 0) head = tail = NULL;
            else{
                temp->next = head;
                head = temp;
            }
            size++;
        }

        void insertAtIndex(int idx, int value){
            if(idx<0 || idx>size) cout<<"Invalid Index"<<endl;
            else if(idx == 0) insertAtHead(value);
            else if(idx == size) insertAtTail(value);
            else{
                Node *t = new Node(value);
                Node *temp = head;
                for(int i=1; i<=idx-1; i++) temp = temp->next;
                t->next = temp->next;
                temp->next = t;
                size++;
            }
        }

        int getAtIndex(int idx){
            if(idx<0 || idx>=size){
                cout<<"Invalid output: ";
                return -1;
            }
            else if(idx==0) return head->value;
            else if(idx==size-1) return tail->value;
            else{
                Node *temp = head;
                for(int i=1; i<=idx; i++) temp = temp->next;
                return temp->value;
            }
        }

        void deleteAtHead(){
            if(size==0){
                cout<<"List is empty!!"<<endl;
                return;
            }
            // if(size==1){                   // no need to do that 
            //     head = tail = NULL;
            //     size--;
            // }
            head = head->next;
            size--;
        }

        void deleteAtTail(){
            if(size==0){
                cout<<"List is empty!!"<<endl;
                return;
            }
            Node *temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            temp->next = NULL;
            tail = temp;
            size--;
        }

        void deleteAtIndex(int idx){
           if(size==0){
                cout<<"List is empty!!"<<endl;
                return;
            }
            if(idx<0 || idx>=size){
                cout<<"Invalid index"<<endl;
                return;
            } 
            else if(idx == 0) return deleteAtHead();
            else if(idx == size-1) return deleteAtTail();
            else{
                Node *temp = head;
                for(int i=1; i<=idx-1; i++){
                    temp = temp->next;
                }
                temp->next = temp->next->next;
                size--;
            }
        }

        void display(){
            Node *temp = head;
            while(temp != NULL){
                cout<<temp->value<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};

class LinkedList{  // without using tail pointer
    public:
        Node *head;
        LinkedList(){ head = NULL; }

        int size(){
            int count = 0;
            Node* temp = head;
            while(temp->next != NULL) count++;
            return count;
        }

        void insert_at_tail(Node* a){
            if(head == NULL){
                head = a;
                return;
            }
            Node* temp = head;
            while(temp->next != NULL) temp = temp->next;
            temp->next = a;
        }

        void delete_at_tail(){
            if(head == NULL){
                cout<<"Deletion is not possible as the size is zero"<<endl;
                return;
            }
            Node* temp = head;
            while(temp->next->next != NULL) temp = temp->next;
            temp->next = NULL;
        }

        void insert_at_head(Node* a){
            if(head == NULL){
                head = a;
                return;
            }
            a->next = head;
            head = a;
        }

        void delete_at_head(){
            if(head == NULL){
                cout<<"Deletion is not possible as the size is zero"<<endl;
                return;
            }
            head = head->next;
        }

        void insert_at_index(int index, int value){
            if(index<0 || index>size()-1){
                cout<<"Invalid index"<<endl;
                return;
            }
            if(index == 0){
                insert_at_head;
                return;
            }
            if(index == size()-1){
                insert_at_tail;
                return;
            }

            Node* temp = head;
            for(int i=0; i<index-1; i++) temp = temp->next;
            Node* t = new Node(value);

            // Node* a = temp->next;  // we can also do that
            // temp->next = t; 
            // t->next = a;

            t->next = temp->next;  // alternate method
            temp->next = t;
        }

        void delete_at_index(int index){
            if(index<0 || index>size()-1){
                cout<<"Invalid index"<<endl;
                return;
            }
            if(index == 0){
                delete_at_head;
                return;
            }
            if(index == size()-1){
                delete_at_tail;
                return;
            }

            Node* temp = head;
            for(int i=0; i<index-1; i++) temp = temp->next;
            temp->next = temp->next->next;
        }

        int get_index(Node* a){
            int index = 0;
            Node* temp = head;
            while(temp != NULL){
                if(temp == a) return index;
                temp = temp->next;
                index++;
            }
            return -1;  // return -1 if index not present of the given node
        }

        void display(){
            if(head == NULL) return;
            Node* temp = head;
            while(temp != NULL) cout<<temp->value<<" ";
        }

};

void display(Node *head);
void display_reverse(Node *head);
int size(Node *head);
void insertAtEnd(Node *head, int value);

int main(){

//**************************************************************************************************//   

    // Node a(10);  // making seperate nodes
    // Node b(20);  // constructor called automatically
    // Node c(30);
    // Node d(40);
    // // cout<<a.next<<endl;  // null will be printed

    // // making link between the nodes
    // a.next = &b; // it is analogus to [Node *ptr = &b; and ptr->value; ]
    // b.next = &c;
    // c.next = &d;  
    // // d.next = NULL; // no need to write this 

    // cout<<"Value of b: "<<b.value<<endl;
    // cout<<"Value of b: "<<(*(a.next)).value<<endl;   // a.next is a pointer, pointing the address of b
    // cout<<"Value of b: "<<(a.next)->value<<endl;  
    // cout<<"Changing value of b: "<<endl;
    // (a.next)->value = 200;    // we have accessed value of node b using pointer, now value can be changed
    // cout<<"Value of b: "<<(a.next)->value<<endl;
    // cout<<endl;

    // // now we can do same for all the nodes. we can access data using address of the node from the previous node
    // // now think of using only node 'a' to get access of all the nodes

    // // (a.next)->value  means value of node b
    // // (a.next)->next  means address of node c which is stored in node b
    // cout<<"Value of c: "<<c.value<<endl;
    // cout<<"Value of c: "<<(b.next)->value<<endl;  // accessing value of node c using node b
    // cout<<"Value of c: "<<((a.next)->next)->value<<endl;  // accessing value of node c using node a
    // cout<<"Value of c: "<<(*((*(a.next)).next)).value<<endl;  
    // cout<<endl;

    // // (a.next)->next // address of node c which is stored in node b
    // // ((a.next)->next)->next // address of node d which is stored in node c
    // cout<<"Value of d: "<<d.value<<endl;
    // cout<<"Value of d: "<<(c.next)->value<<endl;  // accessing value of node d using node c
    // cout<<"Value of d: "<<((b.next)->next)->value<<endl;  // accessing value of node d using node b
    // cout<<"Value of d: "<<(((a.next)->next)->next)->value<<endl;  // accessing value of node d using node a
    // cout<<"Value of d: "<<(*((*((*(a.next)).next)).next)).value<<endl;  

//**************************************************************************************************//   

    // Node a(10);  Node b(20);  Node c(30);Node d(40);
    // a.next = &b; b.next = &c;c.next = &d;  

    // Node temp = a;

    // // while((temp.next) != NULL){     // this condition will not let node 'd' to come in the loop
    // //     cout<<temp.value<<" ";
    // //     temp = *(temp.next);  // temp = temp->next
    // // }  // output 10 20 30  

    // while(1){ 
    //     cout<<temp.value<<" ";
    //     if((temp.next) == NULL) break;  // when node 'd' come it will break the loop after printing value of node 'd'
    //     temp = *(temp.next); // temp = temp->next
    // }

//**************************************************************************************************//   

    // Node *a = new Node(10);   Node *b = new Node(20);  Node *c = new Node(30);
    // Node *d = new Node(40);   Node *e = new Node(50);
    // a->next = b;   b->next = c;  c->next = d; d->next = e;

    // cout<<"Size of the linked list: "<<size(a)<<endl; // 4

    // // Node *temp = a; 
    // // while(temp != NULL){           
    // //     cout<<temp->value<<" ";
    // //     temp = temp->next;
    // // }
    // // cout<<endl<<endl;

    // display(a);          // it is known that 'a' is a pointer of node but it is also passed by value in the funtion 
    // cout<<endl<<endl;
    // display_reverse(a);  // displaying in reverse order
    // cout<<endl<<endl;

    // insertAtEnd(a,60);
    // display(a);           
    // cout<<endl<<endl;

//**************************************************************************************************//   


    return 0;
}

void display(Node *head){

    // while(head != NULL){        // it is known that 'a' is a pointer of node but it is also passed by value in the funtion
    //     cout<<head->value<<" ";   // that's we can directly use head it will not change the original linked list
    //     head = head->next;
    // }                             // time complexity -> O(n)   space complexity -> O(1)

    if(head == NULL) return;      // using recursion 
    cout<<head->value<<" ";       // if I print after calling display function, then it will be printed in reverse order 
    display(head->next);          // time complexity -> O(n)   space complexity -> O(n)

}

void display_reverse(Node *head){   // it will be easy to use recursion to print in reverse order
    if(head == NULL) return;      
    display_reverse(head->next);
    cout<<head->value<<" ";       
}

int size(Node *head){
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

void insertAtEnd(Node *head, int value){
    Node *temp = new Node(value);
    while(head->next != NULL) head = head->next;
    head->next = temp;
}