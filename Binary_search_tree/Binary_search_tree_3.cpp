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

TreeNode* trim_BST(TreeNode* root, int low, int high);  // Leetcode-669
void helper(TreeNode* root, int low, int high); 

vector<int> Morris_traversal(TreeNode* root);  // Leetcode-94

void flatten(TreeNode* root); // Leetcode-114
vector<TreeNode*> preorder_traversal(TreeNode* root);

int main(){

//***************************************************************************************************//   

    // Trim a binary search tree (Leetcode-669)

//*****************************************************************************************************//   

    // Inorder traversal with iterative method with space complexity: O(1) ---> Morris traversal (Leetcode-94)
    // now try to implement the previous question with morris traversal like (validate bst, inorder predecessor, etc)

//***************************************************************************************************//   

    // Flatten a binary tree into inliked list (Leetcode-114)

//***************************************************************************************************//   


    return 0;
}

TreeNode* trim_BST(TreeNode* root, int low, int high){  // (Leetcode-669) Trim a binary search tree
    TreeNode* dummy = new TreeNode(INT_MAX);
    dummy->left = root;
    helper(dummy,low,high);
    return dummy->left;
}
void helper(TreeNode* root, int low, int high){
    if(root == NULL) return;
    while(!root->left){
        if(root->left->value < low) root->left = root->left->right;
        else if(root->left->value > high) root->left = root->left->left;
        else break;
    }
    while(!root->right){
        if(root->right->value < low) root->right = root->right->left;
        else if(root->right->value > high) root->right = root->right->right;
        else break;
    }
    helper(root->left,low,high);
    helper(root->right,low,high);
}

vector<int> Morris_traversal(TreeNode* root){  // Morris traversal (Leetcode-94)
    vector<int> ans;
    TreeNode* curr = root;
    while(curr != NULL){
        if(curr->left != NULL){  // find predecessor and do some work
            TreeNode* pred = curr->left;
            while(pred->right != NULL && pred->right != curr) pred = pred->right;
            if(pred->right == NULL){ // make the connection
                pred->right = curr;
                curr = curr->left;
            }
            else{  // pred->right == curr it means unlink and do some work
                pred->right = NULL;
                ans.push_back(curr->value);
                curr = curr->right; 
            }
        }
        else{  // curr->left == NULL then visit the node and go right 
            ans.push_back(curr->value);
            curr = curr->right;   
        }
    }
    return ans;
}

void flatten(TreeNode* root){  // Flatten a binary tree into inliked list (Leetcode-114)

    //******************************** Method_1 ********************************//
    // vector<TreeNode*> ans = preorder_traversal(root);
    // int n = ans.size();                        // using vector of node* to store all the nodes
    // for(int i=0; i<n-1; i++){                      // space complexity: O(n)
    //     ans[i]->right = ans[i+1];
    //     ans[i]->left = NULL;
    // }

    //******************************** Method_2 ********************************//
    // if(root == NULL) return;
    // TreeNode* left = root->left;
    // TreeNode* right = root->right;
    // root->left = NULL;             // Time complexity: O(n)
    // root->right = NULL;           // here we are using reccursion, space complexity: O(n)
    // flatten(left);
    // flatten(right);
    // root->right = left;

    // TreeNode* temp = root;
    // while(temp->right != NULL) temp = temp->right;;
    // temp->right = right;
    
    //******************************** Method_3 ********************************//
    if(root == NULL) return;
    TreeNode* curr = root;
    while(curr != NULL){
        if(curr->left != NULL){  // save the right 
            TreeNode* right = curr->right;
            curr->right = curr->left;

            TreeNode* pred = curr->left;   // finding pred
            while(pred->right != NULL) pred = pred->right;  // by using morris traversal, space complexity: O(1)
  
            pred->right = right;  // Linking 
            curr = curr->right;
        }
        else curr = curr->right;
    }
    TreeNode* temp = root;
    while(temp->right != NULL){
        temp->left = NULL;
        temp = temp->right;
    }

}
vector<TreeNode*> preorder_traversal(TreeNode* root){
    vector<TreeNode*> ans;
    stack<TreeNode*> st;
    if(root != NULL) st.push(root);
    while(st.size()>0){
        TreeNode* temp = st.top();
        st.pop();ans.push_back(temp);
        if(temp->right != NULL) st.push(temp->right);
        if(temp->left != NULL) st.push(temp->left);
    }
    return ans;
}





