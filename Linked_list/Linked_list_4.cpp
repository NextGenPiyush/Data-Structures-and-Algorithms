#include<bits/stdc++.h>
using namespace std;

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

class Node{  // Leetcode-138
    public:
        int value;
        Node* next;
        Node* random;
        Node(int value){
            this->value = value;
            next = NULL;
            random = NULL;
        }
};

class Node_2{  // Leetcode-430
    public:
        int value;
        Node_2* next;
        Node_2* prev;
        Node_2* child;
        Node_2(){
            this->value = value;
            next = NULL;
            prev = NULL;
            child = NULL;
        }
};

class LinkedList{    
    public:
        ListNode *head;
        ListNode *tail;   
        int size;
        LinkedList(){
            head = tail = NULL;
            size = 0;
        }
        
        void insertAtTail(int value){
            ListNode *temp = new ListNode(value);
            if(size == 0) head = tail = temp; 
            else{
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }
            size++;
        }

        void insertAtHead(int value){
            ListNode *temp = new ListNode(value);
            if(size == 0) head = tail = NULL;
            else{
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
            size++;
        }

        void insertAtIndex(int idx, int value){
            if(idx<0 || idx>size) cout<<"Invalid Index"<<endl;
            else if(idx == 0) insertAtHead(value);
            else if(idx == size) insertAtTail(value);
            else{
                ListNode *t = new ListNode(value);
                ListNode *temp = head;
                for(int i=1; i<=idx-1; i++) temp = temp->next;
                t->next = temp->next;   // try to omtimize this as we have done in getIndex() function
                temp->next = t;
                t->next->prev = t;
                t->prev = temp;
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
                ListNode *temp;
                if(idx<size/2){
                    temp = head;
                    for(int i=1; i<=idx; i++) temp = temp->next;
                }
                else{
                    temp = tail;
                    for(int i=1; i<size-idx; i++) temp = temp->prev;
                }
                return temp->value;
            }
        }

        void deleteAtHead(){
            if(size==0) return;  // list is empty
            head = head->next;
            if(head != NULL) head->prev = NULL;
            if(head == NULL) tail = NULL;
            size--;
        }

        void deleteAtTail(){
            if(size==0) return;  // list is empty
            else if(size==1){  // we can also handle the single node in the list by this way 
                deleteAtHead();
                return;
            }
            ListNode* temp = tail->prev;
            temp->next = NULL;
            tail = temp;
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
                ListNode *temp = head;     // try to omtimize this as we have done in getIndex() function
                for(int i=1; i<=idx-1; i++) temp = temp->next;
                temp->next = temp->next->next;
                temp->next->prev = temp;
                size--;
            }
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

void display_by_head(ListNode* head);
void display_by_tail(ListNode* tail);
void reverse_display_by_head(ListNode* head);
void reverse_display_by_tail(ListNode* tail);

vector<ListNode*> splitList(ListNode* head, int k);  // Leetcode-725

vector<int> nodesBetweenCriticalPoints(ListNode* head);  // Leetcode-2058

ListNode* Reverse_list_2(ListNode* head){  // done by changing the links/connections between them
    ListNode* prev = NULL;  // 3 Pointe technique
    ListNode* cur = head;
    ListNode* Next = NULL;
    while(cur != NULL){         // Time complexity: O(n)
        Next = cur->next;       // Space complexity: O(1)
        cur->next = prev;
        prev = cur;
        cur = Next;
    }
    return prev;
}
ListNode* reverse_part(ListNode* head, int left, int right){   // Leetcode-92
    if(left == right) return head;  
    ListNode *a = NULL; ListNode *b = NULL; ListNode *c = NULL; ListNode *d = NULL;
    ListNode* temp = head;
    int n = 1;
    while(temp != NULL){
        if(n==left-1) a = temp;
        if(n==left) b = temp;
        if(n==right) c = temp;
        if(n==right+1) d = temp;
        temp = temp->next;
        n++;
    }
    if(a) a->next = NULL;
    c->next = NULL;  
    c = Reverse_list_2(b);
    if(a) a->next = c;
    b->next = d;
    if(a) return head;  // try to dry run the wrong ans at leetcoode then only you would be able to get to this point
    else return c;
}
ListNode* reverseEvenLengthGroups(ListNode* head);  // Leetcode-2074

Node* copyRandomList(Node* head);  // Leetcode-138

Node_2* flatten(Node_2* head);  // Leetcode-430

int main(){

//**********************************************************************************************************************//

    // ListNode* a = new ListNode(10);  ListNode* b = new ListNode(20);  ListNode* c = new ListNode(30);
    // ListNode* d = new ListNode(40);  ListNode* e = new ListNode(50);  ListNode* f = new ListNode(60);
    // a->next = b;  b->next = c;  c->next = d;  d->next = e;  e->next = f;  f->next = NULL;
    // a->prev = NULL;  b->prev = a;  c->prev = b;  d->prev = c;  e->prev = d;  f->prev = e;
    // display_by_head(a);  cout<<endl;
    // display_by_tail(f);  cout<<endl;
    // reverse_display_by_head(a);  cout<<endl;
    // reverse_display_by_tail(f);  cout<<endl;

//**********************************************************************************************************************//

    // there are other types of the linkedList (Reffer lecture notes)
    //      1. Circular LinkedList
    //      1. Doubly Circular LinkedList

//**********************************************************************************************************************//

    return 0;
}

void display_by_head(ListNode* head){
    
    if(head == NULL) return;   // Iterative approach
    ListNode* temp = head;
    while(temp != NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    
    // if(head == NULL) return;  // Recursive approach
    // cout<<head->value<<" ";
    // display_by_head(head->next);
}

void display_by_tail(ListNode* tail){

    if(tail == NULL) return;   // Iterative approach
    ListNode* temp = tail;
    while(temp->prev != NULL) temp = temp->prev;
    display_by_head(temp);

    // if(tail == NULL) return;  // Recursive approach
    // display_by_tail(tail->prev);
    // cout<<tail->value<<" ";
}

void reverse_display_by_head(ListNode* head){

    if(head == NULL) return;   // Iterative approach
    ListNode* temp = head;
    while(temp->next != NULL) temp = temp->next;  
    reverse_display_by_tail(temp);

    // if(head == NULL) return;  // Recursive approach
    // reverse_display_by_head(head->next);
    // cout<<head->value<<" ";
}

void reverse_display_by_tail(ListNode* tail){

    if(tail == NULL) return;   // Iterative approach
    ListNode* temp = tail;
    while(temp != NULL){
        cout<<temp->value<<" ";
        temp = temp->prev;
    }

    // if(tail == NULL) return;  // Recursive approach
    // cout<<tail->value<<" ";
    // reverse_display_by_tail(tail->prev);
}

vector<ListNode*> splitList(ListNode* head, int k){  // Leetcode-725
    int n = 0;
    ListNode* temp = head;
    while(temp != NULL){
        temp = temp->next;
        n++;
    }
    vector<ListNode*> ans;
    int size = n/k, rem = n%k;
    temp = head;
    while(temp != NULL){
        ListNode* c = new ListNode(0);  // furzy_node
        ListNode* tempC = c;
        int s = size;
        if(rem>0) s++;
        rem--;
        for(int i=0; i<s; i++){
            tempC->next = temp;
            temp = temp->next;
            tempC = tempC->next;
        }
        tempC->next = NULL;
        ans.push_back(c->next);
    }
    if(ans.size()<k) for(int i=0; i<(k-ans.size()); i++) ans.push_back(NULL);
    return ans;
}

vector<int> nodesBetweenCriticalPoints(ListNode* head){  // Leetcode-2058
    int idx = 1, firstidx = -1, lastidx = -1;
    ListNode*a = head;
    ListNode*b = head->next;
    ListNode*c = head->next->next;
    if(c == NULL) return {-1,-1};
    while(c != NULL){
        if((b->value > a->value && b->value > c->value) || (b->value < a->value && b->value < c->value)){
            if(firstidx == -1) firstidx = idx;
            else lastidx = idx;
        }
        a = a->next;
        b = b->next;
        c = c->next;
        idx++;
    }
    if(lastidx == -1) return {-1,-1};  // it means either there is no or one critical point
    int max_diff_idx = lastidx-firstidx;

    int min_diff_idx = INT_MIN;
    firstidx = -1, lastidx = -1;
    a = head;
    b = head->next;
    c = head->next->next;
    while(c != NULL){
        if((b->value > a->value && b->value > c->value) || (b->value < a->value && b->value < c->value)){
            firstidx = lastidx;  // we can change variable names and can make this operating happen in singlw while loop
            lastidx = idx;
            if(firstidx != -1) min_diff_idx = min(min_diff_idx,lastidx-firstidx);
        }
        a = a->next;
        b = b->next;
        c = c->next;
        idx++;
    }
    return {min_diff_idx,max_diff_idx};
}

ListNode* reverseEvenLengthGroups(ListNode* head){  // Leetcode-2074
    ListNode* temp = head;
    int gap = 1;
    while(temp != NULL && temp->next != NULL){
        int remlength = 0;
        ListNode* t = temp->next;
        for(int i=1; i<=gap+1 && t!=NULL; i++){
            t = t->next;
            remlength++;
        }
        if(remlength<gap+1) gap = remlength-1;
        if(gap%2 != 0) reverse_part(temp,2,gap+2);
        gap++;
        for(int i=0; i<gap && temp!=NULL; i++) temp = temp->next;
    }
}

Node* copyRandomList(Node* head){  // Leetcode-138

    Node* dummy = new Node(0);    // step-1: Creat a deep copy of the original linkedlist 
    Node* temp = head;
    Node* tempD = dummy;
    while(temp != NULL){
        tempD->next = new Node(temp->value);
        temp = temp->next;
        tempD = tempD->next;
    }
    Node* duplicate = dummy->next;

    dummy = new Node(0);   // step-2: Make alternate connection between both teh linkedlist
    tempD = dummy;
    Node* a = head;
    Node* b = duplicate;
    while(a != NULL){
        tempD->next = a;
        a = a->next;
        tempD = tempD->next;
        tempD->next = b;
        b = b->next;
        tempD = tempD->next;
    }
    dummy = dummy->next;

    Node* t1 = dummy;   // step-3 assigning random pointers to the newly attached linkedList
    while(t1 != NULL){
        Node* t2 = t1->next;
        if(t1->random != NULL) t2->random = t1->random->next;
        t1 = t1->next->next;
    }

    Node* d1 = new Node(0);   // step-4 removing links between the linkedLists  
    Node* d2 = new Node(0);    
    t1 = d1;
    Node* t2 = d2;
    temp = dummy;
    while(temp != NULL){
        t1->next = temp;
        temp = temp->next;
        t1 = t1->next;
        t2->next = temp;
        temp = temp->next;
        t2 = t2->next;
    }
    t1->next = NULL;
    t2->next = NULL;
    d1 = d1->next;
    d2 = d2->next;

    return d2;
}

Node_2* flatten(Node_2* head){  // Leetcode-430
    Node_2* temp = head;
    while(temp != NULL){
        Node_2* a = temp->next;
        if(temp->child != NULL){
            Node_2* c = temp->child;
            temp->child = NULL;
            c = flatten(c);
            temp->next = c;
            c->prev = temp;
            while(c->next != NULL) c = c->next;
            c->next = a;
            if(a != NULL) a->prev = c;
        }
        temp = a;
    }
    return head;
}
