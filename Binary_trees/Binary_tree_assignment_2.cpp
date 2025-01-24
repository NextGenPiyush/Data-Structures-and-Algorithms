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

vector<vector<int>> level_order_traversal(TreeNode* root); // we have to strore from right to left into 2D vector

vector<vector<int>> zigzag_level_order(TreeNode* root);  // leetcode-103

int diameter_of_binary_tree(TreeNode* root);  // leetcode-543
int helper(TreeNode* root, int &ans);

int main(){

//***********************************************************************************************************//

    // calculate diameter of binary tree with time complexity of O(n)

//***********************************************************************************************************//

    // Level order traversal using queue from right to left

//***********************************************************************************************************//

    // level order traversal using queue in zigzag manner 

//***********************************************************************************************************//


    return 0;
}

vector<vector<int>> level_order_traversal(TreeNode* root){  // Leetcode-102
    if(root == NULL) return{};
    vector<vector<int>> ans;       // time complexity: O(n) where n is the number of nodes
    queue<TreeNode*> que;      // space complexity: O(2^h) where h is depth of the tree
    que.push(root);
    while(!que.empty()){
        int size = que.size();   // it is necessary to calculate size and using it in for loop, think why?
        vector<int> v(size);
        for(int i=0; i<size; i++){
            auto temp = que.front(); que.pop();  // we use auto when we dont know the data type here I write auto
            v[i] = temp->value;               // instead of using TreeNode*
            if(temp->left) que.push(temp->left);
            if(temp->right) que.push(temp->right);
        }
        reverse(v.begin(),v.end()); // don't use reverse function if you want traversal from left to right
        ans.push_back(v);                                      
    }
    return ans;
}

vector<vector<int>> zigzag_level_order(TreeNode* root){   // leetcode-103
    if(root == NULL) return {};  // return empty vector if the given root is NULL
    queue<TreeNode*> queNode;
    vector<vector<int>> ans;
    queNode.push(root);
    int j = 1;
    while(queNode.empty()!=0){
        int size = queNode.size();
        vector<int> v(size);
        for(int i=0; i<size; i++){
            TreeNode* temp = queNode.front();
            queNode.pop();
            int index = j%2==1 ? i : size-i-1;
            v[index] = temp->value;
            if(temp->left) queNode.push(temp->left);
            if(temp->right) queNode.push(temp->right);
        }
        ans.push_back(v);
        j++;
    }  
    return ans;

    // if(root == NULL) return {};  // return empty vector if the given root is NULL
    // queue<TreeNode*> queNode;
    // bool level = true;  // we can also use bool variable to decide whether to fill forward or backward
    // vector<vector<int>> ans;
    // queNode.push(root);
    // while(queNode.empty()!=0){
    //     int size = queNode.size();
    //     vector<int> v(size);
    //     for(int i=0; i<size; i++){
    //         TreeNode* temp = queNode.front();
    //         queNode.pop();
    //         int index = level ? i : size-i-1;  
    //         v[index] = temp->value;
    //         if(temp->left) queNode.push(temp->left);
    //         if(temp->right) queNode.push(temp->right);
    //     }
    //     ans.push_back(v);
    //     level = !level;  // make sure to change the level to change the direction of filling
    // }  
    // return ans;
}

int diameter_of_binary_tree(TreeNode* root){   // Time complexity O(n)
    int ans;            // space complexity O(n) call stack 
    helper(root,ans);
    // return ans-1;
    return ans;
}
int helper(TreeNode* root, int &ans){
    if(root == NULL) return 0;
    int leftAns = helper(root->left,ans);  // we have followed the bottom up approach
    int rightAns = helper(root->right,ans);
    // ans = max(ans, (leftAns+rightAns) + 1);  // we have 1 one but in the above function we have return ans-1
    ans = max(ans, (leftAns+rightAns));  // we can also do that but now we will have to return ans  
    return max(leftAns,rightAns)+1;  // in the end this function will return level
}