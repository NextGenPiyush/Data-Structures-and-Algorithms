#include<bits/stdc++.h>
using namespace std;

class Node{       
    public:
        int value;
        Node *next;  
        Node(int value){    
            this->value = value;
            next = NULL;
            // this->next = NULL;  // we can also do that 
        }
};

void display(Node *head);
Node* deleteNode(Node *head, Node *target);
Node* deleteNode(Node *head, int target); 
void deleteNode(Node *target);  // only target node is given, head node is not (Leetcode-237)
Node* middle(Node *head);   // return midle node of the linked lit (Leetcode-876)
Node* Remove_Nth_from_end(Node* head, int n); // remove Nth node from the end (Leetcode-19)
Node* Intersection(Node *head1, Node* head2); // intersection node where 2 list intersect (Leetcode-160)
bool LinkedList_cycle(Node *head);  // if there is a cycle in the linked list then return 1 else return 0 (Leetcode-141)
Node* LinkedList_cycle_start(Node *head); //if there is a cycle in the linked list, return cycle starting node (Leetcode-142)

int main(){

//***********************************************************************************************************//

    // Node *a = new Node(10);   Node *b = new Node(20);  Node *c = new Node(30);
    // Node *d = new Node(40);   Node *e = new Node(50);
    // a->next = b;  b->next = c;  c->next = d;  d->next = e;
    
    // Node *head = a;
    // cout<<"Displaying linked list: "<<endl;
    // display(head);

    // head = deleteNode(head,d);  // deleting 4th node
    // display(head);

    // head = deleteNode(head,b); // deleting 2nd node
    // display(head);

    // head = deleteNode(head,30);
    // display(head);

    // head = deleteNode(head,10);
    // display(head);

    // head = deleteNode(head,50);
    // display(head);

//*********************************************************************************************************//

    // Node *a = new Node(10);  Node *b = new Node(20);  Node *c = new Node(30);
    // Node *d = new Node(40);  Node *e = new Node(50);
    // a->next = b;  b->next = c;  c->next = d;  d->next = e;

    // display(a);
    // deleteNode(a);  display(a);

    // deleteNode(a);  // now points to the second node 
    // display(a);

//*********************************************************************************************************//

    // Node *a = new Node(10);   Node *b = new Node(20);  Node *c = new Node(30);
    // Node *d = new Node(40);   Node *e = new Node(50);

    // a->next = b;  b->next = c;  c->next = d;  d->next = e;
    // // Node *f = new Node(50);    // dry run for both even and odd number of nodes in the linked list
    // // e->next = f;

    // cout<<"Middle node in the linked list: "<<endl;
    // cout<<"Value: "<<middle(a)->value<<endl;
    // cout<<"next value: "<<middle(a)->next->value<<endl;

//*********************************************************************************************************//

    // delete the middle node of the linked list 

//*********************************************************************************************************//

    // Node *a = new Node(10);
    // Node *b = new Node(20);
    // Node *c = new Node(30);
    // Node *d = new Node(40);
    // Node *e = new Node(50);
    // a->next = b;               
    // b->next = c;
    // c->next = d;
    // d->next = e;
    // int n;
    // display(a);
    // cout<<"Enter node from the last you want to delete(1-5): ";
    // cin>>n;
    // // Node* head = Remove_Nth_from_end(a,n);
    // display(Remove_Nth_from_end(a,n));

//*********************************************************************************************************//

    // Node *a = new Node(10);    // bad approach
    // Node *b = new Node(20);
    // Node *c = new Node(30);
    // Node *d = new Node(40);
    // Node *e = new Node(50);
    // Node *f = new Node(60);
    // Node *g = new Node(70);
    // Node *h = new Node(80);

    // a->next = b; b->next = c; c->next = d; d->next = e;
    // f->next = g; g->next = h; h->next = d;

    // vector<Node*> v;
    
    // Node* temp = a;              // temp = head1
    // while(temp != NULL){
    //     v.push_back(temp);
    //     temp = temp->next;
    // }
    // // for(int i=0; i<v.size(); i++){  you can check after pushback by printing
    // //     cout<<v[i]<<endl;
    // // }
    // int i = 0;
    // bool flag = false;
    // temp = f;     // temp = head2
    // while(temp != NULL){
    //     if(v[i] == temp){
    //         cout<<"Value "<<temp->value<<" containing node is the intersection node"<<endl;
    //         flag = true;
    //         break;
    //     }
    //     temp = temp->next;
    //     i++;
    // }
    // if(flag == false){
    //     cout<<"There is no intersection point in the linked list "<<endl;
    // }

//*********************************************************************************************************//

    // Node *a = new Node(10);
    // Node *b = new Node(20);
    // Node *c = new Node(30);
    // Node *d = new Node(40);
    // Node *e = new Node(50);
    // Node *f = new Node(60);
    // Node *g = new Node(70);
    // Node *h = new Node(80);

    // a->next = b; b->next = c; c->next = d; d->next = e; // intersection at d
    // f->next = g; g->next = h; h->next = d;

    // // a->next = b; b->next = c; c->next = d; d->next = e; e->next = f; f->next = g; g->next = h;  // no intersection

    // display(a);  // linkedlist-1
    // display(f);  // linkedlist-2
    // Node *ans = Intersection(a,f);  // if Intersection(a,a) then first node will be the intersection node
    // if(ans == NULL) cout<<"There is no intersection point"<<endl;
    // else cout<<"Intersection node value: "<<ans->value<<endl;

//*********************************************************************************************************//

    // Node *a = new Node(10);
    // Node *b = new Node(20);
    // Node *c = new Node(30);
    // Node *d = new Node(40);
    // Node *e = new Node(50);
    // Node *f = new Node(60);
    // Node *g = new Node(70);
    // Node *h = new Node(80);

    // // a->next = b; b->next = c; c->next = d; d->next = e; e->next = f; f->next = g; g->next = h; h->next = d;
    // // a->next = b; b->next = c; c->next = d; d->next = e; e->next = f; f->next = g; g->next = h; 
    // a->next = a;
    // if(LinkedList_cycle(a)){
    //     cout<<"There is a cycle in the linkedlist"<<endl;
    //     cout<<"Start at: "<<LinkedList_cycle_start(a)->value<<endl;
    // }
    // else cout<<"There is no cycle in the linkedlist"<<endl;

//*********************************************************************************************************//

    return 0;
}

