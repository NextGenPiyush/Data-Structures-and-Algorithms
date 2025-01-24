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

TreeNode* searchBST(TreeNode* root, int value);  // Leetcode-700 search in binary search tree

TreeNode* insert_into_BST(TreeNode* root, int value);  // Leetcode-701 insert into binary search tree

TreeNode* LCA_of_BST(TreeNode* root, TreeNode* p, TreeNode* q);  // Leetcode-235 Lowest common ancestor of a binary search tree

bool is_valid_BST(TreeNode* root);   // Leetcode-98 is tree a valid binary search tree
int maxTree(TreeNode* root);
int minTree(TreeNode* root);
void inorder_1(TreeNode* root, vector<int> &ans);
void inorder_2(TreeNode* root, bool &flag, TreeNode* &prev);

TreeNode* greater_sum_tree(TreeNode* root);  // Leetcode-1038 Greater sum Tree of given binary search tree
void reverseInorder(TreeNode* root, int &sum);

TreeNode* build_BST(vector<int> &nums);  // Leetcode-108 building binary search tree from a sorted array
TreeNode* helper(vector<int> &nums, int low, int high);

TreeNode* BST_from_preorder(vector<int> &pre);  // Leetcode-1008 buliding binary search tree from given preorder vector 

int main(){

//********************************************************************************************************//

    // search a value in BST and return the node if present or return NULL (Leetcode-700)

//********************************************************************************************************//

    // insert a node in binary search tree (Leetcode-701)
    // as there are many ways to insert a node in the binary tree, but we will attach at the leaf node

//********************************************************************************************************//

    // find the lowest common ansectors of the two given nodes in binary search tree (Leetcode-235)
    // we have also done this question for binart tree now we have to do it for binary search tree

//********************************************************************************************************//

    // implement a function which check that given tree is binary search tree or not (Leetcode-98)

//********************************************************************************************************//

    // Given a BST, transform it into a greater sum tree where each node contains the sum of all nodes 
    // greater than that node plus original node  (Leetcode-1038)

//********************************************************************************************************//

    // Convert sorted array to balanced binary search tree (Leetcode-108)

//********************************************************************************************************//

    // Given the preorder traversal of a binary search tree, construct the BST (Leetcode-1008)
    // similarly try to implement with postorder and inorder traversal 

//********************************************************************************************************//



    return 0;
}

TreeNode* searchBST(TreeNode* root, int value){     // Leetcode-700 
    if(root == NULL || root->value == value) return root;               // space complexity is same as time complexity 
    // else if(root->value == value) return root;  // this line is already included above 
    else if(root->value > value) return searchBST(root->left,value);    // Time complexity O(n) in worst case
    else return searchBST(root->right,value);                           // O(logn) in best/average case
}

TreeNode* insert_into_BST(TreeNode* root, int value){    // Leetcode-701 
    if(root == NULL) return new TreeNode(value);


    // else if(root->value > value){  // go left
    //     if(root->left == NULL){  // attach it here 
    //         root->left = new TreeNode(value);
    //         return root;
    //     }
    //     else insert_into_BST(root->left,value);  // dont write return here, we dont want to return 
    // }
    // else{   // go right
    //     if(root->right == NULL){   // attach it here 
    //         root->right = new TreeNode(value);
    //         return root;
    //     }
    //     else insert_into_BST(root->right,value);  // if you are facing problem that why we have not written return
    // }                                             // then use helper function of return type void 

    insert_helper(root,value);  // tries to implement it with helper function

    return root;                                  
}
void insert_helper(TreeNode* root, int value){
    if(value < root->value){
        if (root->left == NULL) root->left = new TreeNode(value);
        else insert_helper(root->left, value);
    }
    else{
        if (root->right == NULL) root->right = new TreeNode(value);
        else insert_helper(root->right, value);
    }
}

TreeNode* insertion(TreeNode* root, int value){       // we can also do this 
    if(root == NULL) return new TreeNode(value);  // there are many ways of inserting in thr binary search tree
    else if(root->value < value){
        if(root->right == NULL){
            root->right = new TreeNode(value);
            return root;
        }
        else{
            TreeNode* temp = root->right;
            TreeNode* target = new TreeNode(value);
            root->right = target;
            if(temp->value < target->value) target->left = temp;
            else target->right = temp; 
            return root;
        }
    }
    else{
        if(root->left == NULL){
            root->left = new TreeNode(value);
            return root;
        }
        else{
            TreeNode* temp = root->left;
            TreeNode* target = new TreeNode(value);
            root->left = target;
            if(temp->value < target->value) target->left = temp;
            else target->right = temp; 
            return root;
        }
    }
}

