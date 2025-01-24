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
};

void display(TreeNode* root){
    if(root == NULL) return;
    cout<<root->value<<" ";
    display(root->left);     // we can also write display(root->right) first 
    display(root->right);    // will se the another way of printing in next lecture 
}

int sum(TreeNode* root);
int size(TreeNode* root);

int max_node_val(TreeNode* root);

int levels(TreeNode* root);

int diameter_of_binary_tree(TreeNode* root);   // Maximum diameter problem (Leetcode-543)
void helper_1(TreeNode* root, int &maxDia);

bool same_tree(TreeNode* root1, TreeNode* root2);  // tree are same or not (Leetcode-100)

TreeNode* invert_binary_tree(TreeNode* root);  //invert the binary tree (Leetcode-226)

vector<string> binary_tree_path(TreeNode* root);  // (Leetcode-257)
void helper_3(TreeNode* root, string s, vector<string> &v);

TreeNode* lowest_common_ancestor(TreeNode* root, TreeNode* p, TreeNode* q); // (Leetcode-236)
bool exist(TreeNode* root, TreeNode* target);

int main(){

//**********************************************************************************************************//

    // TreeNode* a = new TreeNode(1);    TreeNode* b = new TreeNode(2);    TreeNode* c = new TreeNode(3);    
    // TreeNode* d = new TreeNode(4);  
    // TreeNode* e = new TreeNode(5);    TreeNode* f = new TreeNode(6);    TreeNode* g = new TreeNode(7);
    // a->left = b; a->right = c; b->left = d; b->right = e; c->left = f; c->right = g;

    // cout<<"Displaying tree: "<<endl; display(a); cout<<endl;

    // cout<<"Sum of elemets of the tree: "<<sum(a)<<endl;
    // cout<<"Size of the tree: "<<size(a)<<endl;
    // cout<<"Maximum value node: "<<max_node_val(a)<<endl;
    // cout<<"Levels in the tree: "<<levels(a)<<endl;

//************************************************************************************************************//

    // TreeNode* a = new TreeNode(-1);
    // TreeNode* b = new TreeNode(-2);
    // TreeNode* c = new TreeNode(-3);
    // TreeNode* d = new TreeNode(-4);
    // TreeNode* e = new TreeNode(-5);
    // TreeNode* f = new TreeNode(-6);
    // TreeNode* g = new TreeNode(-7);
    // a->left = b; a->right = c; b->left = d; b->right = e; c->left = f; c->right = g;
    // cout<<"Maximum value node: "<<max_node_val(a)<<endl;   // ans will be 0 if we have returned 0 in the base case
    // // as zero is the maximum elements after returning in the base case 

//************************************************************************************************************//

    // Binary tree are those which has atmost 2 children
    
    // full binary tree are those which have either 0 or 2 children
    
    // generic trees has no limitation on children
    
    // perfect binary trees are those which have 0 children in leaf nodes and 2 children of other node
    
    // complete binary tree are those in which nodes are attached in the order of completion of level from left to right
    
    // Balanced binary tree in which for every node the difference between the levels of the right subtree and left 
    // subtree is atmost 1

    // degenerate and skewed binary tree are thosw which has atmost 1 child

//**********************************************************************************************************//

    return 0;
}

int sum(TreeNode* root){      // we can also implement the product of all the nodes of the binary tree
    if(root == NULL) return 0;  // while calculating product we will return 1 as 0 wil make the ans zero
    return root->value + sum(root->left) + sum(root->right);
}

int size(TreeNode* root){
    if(root == NULL) return 0;
    return 1 + size(root->left) + size(root->right);
}

int max_node_val(TreeNode* root){          // similarly try to implement minimum value node
    if(root == NULL) return INT_MIN;   // can write return 0; if we have only positive elements of the tree
    // return max(root->value, max(max_node_val(root->left), max_node_val(root->right)));
    return max({root->value, max_node_val(root->left), max_node_val(root->right)});  //can also write like this 
}

int levels(TreeNode* root){      // hieght will be eqaul to the (level-1)       
    if(root == NULL) return 0;
    return 1 + max(levels(root->left), levels(root->right));;
    // int hieght = lev-1;   
    // return hieght;
}

int diameter_of_binary_tree(TreeNode* root){    // Maximum diameter problem (Leetcode-543)
    int maxDia = 0;                      
    helper_1(root, maxDia);
    return maxDia;
}
void helper_1(TreeNode* root, int &maxDia){  //can also a global variable instead of passing in this function
    // try to implement this using static variable type
    if(root == NULL) return;
    int dia = levels(root->left) + levels(root->right);
    maxDia = max(dia,maxDia);
    helper_1(root->left,maxDia);    // traversing using recursion
    helper_1(root->right,maxDia);
}

bool same_tree(TreeNode* root1, TreeNode* root2){  // tree are same or not (Leetcode-100)
    if(root1 == NULL && root2 == NULL) return true;  //means there is no tree and both have reached to the end 
    if(root1 == NULL || root2 == NULL) return false; // we can also write this below line 
    // if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)) return false;  
    if(root1->value != root2->value) return false;

    // if(!same_tree(root1->left,root2->left)) return false;
    // if(!same_tree(root1->right,root2->right)) return false;
    // return true;
    return same_tree(root1->left,root2->left) && same_tree(root1->right,root2->right); //can also write like this
    // if any function return 0 in above case then the and operating will give final return 0 
}

TreeNode* invert_binary_tree(TreeNode* root){  //invert the binary tree (Leetcode-226)
    if(root == NULL) return NULL;    // try to implement symetric tree question
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invert_binary_tree(root->left);
    invert_binary_tree(root->right);
    return root;
}

vector<string> binary_tree_path(TreeNode* root){  // return all the binary tree path as a string (Leetcode-257)
    vector<string> v;
    helper_3(root,"",v);
    return v;
}
void helper_3(TreeNode* root, string s, vector<string> &v){
    if(root == NULL) return;
    string a = to_string(root->value);
    if(root->left == NULL && root->right == NULL){
        s += a;
        v.push_back(s);
        return;
    }
    helper_3(root->left,s+a+"->",v);
    helper_3(root->right,s+a+"->",v);
}

TreeNode* lowest_common_ancestor(TreeNode* root, TreeNode* p, TreeNode* q){  // (Leetcode-236)
    // if(root == p || root == q) return root;
    // else if(exist(root->left,p) && exist(root->right,q)) return root;
    // // else if(!exist(root->left,p) && !exist(root->right,q)) return root;
    // else if(exist(root->right,p) && exist(root->left,q)) return root;   // we can also write above line 
    // else if(exist(root->left,p) && !exist(root->right,q)) return lowest_common_ancestor(root->left,p,q);
    // else return lowest_common_ancestor(root->right,p,q);

    if(exist(root->left,p) && !exist(root->right,q)) return lowest_common_ancestor(root->left,p,q);
    else if(!exist(root->left,p) && exist(root->right,q)) return lowest_common_ancestor(root->right,p,q);
    else return root; // this condition (root == p || root == q) will be come under this else condition 
}
bool exist(TreeNode* root, TreeNode* target){
    if(root == NULL) return false;
    if(root == target) return true;
    return exist(root->left,target) || exist(root->right,target);
}