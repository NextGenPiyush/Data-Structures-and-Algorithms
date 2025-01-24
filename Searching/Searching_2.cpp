#include<bits/stdc++.h>
using namespace std;

int peakIndexMountainArray(vector<int> &ans);  // Leetcode-852

int rotatedSortedArraySearch(vector<int> &nums, int target);  // Leetcode-33
int pivot_index(vector<int> nums);
int binary_search(vector<int> nums, int low, int high, int target);

vector<int> find_K_closest(vector<int> &arr, int k, int x);  // Leetcode-658

bool judgeSquareSum(int c);  // Leetcode-633

int main(){

//*******************************************************************************************************************//

    // vector<int> v = {1,2,5,4,3,2,1};  // mountain array
    // cout<<"Peak in mountain array: "<<v[peakIndexMountainArray(v)]<<endl;  // Leetcode-852

//*******************************************************************************************************************//

    // search in a rotated sorted array (Leetcode-33)  --> good question 

//*******************************************************************************************************************//

    // finding k closest element and return it in a vector after sorting (Leetcode-658) --> good question

//*******************************************************************************************************************//

    // find are there two numbers a and b for which a^2 + b^2 = c (Leetcode-633)

//*******************************************************************************************************************//


    return 0;
}

int peakIndexMountainArray(vector<int> &ans){  // Leetcode-852
    int n = ans.size();

    // for(int i=1; i<n-1; i++) if(ans[i]>ans[i-1] && ans[i]>ans[i+1]) return i;  Time complexity: O(n)
    // return -1;  // No peak element in the vector

    int low = 1;       // no need to take low = 0
    int high = n-2;    // no need to take high = n-1
    int mid;
    while(low<=high){
        mid = low+((high-low)/2);  // Time complexity: O(logn)
        if(ans[mid] > ans[mid+1] && ans[mid] > ans[mid-1]) return mid;
        else if(ans[mid] > ans[mid-1]) low = mid+1;
        else high = mid-1;
    }
    return -1;   // no peak element in the vector
}

int rotatedSortedArraySearch(vector<int> &nums, int target){   // Leetcode-33 
    if(nums.size() == 2){  // handling the case when n=2
        if(nums[0] == target) return 0;
        else if(nums[1] == target) return 1;
        else return -1;
    }                                 // we can also solve this problem using simple lenear seach
    int pivot = pivot_index(nums);    // using binary search reduces the search space and make complexity much better
    if(pivot == -1) return binary_search(nums,0,nums.size()-1,target);  //search on full array as no rotation in the vector  
    if(target >= nums[0] && target <= nums[pivot-1]) return binary_search(nums,0,pivot-1,target);
    else if(target >= nums[pivot] && target <= nums[nums.size()-1]) return binary_search(nums,pivot,nums.size()-1,target);
    else return -1;  // when target is not present in the sorted array 
}
int pivot_index(vector<int> nums){  
    int n = nums.size(), low = 0, high = n-1, mid = 0;
    while(low<=high){  // pivot = smallest element index 
        mid = low + (high-low)/2;
        if(mid == 0) low = mid+1;
        else if(mid == n-1) high = mid-1;
        else if(nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1]) return mid; // return smallest element index 
        else if(nums[mid] > nums[mid+1] && nums[mid] > nums[high]) return mid+1;     
        // this codition will help you to get to the pivot index faster as in rotated sorted vector 
        // smallest element will be the next of  the largets element in the vector 
        else if(nums[mid] > nums[high]) low = mid+1;
        else high = mid-1;  // when nums[mid] < nums[high]
    }
    return -1;  // it means vector is already sorted and there is no rotation in the vector 
}
int binary_search(vector<int> nums, int low, int high, int target){
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

vector<int> find_K_closest(vector<int> &arr, int k, int x){   // Leetcode-658
    int n = arr.size();
    vector<int> ans(k);  // vector os size k as we want to insert only k elements in the vector 
    if(x<arr[0]){   // case-1 --> x is the smaller element in comaprison to all the elements of the arr  
        for(int i=0; i<k; i++) ans[i] = arr[i]; // so startig element will the closest elements in the arr
        return ans;
    }
    if(x>arr[n-1]){  // case-2 --> x is the larger element in comaprison to all the elements of the arr  
        int i=n-1;
        int j=k-1;
        while(j>=0) ans[j--] = arr[i--];  // so ending element will the closest elements in the arr
        return ans;                  // space complexity: O(k) we have used an extra vector of size k
    }                      // Total Time complexity: O(logn + klogk) --> binary search + in-built sorting

    int low = 0, high = n-1, t = 0, mid = 0;
    bool flag = false;
    while(low<=high){             // Binary search traversal on the given vector
        mid = low + (high-low)/2;
        if(arr[mid] == x){
            ans[t] = arr[mid]; // if the element present then it will inserted in the vector and index incremented by one
            t++; flag = true; break;
        }
        else if(arr[mid]>x) high = mid-1;
        else low = mid+1;  
    }
    int lower_bound = high, upper_bound = low;
    if(flag == true){  // if the element is present then the lower and upper bound can be easily writen 
        lower_bound = mid-1;
        upper_bound = mid+1;
    }

    while(t<k && lower_bound>=0 && upper_bound<=n-1){  // case-3 --> when the element lower and upper bound in the arr
        int d1 = abs(x-arr[lower_bound]);
        int d2 = abs(x-arr[upper_bound]);
        if(d1 <= d2){
            ans[t] = arr[lower_bound];
            lower_bound--;
        }
        else{
            ans[t] = arr[upper_bound];
            upper_bound++;
        }
        t++; 
    }
    if(lower_bound < 0){ // case-4 --> when there is no lower bound or lower bound is negative 
        while(t<k){
            ans[t] = arr[upper_bound];
            upper_bound++; t++;
        }
    }
    if(upper_bound > n-1){ // case-5 --> when there is no upper bound or upper bound is equal to n (size of arr) 
        while(t<k){
            ans[t] = arr[lower_bound];
            lower_bound--; t++;
        }
    }
    sort(ans.begin(),ans.end()); // Time complexity: O(klogn)
    return ans;
}

bool judgeSquareSum(int c){  // Leetcode-633
    int x = 0, y = c;                            // Time complexity: O(c^(1/2))
    while(x<=y){                                 // space complexity: O(1)
        if(isPerfectSquare(x) && isPerfectSquare(y)) return true; // means number choosen are both perfect square
        else if(!isPerfectSquare(y)){  // if y is not a perfect square 
            y = int(sqrt(y))*int(sqrt(y));  // then make y perfect square by reducing value
            x = c-y;
        } 
        else{  // if x is not a perfect square
            x = int(sqrt(x)+1)*int(sqrt(x)+1);  // then make x perfect square by exceeding value
            y = c-x;
        }
    }
    return false;
}
bool isPerfectSquare(int n){
    int root = sqrt(n);
    if(root*root == n) return true;
    else return false;
}
