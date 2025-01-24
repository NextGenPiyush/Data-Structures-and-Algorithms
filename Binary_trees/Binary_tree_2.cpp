#include<bits/stdc++.h>
using namespace std;

class TreeNode{            
    public:
        int value;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int value){
            this->value = value;
            this->left = NULL;
            this->right = NULL;
        }
        TreeNode(void){
            value = 0;
            left = NULL;
            right = NULL;
        }
};

void preorder(TreeNode* root);      // Leetcode-144
void inorder(TreeNode* root);       // Leetcode-94
void postorder(TreeNode* root);     // Leetcode-145

void rev_preorder(TreeNode* root);
void rev_inorder(TreeNode* root);
void rev_postorder(TreeNode* root);

void print_nth_level_1(TreeNode* root, int n);
void print_nth_level_2(TreeNode* root, int curr, int lev);

void level_order_traversal(TreeNode* root);  // try to solve leetcode-102 with this approach           
int levels(TreeNode* root);

vector<vector<int>> level_order(TreeNode* root);  // Binary tree level order (Leetcode-102)
void helper(TreeNode* root, vector<vector<int>> &ans, int level);

void level_order_queue(TreeNode* root);  // level order traversal using queue

TreeNode* construct_tree(int arr[], int n); 

int main(){

//**********************************************************************************************************************//   

    // TreeNode* a = new TreeNode(1);
    // TreeNode* b = new TreeNode(2);
    // TreeNode* c = new TreeNode(3);
    // TreeNode* d = new TreeNode(4);
    // TreeNode* e = new TreeNode(5);
    // TreeNode* f = new TreeNode(6);
    // TreeNode* g = new TreeNode(7);
    // a->left = b; a->right = c; b->left = d; b->right = e; c->left = f; c->right = g;
    // cout<<"Preorder: "; preorder(a); cout<<endl;
    // cout<<"Inorder: "; inorder(a); cout<<endl;
    // cout<<"Postorder: "; postorder(a); cout<<endl;
    // cout<<"revPreorder: "; rev_preorder(a); cout<<endl;
    // cout<<"revInorder: "; rev_inorder(a); cout<<endl;
    // cout<<"revPostorder: "; rev_postorder(a); cout<<endl;
    // cout<<"Level order traversal"<<endl;
    // level_order_traversal(a);
    // level_order_queue(a);

//**********************************************************************************************************************//   

    // TreeNode* a = new TreeNode(1);
    // TreeNode* b = new TreeNode(2);
    // TreeNode* c = new TreeNode(3);
    // TreeNode* d = new TreeNode(4);
    // TreeNode* e = new TreeNode(5);
    // TreeNode* f = new TreeNode(6);
    // TreeNode* g = new TreeNode(7);
    // a->left = b; a->right = c; b->left = d; b->right = e; c->left = f; c->right = g;
    // // print_nth_level(a,3);   cout<<endl;
    // // print_nth_level(a,2);   cout<<endl;
    // // print_nth_level(a,1);   cout<<endl;
    // print_nth_level(a,1,3);  cout<<endl;
    // print_nth_level(a,1,2);  cout<<endl;
    // print_nth_level(a,1,1);  cout<<endl;

//**********************************************************************************************************************//   

    // Leetcode-102 Binary tree level order traversal using simple approach (Using nth level function)
    // and using queue data structure 

//**********************************************************************************************************************//   

    // Leetcode-103 Binary tree zigzag level order traversal (Homework)

//**********************************************************************************************************************//   

    int arr[] = {1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};  // here INT_MIN represent NULL 
    int n = sizeof(arr)/sizeof(arr[0]); 
    TreeNode* root = construct_tree(arr,n); // if we pass vector there is no need to pass size of the vector 
    level_order_traversal(root);     

//**********************************************************************************************************************//   


    return 0;
}

void preorder(TreeNode* root){   // Leetcode-144       
    if(root == NULL) return;        // space complexity: O(level+1)=O(hieght+2)=O(hieght)=O(h)
    cout<<root->value<<" ";         // space complexity: average/worst case: O(n)
    preorder(root->left);           // space complexity: best case: O(logn)
    preorder(root->right);          // time complexity: O(n) where n is the number of nodes
}

void inorder(TreeNode* root){     // Leetcode-94
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->right);
}

void postorder(TreeNode* root){     // Leetcode-145
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->value<<" ";
}

