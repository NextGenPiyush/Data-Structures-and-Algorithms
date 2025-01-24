#include<bits/stdc++.h>  
// #include<queue> must include for heap 
using namespace std;

int kthSmallest(vector<int> v, int k);
int kthLargest(vector<int> v, int k);  // Leetcode-215

void K_sorted(vector<int> &v, int k);

vector<int> topKfrequent(vector<int> &arr, int k);  // Leetcode-347
typedef pair<int,int> p;

vector<int> findClosestElements(vector<int> &arr, int k, int x);  // Leetcode-658

vector<vector<int>> KClosest(vector<vector<int>> &arr, int k); // Leetcode-973
typedef pair<int,vector<int>> piv;
// typedef pair<int,pair<int,int>> pvi; // we can also do that 

int lastStoneWeight(vector<int> &arr);  // Leetcode-1046

int ropeCost(vector<int> &v); 

int main(){

//*********************************************************************************************************************//   

    // cout<<"Implementing maxHeap: "<<endl;
    // priority_queue<int> pq1;  // maxHeap (by-default) 
    // pq1.push(10);  pq1.push(81);  pq1.push(7);  pq1.push(-60);  pq1.push(20); // Time complexity:O(logn),n --> pq.size()
    // cout<<"Top element: "<<pq1.top()<<endl;  // print largest element
    // pq1.pop();  // remove the largest element      Time complexity: O(logn), n --> pq.size()
    // cout<<"After poping element, top element: "<<pq1.top()<<endl;   // Time complexity: O(1)
    // pq1.push(-20);   // -20 is not the largest element, so the pq.top() remain same
    // cout<<"After inserting new element, top element: "<<pq1.top()<<endl;
    // cout<<"Size of priority queue: "<<pq1.size()<<endl;
    // // Data structure in which we can always get max or min element at any point of time we use priority queue
    // // revisit min stack problem discussed in stack and queue data structure 

    // // maxHeap --> maximum element is on the top (by-default in c++)
    // // minHeap --> minimum element is on the top

    // cout<<endl<<"Implementing minHeap: "<<endl;
    // priority_queue<int,vector<int>,greater<int>> pq2;  // minHeap 
    // pq2.push(10);  pq2.push(81);  pq2.push(7);  pq2.push(-60);  pq2.push(20); // Time complexity:O(logn),n --> pq.size()
    // cout<<"Top element: "<<pq2.top()<<endl;  // print smallest element
    // pq2.pop();  // remove the smallest element      Time complexity: O(logn), n --> pq.size()
    // cout<<"After poping element, top element: "<<pq2.top()<<endl;   // Time complexity: O(1)
    // pq2.push(-20);   // now -20 is minimum, so pq.top() will change 
    // cout<<"After inserting new element, top element: "<<pq2.top()<<endl;
    // cout<<"Size of priority queue: "<<pq2.size()<<endl;

//*********************************************************************************************************************//   

    // // Find the kth smallest/largest element in a given array 

    // // Method-1 first sort then return (k-1)th index  
    // // Time complexity: O(nlogn) when er use inbuilt sort and space complexity: O(logn)

    // // Method-2 run selection sort code k times then return (k-1)th index
    // // Time complexity: O(kn) and space complexity: O(1)  --> this can be faster in some case as compared to
    // // method-1 when (k<logn) but not in all case

    // // Method-3 bubble sort from backward
    // // Time complexity: O(kn) and space complexity: O(1)  --> can be faster from method-1 in some cases

    // // Method-4 Quick select algorithem which was discussed in sorting 
    // // Time complexity: O(n) not used in worst case 

    // // Method-5 using heap 
    // // Time complexity: O(nlogk)

    // vector<int> v = {2,4,7,9,12,-40,-20,-56,45,76,105};
    // for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";  cout<<endl;
    // int k;
    // cout<<"value of k for kth smallest element: ";  cin>>k;
    // cout<<"your answer is: "<<kthSmallest(v,k)<<endl;
    // cout<<endl;
    // cout<<"value of k for kth largest element: ";  cin>>k;
    // cout<<"your answer is: "<<kthLargest(v,k)<<endl;

//*********************************************************************************************************************//   

    // // sort a 'k' sorted array (sort a nearly sorted array)

    // vector<int> v = {10,9,8,7,4,70,60,50};    int k = 4;
    // // vector<int> v = {6,5,3,2,8,10,9};   int k = 3;
    // cout<<"Before sorting: ";
    // for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";  cout<<endl;
    // K_sorted(v,k);
    // cout<<"After sorting: ";
    // for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";  cout<<endl;

//*********************************************************************************************************************//   

    // Homework: Leetcode378 (Hint --> Time complesity: O((k^2)logk)) try to think ----->>>

//*********************************************************************************************************************//   

    // vector<int> arr = {1,3,2,1,1,2};  int k = 2;  // (Leetcode-347)
    // for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";  cout<<endl;
    // cout<<"Top "<<k<<" frequent element in the array will be: ";
    // for(int i=0; i<topKfrequent(arr,k).size(); i++) cout<<topKfrequent(arr,k)[i]<<" "; cout<<endl;

//*********************************************************************************************************************//   

    // Homework: sort array by increasing frequency (Leetcode-1636)  ----->>>

//*********************************************************************************************************************//   

    // vector<int> arr = {1,2,3,4,5,6};  int x = 3;  int k = 4;  // find k closest element from x (Leetcode-658)
    // for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";  cout<<endl;
    // cout<<k<<" closest element from "<<x<<": ";
    // vector<int> ans = findClosestElements(arr,k,x);
    // for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";  cout<<endl;

//*********************************************************************************************************************//   

    // vector<vector<int>> v = {{3,3},{5,-1},{-2,4}};  int k = 2;  // (Leetcode-973)
    // cout<<"Our points are: ";
    // for(int i=0; i<v.size(); i++) cout<<"{"<<v[i][0]<<","<<v[i][1]<<"} ";  cout<<endl;
    // cout<<k<<" closest points from origin: ";
    // vector<vector<int>> ans = KClosest(v,k);
    // for(int i=0; i<ans.size(); i++) cout<<"{"<<ans[i][0]<<","<<ans[i][1]<<"} ";  cout<<endl;

//*********************************************************************************************************************//   

    // last stone weight problem (Leetcode-1046)

//*********************************************************************************************************************//   

    // vector<int> v = {6,5,3,2,8,10,9};
    vector<int> v = {2,7,4,1,8};
    cout<<"Ropes of different length: ";
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";  cout<<endl;
    cout<<"Minimum cost to tie all the ropes: "<<ropeCost(v)<<endl;

//*********************************************************************************************************************//   


    return 0;
}

