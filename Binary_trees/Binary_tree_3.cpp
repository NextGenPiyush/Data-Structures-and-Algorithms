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

vector<int> preorder_traversal(TreeNode* root);   // Leetcode-144
vector<int> postorder_traversal(TreeNode* root);  // Leetcode-145
vector<int> inorder_traversal(TreeNode* root);    // Leetcode-94

TreeNode* construct_tree(int arr[], int n);

void boundary(TreeNode* root);
void left_boundary(TreeNode* root);
void bottom_boundary(TreeNode* root);
void right_boundary(TreeNode* root);

vector<int> rightSideView(TreeNode* root);    // Leetcode-199 
void helper_1(TreeNode* root, vector<int> &ans, int level);
int levels(TreeNode* root);
void print_nth_level(TreeNode* root, int curr, int lev, vector<int> &ans);
void level_order_traversal(TreeNode* root, vector<int> &ans);

vector<vector<int>> pathSum_2(TreeNode* root, int targetSum);  // Leetcode-113
void helper_2(TreeNode* root, vector<int> v, vector<vector<int>> &ans, int targetSum);

int pathSum_3(TreeNode* root, int targetSum);   // Leetcode-437 good question   
void helper_3(TreeNode* root, int targetSum, int count);

TreeNode* build_tree(vector<int> &preorder, vector<int> &inorder);  // Leetcode-105 
TreeNode* build(vector<int> &preorder, int prelo, int prehi, vector<int> &inorder, int inlo, int inhi);

int main(){

//********************************************************************************************************//

    // int arr[] = {1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,
    //              INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,
    //               20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,INT_MIN,28,INT_MIN,INT_MIN};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // TreeNode* root = construct_tree(arr,n);
    // boundary(root);

//********************************************************************************************************//

    // try to bild tree with inorder and postorder vector Leetcode-106 (Homework-1)

//********************************************************************************************************//

    // try to bild tree with preorder and postorder vector Leetcode-889 (Homework-2)

//********************************************************************************************************//

    return 0;
}

vector<int> preorder_traversal(TreeNode* root){  // preorder with iterative method 
    stack<TreeNode*> st;
    vector<int> ans;
    if(root != NULL) st.push(root);  // push if tree in not empty 
    while(st.size()>0){              // if root is null then this will never be executed
        TreeNode* temp = st.top();
        st.pop();
        ans.push_back(temp->value);
        
        if(temp->right != NULL) st.push(temp->right);  // if I push temp->left first then it will not give postorder
        if(temp->left != NULL) st.push(temp->left);
    }
    return ans;      // if root == NULL directly return empty vector 
    // or we can return empty vector by writting return {};
}

vector<int> postorder_traversal(TreeNode* root){  // postorder with iterative method 
    stack<TreeNode*> st;
    vector<int> ans;
    if(root != NULL) st.push(root);  // push if tree in not empty 
    while(st.size()>0){              // if root is null then this will never be executed
        TreeNode* temp = st.top();
        st.pop();
        ans.push_back(temp->value);
        
        if(temp->left != NULL) st.push(temp->left);
        if(temp->right != NULL) st.push(temp->right);
    }
    reverse(ans.begin(),ans.end());  // by reversing it will change to the postorder traversal vector
    return ans;      // if root == NULL directly return empty vector 
}

vector<int> inorder_traversal(TreeNode* root){  // inorder with iterative method
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* node = root;
    while(st.size()>0 || node!=NULL){   // if stack is empty then check, if node is not NULL keep running the loop 
        if(node){
            st.push(node);
            node = node->left;
        }
        else{   // temp is NULL
            TreeNode* temp = st.top(); st.pop();
            ans.push_back(temp->value);
            node = temp->right;
        }   
    }
    return ans;
}

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

void boundary(TreeNode* root){   
    left_boundary(root);        // this is not a homework but can i get this using iterative method 
    bottom_boundary(root);
    right_boundary(root->right);
    cout<<endl;
}
void left_boundary(TreeNode* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;  // as leaf node will be covered in bottom boundary
    cout<<root->value<<" ";
    left_boundary(root->left);
    if(root->left == NULL) left_boundary(root->right);
}
void bottom_boundary(TreeNode* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) cout<<root->value<<" ";
    bottom_boundary(root->left);
    bottom_boundary(root->right);
}
void right_boundary(TreeNode* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;  // as leaf node will be covered in bottom boundary
    right_boundary(root->right);
    if(root->right == NULL) right_boundary(root->left);
    cout<<root->value<<" ";  // here i have used bottom up approach by calling recursion before printing
}

