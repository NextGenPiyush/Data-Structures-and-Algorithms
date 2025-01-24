#include<bits/stdc++.h>  // this header file include all the necessary library
// #include<set>  // for ordered set
// #include<map>  // for ordered map

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

class ListNode{       
    public:
        int value;
        ListNode* next;
        ListNode* random;  
        ListNode(int value){    
            this->value = value;
            next = NULL;
            // this->next = NULL;  // we can also do that 
            random = NULL;  // for leetcode question 138
        }
};

vector<int> findEvenNumber(vector<int> &arr);  // Leetcode-2094

int countNicePairs(vector<int> &nums);  // Leetcode-1814
int rev(int num);
int comb(int n, int r);
int fact(int n);

void top_view(TreeNode* root); 

ListNode* copyRandomList(ListNode* head);  // Leetcode-138

int main(){

//*********************************************************************************************************************//  

    // set<int> s;  // ordered set
    // s.insert(5);  s.insert(3);  s.insert(1);  s.insert(4);  s.insert(2);  s.insert(5); // duplicates not inserted
    // for(int ele: s) cout<<ele<<" ";  cout<<endl;   // printed in a sorted order not depending order of insertion 
    // // inersetion, deletion will not take O(1), it take O(logn) remember

    // map<int,int> m1;  // ordered map<a,b> here a is the key
    // map<string,int> m2;
    // m1[2] = 99;  m1[1] = 50;  m1[3] = 23;
    // m2["Raghav"] = 99;  m2["Harsh"] = 50;  m2["Sanket"] = 23;

    // for(pair<int,int> x: m1){
    //     cout<<x.first<<" "<<x.second<<endl;     // printed in sorted order according to the key 
    //     // cout<<x.second<<" "<<x.first<<endl;
    // }
    // for(auto x: m2){
    //     cout<<x.first<<" "<<x.second<<endl;     // lexographically character sorting order according to the key 
    //     // cout<<x.second<<" "<<x.first<<endl;
    // }

//*********************************************************************************************************************//  

    // // vector<int> v{2,1,3,0};  // Leetcode-2094
    // // vector<int> v{3,7,5};  // odd elements only
    // vector<int> v{2,2,8,8,2};  // repeated elements 
    // vector<int> ans = findEvenNumber(v);
    // for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";  cout<<endl;

//*********************************************************************************************************************//  

    // // vector<int> v{42,11,1,97};  // Leetcode-1814
    // vector<int> v{13,10,35,24,76};
    // cout<<"Number of required pairs: "<<countNicePairs(v)<<endl;

//*********************************************************************************************************************//  

    // TreeNode* a = new TreeNode(1);
    // TreeNode* b = new TreeNode(2);
    // TreeNode* c = new TreeNode(3);
    // TreeNode* d = new TreeNode(4);
    // TreeNode* e = new TreeNode(5);
    // TreeNode* f = new TreeNode(6);
    // TreeNode* g = new TreeNode(7);
    // a->left = b; a->right = c; b->left = d; b->right = e; c->left = f; c->right = g;
    // cout<<"Top view of binary tree: "<<endl;
    // top_view(a);

//*********************************************************************************************************************//  


    return 0;
}

vector<int> findEvenNumber(vector<int> &arr){  // Leetcode-2094
    vector<int> ans;
    int n = arr.size(); 

    // unordered_set<int> s;
    // for(int ele: arr) s.insert(ele);  // we can anly use set when there are unique elements in the vector 
    // for(int i=100; i<=999; i+=2){  // we want only even numbers
    //     int x = i;
    //     int a = x%10; x/=10;  // ones place 
    //     int b = x%10; x/=10;  // tens place 
    //     int c = x%10;  // hundreds place 
    //     if(s.find(a) != s.end()){   // a is present 
    //         s.erase(a);
    //         if(s.find(b) != s.end()){  // a and b both are present 
    //             s.erase(b);
    //             if(s.find(c) != s.end()) ans.push_back(i); // a, b and c all three are present 
    //             s.insert(b);
    //         }
    //         s.insert(a);
    //     }
    // }

    unordered_map<int,int> m;
    for(int ele: arr) m[ele]++;  // we can anly use map when there are repeated elements in the vector 
    for(int i=100; i<=999; i+=2){  // we want only even numbers
        int x = i;
        int a = x%10; x/=10;  // ones place 
        int b = x%10; x/=10;  // tens place 
        int c = x%10;  // hundreds place 
        if(m.find(a) != m.end()){   // a is present 
            m[a]--;
            if(m[a] == 0) m.erase(a);
            if(m.find(b) != m.end()){  // a and b both are present 
                m[b]--;
                if(m[b] == 0) m.erase(b);
                if(m.find(c) != m.end()) ans.push_back(i); // a, b and c all three are present 
                m[b]++;
            }
            m[a]++;
        }
    }

    return ans;
}

