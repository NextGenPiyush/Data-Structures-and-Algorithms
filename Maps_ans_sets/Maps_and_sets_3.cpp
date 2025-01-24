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

int subArraySum(vector<int> &nums, int k);  // Leetcode-560
bool binary_search(vector<int> nums, int x, int idx);

int amountOfTime(TreeNode* root, int start);  // Leetcode-2385
void find(TreeNode* root, int start, TreeNode* first);
void markParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent);

vector<vector<string>> groupAnagrams(vector<string> &str);  // Leetcode-49

bool close_string(string str1, string str2);  // Leetcode-1657

bool canArrange(vector<int> &arr, int k);  //

int main(){

//*********************************************************************************************************************//

    // vector<int> v = {2,3,4,5,8,1,2,7};  int k = 9;  // Leetcode-560
    // vector<int> v = {-1,-1,1};  int k = 0;
    vector<int> v = {0,0,0,0};  int k = 0;
    cout<<"number of subarray: "<<subArraySum(v,k)<<endl;

//*********************************************************************************************************************//

    // amount of time required to infect a binary tree from a ramdomly given node (Leetcode-2385)

//*********************************************************************************************************************//

    // make group of anagrams and return it into a 2D vector (Leetcode-49)

//*********************************************************************************************************************//

    // determine if two strings are close or not (Leetcode-1657)

//*********************************************************************************************************************//



//*********************************************************************************************************************//


    return 0;
}

int subArraySum(vector<int> &nums, int k){  // Leetcode-560
    int n = nums.size();
    int count = 0;
    for(int i=1; i<n; i++) nums[i] += nums[i-1];  // making prefix sum array  O(n)

//******************************************Method-1******************************************//
    // for(int i=0; i<n; i++){     // Time complexity: O(nlogn)
    //     if(nums[i] == k) count++;
    //     if(nums[i] > k) if(binary_search(nums,(nums[i]-k),i)) count++; // search for element from 0 to (i-1)th index
    // }

//******************************************Method-2******************************************//
    // unordered_set<int> s; // unordered set
    // for(int i=0; i<n; i++){   // Time complexity: O(n)
    //     if(nums[i] == k) count++;
    //     // if((nums[i] > k) && (s.find(nums[i]-k) != s.end())) count++; // alos do it for (nums[i]<k) condition
    //     else{
    //         int rem = nums[i]-k;
    //         if(s.find(rem) != s.end()) count++;
    //     }                     // not a correct method 
    //     s.insert(nums[i]);     // only insert the unique elements 
    // }

//******************************************Method-2******************************************//
    unordered_map<int,int> m;  // unordered map<ele,freq>
    for(int i=0; i<n; i++){    // Time complexity: O(n)
        if(nums[i] == k) count++;
        int rem = nums[i]-k;     // Coorect approach 
        if(m.find(rem) != m.end()) count += m[rem];
        m[nums[i]]++;  // inserting into map
    }

    return count;
}
bool binary_search(vector<int> nums, int x, int idx){
    int n = nums.size();
    int low=0, high=idx-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid] == x) return true;
        else if(nums[mid] > x) high = mid-1; 
        else low = mid+1; 
    }
    return false;
}

int amountOfTime(TreeNode* root, int start){  // Leetcode-2385
    TreeNode* first;
    find(root,start,first);  // finding the root and make it first root 
    unordered_map<TreeNode*,TreeNode*> parent;
    markParent(root,parent);  // filling the map with appropriate parent entries 
    unordered_set<TreeNode*> isInfected;
    isInfected.insert(first);
    queue<pair<TreeNode*,int>> q;
    q.push({first,0});
    int maxLevel = 0;

    while(q.size()>0){
        pair<TreeNode*,int> p = q.front();
        q.pop();
        int level = p.second;
        maxLevel = max(maxLevel,level);
        TreeNode* temp = p.first;
        if((temp->left != NULL) && (isInfected.find(temp->left) == isInfected.end())){
            q.push({temp->left,level+1});
            isInfected.insert(temp->left);
        }
        if((temp->right != NULL) && (isInfected.find(temp->right) == isInfected.end())){
            q.push({temp->right,level+1});
            isInfected.insert(temp->right);
        }
        if(parent.find(temp) != parent.end() && isInfected.find(temp) == isInfected.end()){
            q.push({parent[temp],level+1});
            isInfected.insert(parent[temp]);
        }
    }
    return maxLevel;
}
void find(TreeNode* root, int start, TreeNode* first){
    if(root == NULL) return;
    if(root->value == start) first = root;
    find(root->left,start,first); 
    find(root->right,start,first); 
}
void markParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent){
    if(root == NULL) return;
    if(root->left != NULL) parent[root->left] = root;
    if(root->right != NULL) parent[root->right] = root;
}

vector<vector<string>> groupAnagrams(vector<string> &arr){  // Leetcode-49
    vector<vector<string>> ans;
    unordered_map<string,vector<string>> map;
    for(string str : arr){  // O(n) in traversing the arr
        string lexo = str;
        sort(lexo.begin(),lexo.end());  // O(klogk) where k is the average length of each string 
        if(map.find(lexo) != map.end()){
            vector<string> v;  
            v.push_back(str);
            map[lexo] = v;
        }                                    // Time complexity: O(nklogk)
        else map[lexo].push_back(str);       // space complexity: O(kn) where k is the number of group formed
    }
    for(auto x: map) ans.push_back(x.second);   
    return ans;
}

bool close_string(string str1, string str2){   // Leetcode-1657
    if(str1.length() != str2.length()) return false;

    unordered_map<char,int> mp1,mp2;  // map<char, freq>
    // for(char ch: str1) mp1[ch]++;
    // for(char ch: str2) mp2[ch]++;   // we can also mark map with different loops 
    for(int i=0; i<str1.length(); i++){
        mp1[str1[i]]++;                        // Time complexity: O(n)
        mp2[str2[i]]++;                        // space complexity: O(n)
    } 
    for(auto x: mp1){
        char ch = x.first;
        if(mp2.find(ch) == mp2.end()) return false;
    }

    unordered_map<int,int> h1,h2;    // map<freq, freq of freq>
    for(auto x: mp1) h1[x.second]++;  
    for(auto x: mp2) h2[x.second]++;
    for(auto x: h1){
        int key = x.first;
        if(h2.find(key) == h2.end()) return false;
        if(h2[key] != h1[key]) return false;
    }
    return true;
}

bool canArrange(vector<int> &arr, int k){
    unordered_map<int,int> map;
    for(int ele: arr){
        // ele %= k;
        ele = ((ele%k)+k)%k;
        map[ele]++;                      // Time complexity: O(n)
    }                                   
    if(map.find(0) != map.end()){
        if(map[0]%2 != 0) return false;
        map.erase(0);
    }
    for(auto x: map){
        int ele = x.first;
        int rem = k-ele;
        if(map.find(rem) == map.end()) return false;
        if(map[ele] != map[rem]) return false;
    }
    return true;
}