int kthSmallest(vector<int> v, int k){
    int n = v.size();

    // priority_queue<int,vector<int>,greater<int>> pq(v.begin(),v.end());  // we can also fill vector elements like this
    // // priority_queue<int,vector<int>,greater<int>> pq;  // using minHeap (not a optimal approach)
    // // for(int i=0; i<n; i++) pq.push(v[i]);  // O(log(n!))
    // for(int i=1; i<k; i++) pq.pop();  // Time complexity: O(klogn) + O(log(n!))
    // return pq.top();

    priority_queue<int> pq;  // maxHeap will be used in this case 
    for(int i=0; i<n; i++){  
        pq.push(v[i]);  // Time complexity: O(nlogk) as push and pop will take O(logk) and traversing O(n)
        if(pq.size()>k) pq.pop(); // atmost k element will be in the heap 
    }
    return pq.top();
}
int kthLargest(vector<int> v, int k){  // Leetcode-215
    int n = v.size();

    // priority_queue<int> pq(v.begin(),v.end());  // we can also fill vector elements like this
    // // priority_queue<int> pq;  // using maxHeap (not a optimal approach)
    // // for(int i=0; i<n; i++) pq.push(v[i]);  // O(log(n!))
    // for(int i=1; i<k; i++) pq.pop();  // Time complexity: O(klogn) + O(log(n!))
    // return pq.top();
    
    priority_queue<int,vector<int>,greater<int>> pq;  // minHeap will be used in this case 
    for(int i=0; i<n; i++){  
        pq.push(v[i]);  // Time complexity: O(nlogk) as push and pop will take O(logk) and traversing O(n)
        if(pq.size()>k) pq.pop(); // atmost k element will be in the heap 
    }
    return pq.top();
}

