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

TreeNode* deleteNode(TreeNode* root, int key);  // Leetcode-450 Delete node in a BST
TreeNode* iop(TreeNode* root);   // inorder predecessor
TreeNode* iosc(TreeNode* root);  // Inorder sucessor

int main(){

//************************************************************************************************************//

    // Inorder predecessor and successor
    // preorder predecessor and successor
    // postorder predecessor and successor

//**************************************************************************************************************//

    return 0;
}

TreeNode* deleteNode(TreeNode* root, int key){    // Leetcode-450
    if(root == NULL) return NULL;
    if(root->value == key){
        if(root->left == NULL && root->right == NULL) return NULL; // 0 child node
        if(root->left == NULL || root->right == NULL){  // 1 child node
            if(root->left != NULL) return root->left;
            else return root->right;
        }   
        if(root->left != NULL && root->right != NULL){  // 2 child node
            // TreeNode* pre = iop(root);
            // root->value = pre->value;    // replace node by its inorder predecessor
            // root->left = deleteNode(root->left,pre->value); 
            TreeNode* suc = iosc(root);
            root->value = suc->value;    // replace node by its inorder successor
            root->right = deleteNode(root->right,suc->value); 
        } 
    }
    else if(root->value > key) root->left = deleteNode(root->left,key);
    else root->right = deleteNode(root->right,key);
    return root;
}

TreeNode* iop(TreeNode* root){          // Inorder predecessor
    TreeNode* pre = root->left;
    while(pre->right != NULL) pre = pre->right;
    return pre;
}

TreeNode* iosc(TreeNode* root){       // Inorder sucessor
    TreeNode* suc = root->right;
    while(suc->left != NULL) suc = suc->left;
    return suc;
}