vector<int> rightSideView(TreeNode* root){    // try to implement left side view of the binary tree 
    vector<int> ans(levels(root),0);
    // level_order_traversal(root,ans);    // alternate method
    helper_1(root,ans,0);  // more easy to understand 
    return ans;
} 
void helper_1(TreeNode* root, vector<int> &ans, int level){
    if(root == NULL) return;
    ans[level] = root->value;
    helper_1(root->left,ans,level+1);
    helper_1(root->right,ans,level+1);
}
int levels(TreeNode* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left),levels(root->right));
}
void level_order_traversal(TreeNode* root, vector<int> &ans){
    for(int i=0; i<ans.size(); i++) print_nth_level(root,0,i,ans);
}
void print_nth_level(TreeNode* root, int curr, int lev, vector<int> &ans){   // try to use another print_nth_level function
    if(root == NULL) return;   // which do not include any int curr variable
    if(curr == lev){       
        ans[curr] = root->value;   // this value will be overight multiple times 
        return;
    }
    print_nth_level(root->right,curr+1,lev,ans);   // for right to left
    print_nth_level(root->left,curr+1,lev,ans);
    // print_nth_level(root->left,curr+1,lev,ans);   // for left to right
    // print_nth_level(root->right,curr+1,lev,ans);
}

vector<vector<int>> pathSum_2(TreeNode* root, int targetSum){  // Leetcode-113
    vector<vector<int>> ans;
    vector<int> v;
    helper_2(root,v,ans,targetSum); // space complx of this approach is not good as new vector created everytime
    return ans;  // we will make it optimize using backtracking (but now we haven't practice backtracking)
}
void helper_2(TreeNode* root, vector<int> v, vector<vector<int>> &ans, int targetSum){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        if(root->value == targetSum){
            v.push_back(root->value);
            ans.push_back(v);
        }
        return;
    }
    v.push_back(root->value);
    helper_2(root->left,v,ans,targetSum-(root->value));
    helper_2(root->right,v,ans,targetSum-(root->value));
}

int pathSum_3(TreeNode* root, int targetSum){  // Leetcode-437 good question 
    if(root == NULL) return 0;
    int count = 0;
    helper_3(root,targetSum,count);  // try to implement without passing count as an argument (discussed in lecture)
    count += (pathSum_3(root->left,targetSum) + pathSum_3(root->right,targetSum));  // run for all the elements of the tree
    return count;
}     
void helper_3(TreeNode* root, int targetSum, int count){  // try to implement this function with return type integer 
    if(root == NULL) return;
    if(root->value == targetSum) count++;  // try to think we should not return here                
    helper_3(root->left,targetSum-(root->value),count);  // handle the integer signed overflow 
    helper_3(root->right,targetSum-(root->value),count);
}

TreeNode* build_tree(vector<int> &preorder, vector<int> &inorder){  // Leetcode-105
    int n = preorder.size();
    return build(preorder,0,n-1,inorder,0,n-1);  // here 0 and n-1 are the indeces of the vector
}
TreeNode* build(vector<int> &preorder, int prelo, int prehi, vector<int> &inorder, int inlo, int inhi){
    if(prelo>prehi) return NULL;     // we can also write (inlo>inhi) in the condition
    TreeNode* root = new TreeNode(preorder[prelo]);
    if(prelo == prehi) return root;      // we can also write (inlo==inhi) in the condition
    int i=inlo;
    while(i<=inhi){
        if(inorder[i] == preorder[prelo]) break;
        i++; 
    }
    int left_count = i-inlo;
    int right_count = inhi-i;
    root->left = build(preorder, prelo+1, prelo+left_count, inorder, inlo, i-1);
    root->left = build(preorder, prelo+left_count+1, prehi, inorder, i+1, inhi);
    return root;
}