void K_sorted(vector<int> &v, int k){
    int n = v.size();
    // vector<int> ans;   // space complexity: O(n), we can do it in O(1) if we change in original array itself 
    int idx = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0; i<n; i++){
        pq.push(v[i]);         // Time complexity: O(nlogk)
        if(pq.size()>k){
            // ans.push_back(pq.top());
            v[idx++] = pq.top();  // now the space complexity: O(1)
            pq.pop();
        }
    }
    while(pq.size()>0){
        // ans.push_back(pq.top());
        v[idx++] = pq.top();
        pq.pop();
    }
    // for(int i=0; i<n; i++) v[i] = ans[i];  // no need to write this line as we have made change in original vector
}

vector<int> topKfrequent(vector<int> &arr, int k){  // Leetcode-347
    // we can sort using maps by custom comparator sorting then store element into the vector
    int n = arr.size();
    unordered_map<int,int> map;
    for(int i=0; i<n; i++) map[arr[i]]++;
    priority_queue<p,vector<p>,greater<p>> heap;
    for(auto x: map){
        heap.push({x.second,x.first});  // we can alo write it like pair<int,int> p = {x.second,x.first} and heap.push(p)
        if(heap.size()>k) heap.pop();
    }
    vector<int> ans;
    while(heap.size()>0){
        ans.push_back(heap.top().second);
        heap.pop();
    }
    return ans;
}

vector<int> findClosestElements(vector<int> &arr, int k, int x){  // Leetcode-658
    priority_queue<pair<int,int>> heap;
    int n = arr.size();
    for(int i=0; i<n; i++){
        heap.push({abs(arr[i]-x),arr[i]});  // Time complexity: O(nlogk)
        if(heap.size()>k) heap.pop();  // one more important thing if there are two pairs with same key value
    }                                   // p1 = {2,5} and p2 = {2,1} so in max heap p1 will be at the top 
    vector<int> ans;                     // when both first value are same then we check the second one 
    while(heap.size()>0){
        ans.push_back(heap.top().second);
        heap.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}

vector<vector<int>> KClosest(vector<vector<int>> &arr, int k){  // Leetcode-973
    priority_queue<piv> pq;
    // for(vector<int> v: arr){
    for(auto v: arr){
        pq.push({(v[0]*v[0] + v[1]*v[1]),v});   // Time complexity: O(nlogk)
        if(pq.size()>k) pq.pop();   
    }
    vector<vector<int>> ans;
    while(pq.size()>0){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int lastStoneWeight(vector<int> &arr){  // Leetcode-1046

    // priority_queue<int> pq;
    // for(int ele: arr) pq.push(ele);
    // while(pq.size()>1){                 // Time complexity: O(log(n!))+O(nlogn)
    //     int x = pq.top(); pq.pop();
    //     int y = pq.top(); pq.pop();
    //     if(x!=y) pq.push(x-y);
    // }
    // if(pq.size()==1) return pq.top();
    // else return 0;

    int n = arr.size();
    while(arr.size()>1){
        sort(arr.begin(),arr.end());       // Time complexity: O(nlogn) but it is more than previous approach 
        int x = arr[n-1]; arr.pop_back();
        int y = arr[n-1]; arr.pop_back();
        if(x!=y) arr.push_back(x-y);
    }
    if(arr.size()==1) return arr[0];
    else return 0;

}

int ropeCost(vector<int> &v){
    priority_queue<int,vector<int>,greater<int>> heap;
    for(int ele: v) heap.push(ele);
    int sum = 0;
    while(heap.size()>1){
        int x = heap.top(); heap.pop();
        int y = heap.top(); heap.pop();
        heap.push(x+y);
        sum += (x+y);
    }
    // if(heap.size()==1) sum += heap.top();  // this condition will never be executed as there will be always 2 elements
    return sum;
}