int countNicePairs(vector<int> &nums){  // Leetcode-1814
    int n = nums.size();
    int count = 0;

    // for(int i=0; i<n-1; i++) for(int j=i+1; j<n; j++) if(nums[i]+rev(nums[j]) == rev(nums[i])+nums[j]) count++;

    // unordered_map<int,int> m;
    // for(int i=0; i<n; i++) nums[i] -= rev(nums[i]);  // mathematics 
    // for(int i=0; i<n; i++) m[nums[i]]++;
    // for(auto x: m){
    //     int freq = x.second;
    //     count += comb(freq,2);  // combination function is taking lot of time and space complexity 
    // }                           // and we can also get run time error

    unordered_map<int,int> m;
    for(int i=0; i<n; i++) nums[i] -= rev(nums[i]);  // mathematics 
    for(int i=0; i<n; i++){
        if(m.find(nums[i]) != m.end()){
            count += m[nums[i]];      // here frequency indication the number of pairs 
            m[nums[i]]++;     // best approach (Optimized)
        }
        else m[nums[i]]++;
    }

    return count;
}
int rev(int num){
    int r=0;
    while(num>0){
        r *= 10;
        r += (num%10);
        num /= 10;
    }
    return r;
}
int comb(int n, int r){   // calculating nCr combination of n and r
    return fact(n)/(fact(r)*fact(n-r));
}
int fact(int n){
    int ans = 1;
    for(int i=2; i<=n; i++) ans*=i;
    return ans;
}

void top_view(TreeNode* root){
    unordered_map<int,int> m;     // map<level,root->value>
    queue<pair<TreeNode*,int>> q;
    pair<TreeNode*,int> p;        // pair<root,level>
    p.first = root;  p.second = 0;  q.push(p);  // inserting first pair of node and level into the queue
    while(q.size()>0){
        TreeNode* temp = (q.front()).first;
        int level = (q.front()).second;
        q.pop();
        if(m.find(level) == m.end()) m[level] = temp->value;  // if level was not presenmt in the map then only insert 
        if(temp->left != NULL){   // inserting left node by decrementing level
            pair<TreeNode*,int> p;
            p.first = temp->left;  p.second = level-1;  q.push(p);
        }
        if(temp->right != NULL){  // inserting right node by incrementing level 
            pair<TreeNode*,int> p;
            p.first = temp->right;  p.second = level+1;  q.push(p);
        }
    }
    int minLevel = INT_MAX;
    int maxLevel = INT_MIN;
    for(auto x: m){
        minLevel = min(minLevel,x.first);   // calculating minimum level
        maxLevel = max(maxLevel,x.first);   // calculating maximum level
    }
    for(int i=minLevel; i<=maxLevel; i++) cout<<m[i]<<" ";  cout<<endl;
}

ListNode* copyRandomList(ListNode* head){   // Leetcode-138
    // step-1 creat deep copy without random pointer 
    ListNode* dummy = new ListNode(0);
    ListNode* tempC = dummy;
    ListNode* temp = head;
    while(temp){                                      // Time complexity: O(n)
        ListNode* a = new ListNode(temp->value);      // space complexity: O(n)
        tempC->next = a;
        tempC = tempC->next;
        temp = temp->next;
    }
    ListNode* b = dummy->next;
    ListNode* a = head;

    // step-2 make a map of <original node, duplicate node>
    unordered_map<ListNode*,ListNode*> m;  // here we have tried to implement it with hashmaps 
    ListNode* tempa = a;    // there is another approach which will take space complexity: O(1)
    ListNode* tempb = b;
    while(tempa != NULL){
        m[tempa] = tempb;
        tempa = tempa->next;
        tempb = tempb->next;
    }

    // step-3 managing ramdom pointer in the linkedlist
    for(auto x: m){
        ListNode* original = x.first;
        ListNode* duplicate = x.second;
        if(original->random != NULL){
            ListNode* oRandom = original->random;
            ListNode* dRandom = m[original->random];
            duplicate->random = dRandom;
        }
    }
    return b;
}