TreeNode* LCA_of_BST(TreeNode* root, TreeNode* p, TreeNode* q){     // Leetcode-235
    // if(root->value == p->value || root->value == q->value) return root;
    // else if(root->value > p->value && root->value < q->value) return root;
    // else if(root->value < p->value && root->value > q->value) return root;
    // else if(root->value < p->value && root->value < q->value) return LCA_of_BST(root->right,p,q);
    // else return LCA_of_BST(root->left,p,q);

    if(root->value < p->value && root->value < q->value) return LCA_of_BST(root->right,p,q);
    else if(root->value > p->value && root->value > q->value) return LCA_of_BST(root->left,p,q);
    else return root;
}

bool is_valid_BST(TreeNode* root){    // Leetcode-98   not a good method 

    // *******************************  Method_1 ******************************* //
    if(root == NULL) return true; 
    if(root->left == NULL && root->right == NULL) return true; 
    else if(root->value <= maxTree(root->left)) return false;
    else if(root->value >= minTree(root->left)) return false;
    return is_valid_BST(root->left) && is_valid_BST(root->right);  // Time complexity: O(n^2)

    // *******************************  Method_2 ******************************* //
    // vector<int> ans;    // right approach
    // inorder_1(root,ans);  // if inorder traversal is sorted then it is a valid binary search tree
    // for(int i=0; i<ans.size()-2; i++) if(ans[i] >= ans[i+1]) return false;
    // return true;         // here space complexity is: O(n) but there is another method in which it will be O(1)

    // *******************************  Method_3 ******************************* //
    TreeNode* prev = NULL;
    bool flag = true;
    inorder_2(root,flag,prev);  // here space complexity will be: O(1)
    return flag;
}   
int maxTree(TreeNode* root){                         
    if(root == NULL) return INT_MIN; // we can use long long data_type(LLONG_MIN) 
    return max(root->value, max(maxTree(root->left), maxTree(root->right)));
}
int minTree(TreeNode* root){
    if(root == NULL) return INT_MAX; // we can use long long data_type(LLONG_MAX) 
    return min(root->value, min(minTree(root->left), minTree(root->right)));
}
void inorder_1(TreeNode* root, vector<int> &ans){
    if(root == NULL) return;
    inorder_1(root->left, ans);      // No need to maintain a vector, we can jest check by previous value to reduce space
    ans.push_back(root->value);  
    inorder_1(root->right, ans);
}
void inorder_2(TreeNode* root, bool &flag, TreeNode* &prev){
    if(root == NULL) return;
    inorder_2(root->left,flag,prev);  
    if(prev != NULL){         // space complexity: O(1)
        if(root->value <= prev->value){
            flag = false;
            return;
        }
    }
    prev = root;
    inorder_2(root->right,flag,prev);
}

TreeNode* greater_sum_tree(TreeNode* root){  // Leetcode-1038 
    int sum = 0;
    reverseInorder(root,sum);  // Use reverse inorder traversal to solve this question 
    return root;
}
void reverseInorder(TreeNode* root, int &sum){
    if(root == NULL) return;
    reverseInorder(root->right,sum);
    root->value += sum;
    sum = root->value;
    reverseInorder(root,sum);
}

TreeNode* build_BST(vector<int> &nums){  // Leetcode-108
    int n = nums.size();
    return helper(nums,0,n-1);  // Paasing whole vector from start to end 
}   
TreeNode* helper(vector<int> &nums, int low, int high){
    if(low>high) return NULL;
    int mid = low+(high-low)/2;       // same we have done in binary search to calculate mid or vector 
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = helper(nums,low,mid-1);   // base case: (low>high) then attach null pointer to the node
    root->right = helper(nums,mid+1,high);
    return root;
}

TreeNode* BST_from_preorder(vector<int> &pre){  // Leetcode-1008  we can make inorder by sorting array
// and we have solved a problem in which from pre and in order we build a binary tree (not a good approach in this case) 

    // alternate method (much better solution)
    TreeNode* root = new TreeNode(pre[0]);  // first element must be the root of the tree
    for(int i=1; i<pre.size(); i++){
        insert_into_BST(root,pre[i]);  // we will insert one by one root into the binary search tree 
    }
    return root;
}




