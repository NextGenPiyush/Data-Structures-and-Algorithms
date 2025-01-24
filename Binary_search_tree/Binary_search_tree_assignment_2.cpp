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

bool count_sub_trees(TreeNode* root, int low, int high, int &count);  // good question

int distance(TreeNode* root, int key1, int key2);  // good question
int root_to_node(TreeNode* root, int key);

int main(){

//********************************************************************************************************// 

    // Given a BST, count subtrees in it whose nodes lie within a given range.
    // try to implement with top-down approach and calculate the time and space complexity 

//********************************************************************************************************// 

    // Given a BST and two keys in it. Find the distance between two nodes with given two keys. It may
    // be assumed that both keys exist in BST.

//********************************************************************************************************// 



    return 0;
}

bool count_sub_trees(TreeNode* root, int low, int high, int &count){
    if(root == NULL) return true;
    bool leftcall = count_sub_trees(root->left,low,high,count);    // bottom up approach 
    bool rightcall = count_sub_trees(root->right,low,high,count);
    if(leftcall && rightcall && root->value >= low && root->value <= high){
        count++;
        return true;              // time complexity: O(n)
    }                             // space complexity: O(n)
    return false;
}

int distance(TreeNode* root, int key1, int key2){
    if(root == NULL) return 0;
    else if(root->value > key1 and root->value > key2) return distance(root->left,key1,key2);
    else if(root->value < key1 and root->value < key2) return distance(root->right,key1,key2);
    else return root_to_node(root,key1) + root_to_node(root,key2); //(root->value >= key1 and root->value <= key2)
}
int root_to_node(TreeNode* root, int key){
    if(root == NULL) return 0;
    else if(root->value == key) return 0;
    else if(root->value > key) return 1 + root_to_node(root->left,key);
    else return 1 + root_to_node(root->right,key);
}