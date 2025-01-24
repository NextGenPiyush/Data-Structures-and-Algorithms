#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int value;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int value){
            this->value = value;
            left = NULL;
            right = NULL;
        }
        TreeNode(void){
            value = 0;
            left = NULL;
            right = NULL;
        }
};

int product(TreeNode* root);
void final_product(TreeNode* root, int &product);

int min_value(TreeNode* root);
void min_value_of_tree(TreeNode* root, int &minimum);

bool is_balanced(TreeNode* root);   // Leetcode-110 Balanced Binary tree
int level(TreeNode* root);

bool is_symmetric(TreeNode* root);  // Leetcode-101 symmetric tree
bool sym(TreeNode* left, TreeNode* right);

int main(){

//*******************************************************************************************************//

    // TreeNode* a = new TreeNode(1);
    // TreeNode* b = new TreeNode(2);
    // TreeNode* c = new TreeNode(3);
    // TreeNode* d = new TreeNode(4);
    // TreeNode* e = new TreeNode(5);
    // TreeNode* f = new TreeNode(6);
    // TreeNode* g = new TreeNode(7);
    // a->left = b; a->right = c; b->left = d; b->right = e; c->left = f; c->right = g;
    // TreeNode* root = a;
    // int product = root->value;
    // final_product(root,product);
    // cout<<"Product of the nodes: "<<product<<endl;

//******************************************************************************************************//

    // TreeNode* a = new TreeNode(100);
    // TreeNode* b = new TreeNode(2);
    // TreeNode* c = new TreeNode(3);
    // TreeNode* d = new TreeNode(4);
    // TreeNode* e = new TreeNode(5);
    // TreeNode* f = new TreeNode(6);
    // TreeNode* g = new TreeNode(7);
    // a->left = b; a->right = c; b->left = d; b->right = e; c->left = f; c->right = g;
    // TreeNode* root = a;
    // int minimum = root->value;
    // min_value_of_tree(a,minimum);
    // cout<<"Minimum value of the tree: "<<minimum<<endl;

//******************************************************************************************************//



//******************************************************************************************************//



//********************************************************************************************************//


    return 0;
}

int product(TreeNode* root){  
    if(root == NULL) return 1;
    return root->value * product(root->left) * product(root->right);
}
void final_product(TreeNode* root, int &product){     //we can also do that by another approach
    // if(root == NULL) return ;
    if(!root) return; // both have same meaning 
    if(root->left) product *= root->left->value;
    if(root->right) product *= root->right->value;
    final_product(root->left,product);
    final_product(root->right,product);
}

int min_value(TreeNode* root){
    if(root == NULL) return INT_MAX;  // returning becauase we don't want to consider the NULL root
    return min(root->value, min(min_value(root->left), min_value(root->right)));
}
void min_value_of_tree(TreeNode* root, int &minimum){  // alternate approach
    if(!root) return;
    if(root->left) minimum = min(minimum,root->left->value);
    if(root->right) minimum = min(minimum,root->right->value);
    min_value_of_tree(root->left,minimum);
    min_value_of_tree(root->right,minimum);
}

bool is_balanced(TreeNode* root){   // Leetcode-110 Balanced Binary tree   
    // if(root == NULL) return true;    // By definition, an empty tree is considered balanced  
    // if(level(root->left)>level(root->right)){
    //     if(level(root->left)-level(root->right)<=1) return true;
    //     else return false;
    // }
    // else{
    //     if(level(root->right)-level(root->left)<=1) return true;
    //     else return false;
    // }
    // if(is_balanced(root->left) && is_balanced(root->right)) return true;
    // return false;

    if(!root) return true;  // we can also do that 
    int hieghtleft = level(root->left);
    int hieghtright = level(root->right);
    if(abs(hieghtleft - hieghtright) > 1) return false;
    bool leftans = is_balanced(root->left);
    if(!leftans) return false;
    bool rightans = is_balanced(root->right);
    if(!rightans) return false;
    return true; // we can also write return [is_balanced(root->left) && is_balanced(root->right)]
}
int level(TreeNode* root){
    if(root == NULL) return 0;
    return 1 + max(level(root->left), level(root->right));
}

bool is_symmetric(TreeNode* root){   // Leetcode-101 symmetric tree
    // if(root == NULL) return true;
    // return sym(root->left, root->right);

    if(!root) return true;
    queue<TreeNode*> q1,q2;   // Not able to think the solution 
    q1.push(root->left);
    q2.push(root->right);

    while(!q1.empty() and !q2.empty()){  
        TreeNode* p = q1.front();
        q1.pop();
        TreeNode* q = q2.front();
        q2.pop();

        if(!p and !q) continue;  // if both are NUll 
        if(!p or !q) return false;  // if any one is NULL
        if(p->value != q->value) return false;
        q1.push(p->left); q1.push(p->right);
        q2.push(q->right); q2.push(q->left);    
    }
    return true;
}

bool sym(TreeNode* left, TreeNode* right){
    if(left == NULL and right == NULL) return true;   //if(!left and !right)
    if(left == NULL or right == NULL) return false;   //if(!left or !right)
    return (left->value == right->value and sym(left->left, right->right) and sym(left->right, right->left));
}






