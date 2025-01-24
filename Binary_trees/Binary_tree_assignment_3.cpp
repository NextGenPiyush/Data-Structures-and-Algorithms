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

void left_side_view(TreeNode* root, int &maxlevel, int currlevel, vector<int> &ans);

bool path_sum(TreeNode* root, int target);  // Leetcode-112 

TreeNode* Build_tree_1(vector<int> &postorder, vector<int> &inorder);  // Leetcode-106
TreeNode* Build_1(vector<int> &postorder, vector<int> &inorder, int startidx, int endidx, int &index);

TreeNode* Build_tree_2(vector<int> &postorder, vector<int> &preorder);  // Leetcode-889
TreeNode* Build_2(vector<int> &postorder, vector<int> &preorder, int startidx, int endidx, int index);

int main(){

//************************************************************************************************************//

    // TreeNode* a = new TreeNode(1);
    // TreeNode* b = new TreeNode(2);
    // TreeNode* c = new TreeNode(3);
    // TreeNode* d = new TreeNode(4);
    // TreeNode* e = new TreeNode(5);
    // TreeNode* f = new TreeNode(6);
    // TreeNode* g = new TreeNode(7);
    // a->left = b; a->right = c; b->left = d; b->right = e; c->left = f; c->right = g;
    // TreeNode* root = a;
    // int maxlevel = -1; 
    // int currlevel = 0;
    // vector<int> ans;
    // left_side_view(root, maxlevel, currlevel, ans);
    // for(auto val: ans)cout<<val<<" ";

//************************************************************************************************************//

    // path sum problem (Leetcode-112) 
    // If sum of any path which start from root equal to the given target then return true  

//************************************************************************************************************//

    // contruct a Binary tree from postorder and inorder traversal (Leetcode-106)

//************************************************************************************************************//

    // contruct a Binary tree from postorder and preorder traversal (Leetcode-889)

//************************************************************************************************************//


    return 0;
}

void left_side_view(TreeNode* root, int &maxlevel, int currlevel, vector<int> &ans){  // we will pass maxlevel by refference 
    if(root == NULL) return;    // try to dry run the code without passing the refference of the maxlevel
    if(maxlevel < currlevel){
        maxlevel = currlevel;
        ans.push_back(root->value);
    }
    left_side_view(root->left,maxlevel,currlevel+1,ans);  // for left side view
    left_side_view(root->right,maxlevel,currlevel+1,ans);

    // left_side_view(root->right,maxlevel,currlevel+1,ans);   // for right side view
    // left_side_view(root->left,maxlevel,currlevel+1,ans);  
} 

bool path_sum(TreeNode* root, int target){
    if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL) return(target == root->value);
    return (path_sum(root->left,target-root->value) || path_sum(root->right,target-root->value));
} 

TreeNode* Build_tree_1(vector<int> &postorder, vector<int> &inorder){   
    int index = inorder.size()-1; 
    int startidx = 0; 
    int endidx = index;
    return Build_1(postorder, inorder, startidx, endidx, index);
}
TreeNode* Build_1(vector<int> &postorder, vector<int> &inorder, int startidx, int endidx, int &index){
    if((startidx > endidx) || (index < 0)) return NULL;
    TreeNode* root = new TreeNode(postorder[index]);  // here we have used only one index variable instead of
    index--;                                          // taking low and high pointer
    if(startidx == endidx) return root;
    int newIndex = 0;
    for(int i=startidx; i<=endidx; i++){
        if(inorder[i] == root->value){
            newIndex = i; 
            break;
        }
    }
    root->left = Build_1(postorder, inorder, startidx, newIndex-1, index);
    root->right = Build_1(postorder, inorder, newIndex+1, endidx, index);
    return root;
}

TreeNode* Build_tree_2(vector<int> &postorder, vector<int> &preorder){
    int index = 0;
    int startidx = 0; 
    int endindex = preorder.size()-1;
    return Build_1(postorder, preorder, startidx, endindex, index);
}
TreeNode* Build_2(vector<int> &postorder, vector<int> &preorder, int startidx, int endidx, int index){
    if((startidx > endidx) || (index > preorder.size()-1)) return NULL;
    TreeNode* root = new TreeNode(preorder[index]);
    index++;
    if(startidx == endidx) return root;
    int newIndex = 0;
    for(int i=startidx; i<=endidx-1; i++){
        if(postorder[i] == preorder[index]){
            newIndex = i; break;
        }
    }
    root->left = Build_2(postorder, preorder, startidx, newIndex, index);
    root->right = Build_2(postorder, preorder, newIndex+1, endidx-1, index);
    return root;
}