void rev_preorder(TreeNode* root){
    if(root == NULL) return;
    rev_preorder(root->right);
    rev_preorder(root->left);
    cout<<root->value<<" ";
}

void rev_inorder(TreeNode* root){
    if(root == NULL) return;
    rev_inorder(root->right);
    cout<<root->value<<" ";
    rev_inorder(root->left);
}

void rev_postorder(TreeNode* root){
    if(root == NULL) return;
    cout<<root->value<<" ";
    rev_postorder(root->right);
    rev_postorder(root->left);
}

void print_nth_level_1(TreeNode* root, int n){
    if(root == NULL) return;
    // if(n == 1) cout<<root->value<<" ";
    if(n == 1){  // more optimized as no need to go deper as we got our level
        cout<<root->value<<" ";    // no matter you apply pre, in, post order it will print the same 
        return;
    }
    // print_nth_level_1(root->right,n-1);     // for right to left  
    // print_nth_level_1(root->left,n-1);
    print_nth_level_1(root->left,n-1);    // for left to right
    print_nth_level_1(root->right,n-1);
}
void print_nth_level_2(TreeNode* root, int curr, int lev){
    if(root == NULL) return;
    // if(curr == lev) cout<<root->value<<" ";
    if(curr == lev){       // more optimized
        cout<<root->value<<" ";   // no matter you apply pre, in, post order it will print the same 
        return;
    }
    // print_nth_level_2(root->left,curr+1,lev);   // for left to right
    // print_nth_level_2(root->right,curr+1,lev);
    print_nth_level_2(root->right,curr+1,lev);   // for right to left
    print_nth_level_2(root->left,curr+1,lev);
}

int levels(TreeNode* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left), levels(root->right));
}
void level_order_traversal(TreeNode* root){
    for(int i=1; i<=levels(root); i++){
        print_nth_level_1(root,i);   // we can also make vector every time before loop and pass into function
        // print_nth_level_2(root,1,i);  //...we can pushback the vector into 2d vector, 
        // but this approach is not optimized 
    }
}

vector<vector<int>> level_order(TreeNode* root){  // Binary tree level order (Leetcode-102)
    int n = levels(root);
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){      // ans will contain n empty vectors of integers.
        vector<int> v;    // these lines will make code more optimized
        ans.push_back(v);
    }
    // vector<vector<int>> ans(n); // Creates a vector with `n` empty vectors
    helper(root,ans,0);
    return ans;
}
void helper(TreeNode* root, vector<vector<int>> &ans, int level){  // more optimized way of doing this problem  
    if(root == NULL) return;
    ans[level].push_back(root->value);  // instead of printing in nth level function we can pushback in vector 
    helper(root->left,ans,level+1);  // for left to right    
    helper(root->right,ans,level+1);
    // helper(root->right,ans,level+1);  // for right to left 
    // helper(root->left,ans,level+1);      
}

void level_order_queue(TreeNode* root){  // but there is a problem how can we insert it into 2d vector
    queue<TreeNode*> q;                 // as it will print in the single line 
    q.push(root);  
    while(q.size()>0){  // while queue is not empty
        TreeNode* temp = q.front(); q.pop(); 
        cout<<temp->value<<" ";
        if(temp->left != NULL) q.push(temp->left); // for level order traversal  (Left to right printing)
        if(temp->right != NULL) q.push(temp->right);
        // if(temp->right != NULL) q.push(temp->right);  // for level order traversal (right to left printing)
        // if(temp->left != NULL) q.push(temp->left);
    }
    cout<<endl;
}

TreeNode* construct_tree(int arr[], int n){   // constructing binary tree using BFS (Queue)
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(arr[0]);  q.push(root);
    int i=1,j=2;
    while(q.size()>0 && i<n){ // we will handle the case when i<n but j==n 
        TreeNode* temp = q.front(); q.pop();

        TreeNode* leftnode, *rightnode;
        if(arr[i] != INT_MIN) leftnode = new TreeNode(arr[i]);
        else leftnode = NULL; 
        if(j!=n && arr[j] != INT_MIN) rightnode = new TreeNode(arr[j]); //handle case (only j is out of array) 
        else rightnode = NULL;

        temp->left = leftnode; 
        temp->right = rightnode; 

        if(leftnode != NULL) q.push(leftnode);
        if(rightnode != NULL) q.push(rightnode);
        i+=2; j+=2;
    }
    return root;
}