void display(Node *head){
    Node *temp = head;
    if(temp == NULL){
        cout<<"Linked list is empty!! "<<endl;
        return;
    }
    while(temp != NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* deleteNode(Node *head, Node *target){
    if(head == target){
        head = head->next;
        return head;
    }
    Node *temp = head;
    while(temp->next != target) temp = temp->next;
    temp->next = temp->next->next;
    return head; 
}

Node* deleteNode(Node *head, int target){
    if(head->value == target){
        head = head->next;
        return head;
    }
    Node *temp = head;
    while(temp->next->value != target) temp = temp->next;
    temp->next = temp->next->next;
    return head;
} 

void deleteNode(Node *target){             // leetcode-237 Delete node in linkedList
    target->value = target->next->value;
    target->next = target->next->next;
}  

Node* middle(Node *head){      // leetcode-876 Middle of the linked list 

    // int count = 0;
    // Node *temp = head;
    // while(temp != NULL){
    //     count++;
    //     temp = temp->next;
    // }
    // temp = head;  // you can also make a new temp pointer here, but I have used the previous one 
    // int mid = count/2;
    // for(int i=1; i<=mid; i++){
    //     temp = temp->next;
    // }
    // return temp;

    Node *slow = head;
    Node *fast = head;
    // while(fast->next!=NULL && fast!=NULL){   // this will give error, try to dry run this code as there is a chance
                                                // where fast jump to null then null->next is not possible reusult in error
    while(fast!=NULL && fast->next!=NULL){   // in case of even no of elements this function return right of the middle 
    // while(fast->next!=NULL && fast->next->next!=NULL){  // return left of the middle 
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;                          
}

Node* Remove_Nth_from_end(Node* head, int n){    // leetcode-19 Remove Nth node from the end and return the head 

    // int length = 0;
    // Node* temp = head;
    // while(temp != NULL){
    //     length++;
    //     temp = temp->next;
    // }
    // if(n == length){  // important condition 
    //     head = head->next;
    //     return head;
    // }
    // int m = length-n+1; // if Nth from end then Mth from start
    // int idx = m-1;
    // temp = head;
    // for(int i=1; i<=idx-1; i++) temp = temp->next;
    // temp->next = temp->next->next;
    // return head;

    Node* slow = head;  // alternate approach 
    Node* fast = head;
    for(int i=1; i<=n+1; i++){
        if(fast == NULL) return head->next; // try to dry run this loop 
        fast = fast->next;
    }
    while(fast != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return head;
}

Node* Intersection(Node *head1, Node* head2){  // Leetcode-160 Find intersection if any else return NULL
    int length1 = 0,  length2 = 0;
    Node* temp1 = head1;  Node* temp2 = head2;
    while(temp1 != NULL){
        length1++;
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        length2++;
        temp2 = temp2->next;
    }
    temp1 = head1;
    temp2 = head2;
    if(length1 > length2) for(int i=1; i<=(length1-length2); i++) temp1 = temp1->next;
    if(length2 > length1) for(int i=1; i<=(length2-length1); i++) temp2 = temp2->next;
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1;  // return temp2
}

bool LinkedList_cycle(Node *head){  // Leetcode-141 check if is there any cycle in the linkedlist 
    Node *slow = head;
    Node *fast = head;
    while(fast!=NULL && fast->next!=NULL){     // try to implement the mathematical proof of the expression
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow) return true;  // try ro implement this question using visited ListNode vector or hashmaps
    }
    return false;
}

Node* LinkedList_cycle_start(Node *head){  // Leetcode-142 return cycle start node in the linkedlist 
    Node *slow = head;
    Node *fast = head;
    bool flag = false;
    while(fast!=NULL && fast->next!=NULL){    
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow){
            flag = true;
            break;
        }
    }
    if(flag == false) return NULL;
    else{
        Node *temp = head;
        while(temp != slow){       // try to implement mathematical proof of the expression
            slow = slow->next;
            temp = temp->next;
        } 
        return slow;
    }
}