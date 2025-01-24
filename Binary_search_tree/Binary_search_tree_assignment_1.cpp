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

TreeNode* construct_tree(int arr[], int n){   // constructing binary tree using BFS (Queue)
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(arr[0]);  q.push(root);
    int i=1,j=2;
    while(q.size()>0 && i<n){
        TreeNode* temp = q.front(); q.pop();
        TreeNode* leftnode, *rightnode;
        if(arr[i] != INT_MIN) leftnode = new TreeNode(arr[i]);
        else leftnode = NULL; 
        if(j!=n && arr[j] != INT_MIN) rightnode = new TreeNode(arr[j]);
        else rightnode = NULL;

        temp->left = leftnode; 
        temp->right = rightnode; 

        if(leftnode != NULL) q.push(leftnode);
        if(rightnode != NULL) q.push(rightnode);

        i+=2; j+=2;
    }
    return root;
}

int minimum(TreeNode* root);
int maximum(TreeNode* root);

int kth_smallest_element(TreeNode* root, int k);  // (Leetcode-230)
void inorder(TreeNode* root, vector<int> &ans);
void helper(TreeNode* root, int &k, int &ans);

TreeNode* bst_to_balanced_bst(TreeNode* root);   // (Leetcode-1382)

int rangeSum(TreeNode* root, int low, int high); // (Leetcode-938)
void inorder_2(TreeNode* root, int low, int high, int &sum);

int main(){

//********************************************************************************************************//   

    // Find the node with minimum and maximum value node in the gievn binary search tree

//********************************************************************************************************//   

    // // kth smallest element of the binary search tree 
    // int arr[] = {40,30,50,25,35,45,60};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // TreeNode* root = construct_tree(arr,n);
    // cout<<"3rd smallest element of the binary search tree will be: "<<kth_smallest_element(root,3)<<endl;

//********************************************************************************************************//   

    // Given the root of a binary search tree, return a balanced BST with the same node values (Leetcode-1382)

//********************************************************************************************************//   

    // Given the root node of a binary search tree and two integers low and high, return the sum of
    // values of all nodes with a value in the inclusive range [low, high]. (Leetcode-938)

//********************************************************************************************************//   



    return 0;
}

int minimum(TreeNode* root){   // Minimum value in binary search tree will the the leftmost value
    if(root == NULL) return -1;   // time complexity: O(n) in worst case
    else if(root->left == NULL && root->right == NULL) return root->value;  // try to return node istead of value
    minimum(root->left);    // space complexity: O(n) in worst case
} 
int maximum(TreeNode* root){   // Maximum value in binary search tree will the the righttmost value
    if(root == NULL) return -1;  // time complexity: O(n) in worst case
    else if(root->left == NULL && root->right == NULL) return root->value;  // try to return node istead of value
    maximum(root->right);   // space complexity: O(n) in worst case
}


int kth_smallest_element(TreeNode* root, int k){  // Leetcode-230
    // vector<int> ans;
    // inorder(root,ans);  // time complexity: O(n)
    // return ans[k-1];    // space complexity: O(n) here we use vector to store inorder traversal 

    int ans = -1;
    helper(root,k,ans);
    return ans;
}
void inorder(TreeNode* root, vector<int> &ans){
    if(root == NULL) return;
    inorder(root->left,ans);
    ans.push_back(root->value);
    inorder(root->right,ans);
}
void helper(TreeNode* root, int &k, int &ans){
    if(root == NULL) return;
    helper(root->left,k,ans);
    if(--k == 0){
    // if(k-- == 0){  // this will give wrong ans try to understand why? and how we can correct it?
        ans = root->value;
        return;
    }
    helper(root->right,k,ans);
}

TreeNode* bst_to_balanced_bst(TreeNode* root){  // Leetcode-1382
    vector<int> ans;
    inorder(root,ans);      // it will store ans vector   // Time complexity: O(n)
    return helper_2(root,0,ans.size()-1,ans);         // space complexity: O(n)
}
TreeNode* helper_2(TreeNode* root, int low, int high, vector<int> &ans){
    if(low>high) return NULL;  // try to think about this base case
    int mid = (low+high)/2;
    root = new TreeNode(ans[mid]);
    if(low == high) return root;  // try to think why we have written this 
    root->left = helper_2(root,low,mid-1,ans);
    root->right = helper_2(root,mid+1,high,ans);
    return root;
}

int rangeSum(TreeNode* root, int low, int high){  // Leetcode-938
    int sum = 0;
    inorder_2(root,low,high,sum);
    return sum;                                            // time complexity: O(n)
}                                                          // space complexity: O(n)
void inorder_2(TreeNode* root, int low, int high, int &sum){
    if(root == NULL) return;
    inorder_2(root->left,low,high,sum); // we can use any traversal but check conditions while taking sum
    if(root->value>=low && root->value<=high) sum += root->value;
    inorder_2(root->right,low,high,sum);
}