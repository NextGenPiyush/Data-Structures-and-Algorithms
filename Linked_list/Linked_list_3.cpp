#include<bits/stdc++.h>
using namespace std;

class ListNode{       
    public:
        int value;
        ListNode *next;  
        ListNode(int value){    
            this->value = value;
            next = NULL;
            // this->next = NULL;  // we can also do that 
        }
};

ListNode* middle_right(ListNode *head){
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast!=NULL && fast->next!=NULL){   // in case of even no of elements this function return right of the middle 
    // while(fast->next!=NULL && fast->next->next!=NULL){  // return left of the middle 
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;                          
}

ListNode* middle_left(ListNode *head){
    ListNode *slow = head;
    ListNode *fast = head;
    // while(fast!=NULL && fast->next!=NULL){   // in case of even no of elements this function return right of the middle 
    while(fast->next!=NULL && fast->next->next!=NULL){  // return left of the middle 
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;                          
}

void display(ListNode* head);
int size(ListNode* head);

ListNode* deleteDuplicate_from_sorted_list(ListNode* head);     // Remove duplicate from sorted list (Leetcode-83)

ListNode* rotateRight(ListNode* head, int k);  // rotate linkedlist (Leetcode-61)

ListNode* merge_list_1(ListNode* head1, ListNode* head2);  // merge 2 sorted list (Leetcode-21) -> space complexity: O(n)
ListNode* merge_list_2(ListNode* head1, ListNode* head2);  // merge 2 sorted list (Leetcode-21) -> space complexity: O(1)
ListNode* merge_k_lists(vector<ListNode*> &arr);  // merge K sorted lists (Leetcode-23)
ListNode* sortList(ListNode* head);   // sort list (Leetcode-148)

ListNode* partition_list(ListNode* head, int x);  // partition list (Leetcode-86)

ListNode* Reverse_list_1(ListNode* head);  // reversing a linked list (Leetcode-206) by changing value without changing links
ListNode* Reverse_list_2(ListNode* head);  // reversing a linked list (Leetcode-206) by changing links 
ListNode* Reverse_list_3(ListNode* head);  // reversing a linked list (Leetcode-206) recursive approach 
bool isPalindrome(ListNode* head);  // given linkedlist is palindrome or not (Leetcode-234)
bool isPalindrome_2(ListNode* head);  // given linkedlist is palindrome or not (Leetcode-234)

ListNode* reverse_part(ListNode* head, int left, int right);  // reverse the list from position left to right (Leetcode-92)

void reorder_list(ListNode* head);  // Reorder the list (Leetcode-143)

int main(){

//********************************************************************************************************************//  

    // ListNode *a = new ListNode(10);  ListNode *b = new ListNode(10);  ListNode *c = new ListNode(30);  // (Leetcode-83)
    // ListNode *d = new ListNode(40);  ListNode *e = new ListNode(50);  ListNode *f = new ListNode(50);
    // a->next = b;  b->next = c; c->next = d;  d->next = e; e->next = f;
    // display(a);
    // cout<<"After removing duplicate elements: "<<endl;
    // display(deleteDuplicate_from_sorted_list(a));

//********************************************************************************************************************//  

    // ListNode *a = new ListNode(10);   ListNode *b = new ListNode(10);   ListNode *c = new ListNode(30);
    // ListNode *d = new ListNode(40);   ListNode *e = new ListNode(40);   ListNode *f = new ListNode(50);
    // ListNode *g = new ListNode(50);
    // a->next = b;  b->next = c; c->next = d;  d->next = e; e->next = f; f->next = g;
    // display(a);
    // cout<<"Enter the rotation: ";
    // int n; cin>>n;
    // display(rotateRight(a,n));

//********************************************************************************************************************//  

    // spiral matrix 4 (leetcode-2326)  first do the spiral matrix problem which was discussed in the array
    // try to implement spirat matrx similar questions  

//********************************************************************************************************************//  

    // ListNode *a = new ListNode(1);    ListNode *b = new ListNode(2);    ListNode *c = new ListNode(5);
    // a->next = b;    b->next = c;

    // ListNode *d = new ListNode(2);    ListNode *e = new ListNode(3);    ListNode *f = new ListNode(4);
    // ListNode *g = new ListNode(6);    ListNode *h = new ListNode(7);    ListNode *i = new ListNode(8);
    // d->next = e;    e->next = f;    f->next = g;    g->next = h;    h->next = i;

    // display(a);
    // display(d);
    // cout<<"After merging the sorted lists: "<<endl;
    // display(merge_list_1(a,d));
    // display(merge_list_2(a,d));

//********************************************************************************************************************//  

    // ListNode *a = new ListNode(10);       ListNode *b = new ListNode(10);    ListNode *c = new ListNode(30);
    // ListNode *d = new ListNode(40);        ListNode *e = new ListNode(40);    ListNode *f = new ListNode(50);
    // ListNode *g = new ListNode(50);
    // a->next = b;  b->next = c; c->next = d;  d->next = e; e->next = f; f->next = g;
    // ListNode* head = a;
    // display(head);
    // cout<<"Displaying after reversing: "<<endl;
    // display(Reverse_list_1(head));
    // display(Reverse_list_2(head));  // reversing again print the original list 

//********************************************************************************************************************//  

    // ListNode *a = new ListNode(10);   
    // ListNode *b = new ListNode(23);
    // ListNode *c = new ListNode(30);
    // ListNode *d = new ListNode(40);    
    // ListNode *e = new ListNode(30);
    // ListNode *f = new ListNode(20);
    // ListNode *g = new ListNode(10);
    // a->next = b;  b->next = c; c->next = d;  d->next = e; e->next = f; f->next = g;
    // ListNode* head = a;
    // display(head);
    // if(isPalindrome_2(head)) cout<<"Given linked list is palindrome"<<endl;
    // else cout<<"Given linked list is not palindrome"<<endl;

//********************************************************************************************************************//  

    // ListNode *a = new ListNode(10);       ListNode *b = new ListNode(20);    ListNode *c = new ListNode(30);
    // ListNode *d = new ListNode(40);       ListNode *e = new ListNode(50);    ListNode *f = new ListNode(60);
    // ListNode *g = new ListNode(70);
    // a->next = b;  b->next = c; c->next = d;  d->next = e; e->next = f; f->next = g;
    // ListNode* head = a;
    // cout<<"Before reversing: "<<endl;
    // display(head);
    // cout<<"After reversing linked list from 2nd position to 6th position: "<<endl;
    // head = reverse_part(head,2,6);
    // display(head);

//********************************************************************************************************************//  

    ListNode *a = new ListNode(10);       ListNode *b = new ListNode(20);    ListNode *c = new ListNode(30);
    ListNode *d = new ListNode(40);       ListNode *e = new ListNode(50);    ListNode *f = new ListNode(60);
    ListNode *g = new ListNode(70);
    a->next = b;  b->next = c; c->next = d;  d->next = e; e->next = f; f->next = g;
    ListNode* head = a;
    cout<<"Displaying before reordering: "<<endl;
    display(head);
    cout<<"After reordering: "<<endl;
    reorder_list(head);
    display(head);

//********************************************************************************************************************//  

    return 0;
}

void display(ListNode *head){
    ListNode *temp = head;
    while(temp != NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int size(ListNode *head){
    int count = 0;
    ListNode *temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

ListNode* deleteDuplicate_from_sorted_list(ListNode* head){    // Leetcode-83
    if(head == NULL || head->next == NULL) return head;  
    ListNode *a = head;
    ListNode *b = head->next;
    while(b != NULL){   
        while(b != NULL && b->value == a->value) b = b->next;
        a->next = b;
        a = b;
        if(b != NULL) b = b->next;  // try ro implement this question using visited ListNode vector or hashmaps
    }
    return head;
}

ListNode* rotateRight(ListNode* head, int k){     // Leetcode-61
    if(head == NULL || head->next == NULL) return head;
    int n = 0;
    ListNode *temp = head;          // we can also solve it by slow fats method only when (k<n)
    ListNode *tail = NULL;          // go through the notes of the lecture 
    while(temp != NULL){
        if(temp->next == NULL) tail = temp;
        temp = temp->next;
        n++;
    }
    k = k%n;
    if(k == 0) return head;
    temp = head;
    for(int i=1; i<n-k; i++) temp = temp->next;
    tail->next = head;
    head = temp->next;
    temp->next = NULL;
    return head;
}

ListNode* merge_list_1(ListNode* head1, ListNode* head2){    // Leetcode-21  with space complexity O(n+m)
    ListNode* c = new ListNode(-1);
    ListNode*temp = c;
    ListNode* temp1 = head1;
    ListNode* temp2 = head2;
    while(temp1 != NULL && temp2 != NULL){
        ListNode* d;
        if(temp1->value <= temp2->value){
            d = new ListNode(temp1->value);
            temp1 = temp1->next;
        }
        else{
            d = new ListNode(temp2->value);
            temp2 = temp2->next;
        }
        temp->next = d;
        temp = d;
    }
    if(temp1 == NULL) temp->next = temp2;
    if(temp2 == NULL) temp->next = temp1;
    return c->next;
}

ListNode* merge_list_2(ListNode* head1, ListNode* head2){    // Leetcode-21  with space complexity O(1)
    ListNode* c = new ListNode(-1);
    ListNode* temp = c;
    ListNode* a = head1;
    ListNode* b = head2;
    while(a != NULL && b != NULL){
        if(a->value <= b->value){
            temp->next = a;
            a = a->next;
        }
        else{
            temp->next = b;
            b = b->next;
        }
        temp = temp->next;
    }
    if(a == NULL) temp->next = b;
    if(b == NULL) temp->next = a;
    return c->next;
}

ListNode* merge_k_lists(vector<ListNode*> &arr){    // Leetcode-23  
    if(arr.size() == 0) return NULL;
    while(arr.size()>1){
        // ListNode* a = arr[arr.size()-1];     // with bad time complexity O(nk^2)  
        // arr.pop_back();
        // ListNode* b = arr[arr.size()-1];
        // arr.pop_back();
        // arr.push_back(merge_list_2(a,b));   // no extra space required

        ListNode* a = arr[0];      // with better time complexity O(knlogk)  
        arr.erase(arr.begin());  // now element at 1st index will be at 0th index             
        ListNode* b = arr[0];  
        arr.erase(arr.begin());
        arr.push_back(merge_list_2(a,b));    // but while push_back it creats extra space as capacity will increase
    }
    return arr[0];
}

ListNode* sortList(ListNode* head){      // Leetcode-148
    if(head == NULL && head->next == NULL) return head; // base case
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){  
        slow = slow->next;
        fast = fast->next->next;
    }                                // merge sorto algorithm is used here to sort a list
    ListNode* a = head;
    ListNode* b = slow->next;
    slow->next = NULL;
    a = sortList(a);   
    b = sortList(b);
    ListNode* c = merge_list_2(a,b);
    return c;   
}

ListNode* partition_list(ListNode* head, int x){  // Leetcode-86
    ListNode* lo = new ListNode(-1);
    ListNode* hi = new ListNode(-1);
    ListNode* templo = lo;
    ListNode* temphi = hi;
    ListNode* temp = head;
    while(temp != NULL){
        if(temp->value < x){
            templo->next = temp;
            temp = temp->next;
            templo = templo->next;
        }
        else{
            temphi->next = temp;
            temp = temp->next;
            temphi = temphi->next;
        }
        templo->next = hi->next;
        temphi->next = NULL;
        return lo->next;
    }
}

ListNode* getNodeAt(ListNode* head, int idx){
    ListNode*temp = head;
    for(int i=1; i<=idx; i++) temp = temp->next;  // Time complexity: O(n)
    return temp;
}

ListNode* Reverse_list_1(ListNode* head){   // Leetcode-206  done by changing the value of the linked list 
    int length = 0;
    ListNode* temp = head;
    while(temp != NULL){
        temp = temp->next;
        length++;
    }
    int i=0, j=length-1;
    while(i<j){                 // Time complexity: O(n^2) 
        ListNode* left = getNodeAt(head,i);
        ListNode* right = getNodeAt(head,j);
        swap(left->value,right->value);
        i++; j--;
    }
    return head;
}

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

ListNode* Reverse_list_3(ListNode* head){       // recursive call to reverse the linked list 
    if(head == NULL && head->next == NULL) return head;  // not able to understand 
    ListNode* newHead = Reverse_list_3(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

bool isPalindrome(ListNode* head){    // Leetcode-234
    // int n = size(head);
    // int i=0, j=n-1;
    // while(i<j){                                        
    //     ListNode* left = getNodeAt(head,i);                   // Bad time complexity: O(n^2) due to getNodeAt function 
    //     ListNode* right = getNodeAt(head,j);                   // space complexity: O(1)
    //     if(left->value != right->value) return false; 
    //     i++; j--;
    // }
    // return true;

    ListNode* c = new ListNode(-1);
    ListNode* temp1 = head;
    ListNode* temp2 = c;
    while(temp1 != NULL){                           // Time complexity: O(n)
        ListNode* extra = new ListNode(temp1->value);       // space complexity: O(n)
        temp2->next = extra;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    // temp2->next = NULL;  // no need to write this 
    c = c->next;
    c = Reverse_list_2(c);  // Time complexity: O(n)

    temp1 = head; temp2 = c;
    while(temp1 != NULL){    // Time complexity: O(n)
        if(temp1->value != temp2->value) return false;
        temp1 = temp1->next; temp2 = temp2->next;
    }
    return true;
}

bool isPalindrome_2(ListNode* head){       //Leetcode-234
    ListNode* left = middle_left(head);
    ListNode* right = Reverse_list_2(left->next); 
    ListNode* a = head, *b = right;
    while(b != NULL){
        if(b->value != a->value) return false;
        b = b->next;
        a = a->next;
    }
    return true;
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

void reorder_list(ListNode* head){    // Leetcode-143 
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){   
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* b = Reverse_list_2(slow->next);
    ListNode* a = head;
    slow->next = NULL;

    ListNode* c = new ListNode(-1);
    ListNode* TempA = a;
    ListNode* TempB = b;
    ListNode* TempC = c;
    while(TempA && TempB){
        TempC->next = TempA;
        TempA = TempA->next;
        TempC = TempC->next;
        TempC->next = TempB;
        TempB = TempB->next;
        TempC = TempC->next;
    }
    TempC->next = TempA;   // Try to dry run with TemC->next = NULL as it will not run for odd length of string
    // TempC->next = NULL;
    head = c->next;
}






