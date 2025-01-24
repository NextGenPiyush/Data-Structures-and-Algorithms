#include<bits/stdc++.h>
using namespace std;

int maxSumSubarray(int arr[], int n, int k); 

int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int min);  // Leetcode-1052
int maxSatisfied_2(vector<int> &customers, vector<int> &grumpy, int min);  // Leetcode-1052

int minSubArrayLen(int target, vector<int>& nums);  // Leetcode-209

int longestOnes(vector<int>& nums, int k);  // Leetcode-1004

int longestSubarray(vector<int>& nums);  // Leetcode-1493

int SubarrayProductLessThanK(vector<int> &nums, int k); //Leetcode-713 

int main(){

//***********************************************************************************************************************//

    // int n,k;
    // cout<<"Enter the size of array: ";  cin>>n;
    // int arr[n];
    // cout<<"Enter size of subarray: ";  cin>>k;
    // cout<<"Subarray with max sum start with: "<<maxSumSubarray(arr,n,k)<<endl;

//***********************************************************************************************************************//

    // int n,k;
    // cin>>n>>k;
    // int arr[n];
    // cout<<"Enter the elements of the array: "<<endl;
    // for(int i=0; i<n; i++) cin>>arr[i];
    // int ans[n-k+1];
    // int index = -1;
    // for(int i=0; i<k; i++){
    //     if(arr[i]<0){
    //         index = i;
    //         break;
    //     }
    // }
    // if(index == -1) ans[0] = 1; // there is no negative element in the first window of the given array
    // else ans[0] = arr[index]; 
    // int i=1,j=k;
    // while(j<n){
    //     if(index >= i) ans[i] = arr[index]; // index of first negative element in the window is still index
    //     else{
    //         index = -1;
    //         for(int x=i; x<=j; x++){
    //             if(arr[x]<0){
    //                 index = x;
    //                 break;
    //             }
    //         }
    //         if(index != -1) ans[i] = arr[index];
    //         else ans[i] = 1;  // there is window in between which does'nt have any negative window
    //     }
    //     i++; j++;
    // }

//***********************************************************************************************************************//

    return 0;

}

int maxSumSubarray(int arr[], int n, int k){  // Sliding Window 

    int maxSum = INT_MIN;
    int maxIdx = -1;

    // for(int i=0; i<n-k; i++){  // Time complexity: O(k*n)
    //     int sum = 0;
    //     for(int j=i; j<i+k; j++) sum += arr[j];
    //     if(maxSum < sum){
    //         maxSum = sum;
    //         maxIdx = i;
    //     }
    // }

    int sum = 0; 
    for(int i=0; i<k; i++) sum += arr[i];
    int i=0, j=k;
    while(j<n){   // Time complexity: O(n) = O(k) + O(n-k)
        sum += arr[j++]-arr[i++];
        if(maxSum < sum){
            maxSum = sum;
            maxIdx = i;
        }
    }

    return maxIdx;
} 

int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int min){  // Leetcode-1052 (mera method)
    long long sum_with_grumpy = 0;
    long long sum_without_grumpy = 0;  // Time Complexity: O(n) where n is the size of customers vector
    int n = customers.size();
    for(int i=0; i<min; i++){
        if(grumpy[i] == 0) sum_with_grumpy += (long long)customers[i];
        sum_without_grumpy += (long long)customers[i];
    }
    long long max_dif = sum_without_grumpy-sum_with_grumpy; 
    int i=0, j=min;
    int index = 0;
    while(j<n){

        // if(grumpy[i] == 0 && grumpy[j] == 0) sum_with_grumpy += (long long)(customers[j]-customers[i]);
        // else if(grumpy[i] == 0) sum_with_grumpy -= (long long)customers[i];
        // else if(grumpy[j] == 0) sum_with_grumpy += (long long)customers[j];

        if(grumpy[j] == 0) sum_with_grumpy += (long long)customers[j];  // we can also do that
        if(grumpy[i] == 0) sum_with_grumpy -= (long long)customers[i];

        sum_without_grumpy += (long long)(customers[j]-customers[i]);
        long long new_dif = sum_without_grumpy-sum_with_grumpy;
        if(new_dif > max_dif){
            max_dif = new_dif;
            index = i;
        } 
        i++; j++;
    } 
    long long ans = 0;
    for(int i=0; i<n; i++) if((i > index && i < index+min+1) || grumpy[i] == 0) ans += (long long)customers[i];
    return ans;
}

int maxSatisfied_2(vector<int> &customers, vector<int> &grumpy, int min){  // Leetcode-1052 (sir ka method)
    int n = customers.size();
    int pre_loss = 0;
    for(int i=0; i<min; i++) if(grumpy[i] == 1) pre_loss += customers[i];
    int i=0, j=min;
    int index = 0;
    int max_loss = pre_loss;
    while(j<n){
        int new_loss = pre_loss;
        if(grumpy[j] == 1) new_loss += customers[j];  // we can also do that
        if(grumpy[i] == 1) new_loss -= customers[i];
        if(new_loss > max_loss){
            max_loss = new_loss;
            index = i;
        } 
        pre_loss = new_loss;
        i++; j++;
    } 
    int ans = 0;
    for(int i=0; i<n; i++) if((i > index && i < index+min+1) || grumpy[i] == 0) ans += customers[i];
    return ans;
}

int minSubArrayLen(int target, vector<int>& nums){  // Leetcode-209
    int n = nums.size();
    int i=0,j=0;
    int sum = 0;
    int minLen = INT_MAX;
    while(j<n){    // Time complexity: O(n)
        sum += nums[j];
        while(sum>=target){
            minLen = min(minLen,j-i+1);
            sum -= nums[i++];
        }
        j++;
    }   
    if(minLen == INT_MAX) return 0;
    else return minLen;
}

int longestOnes(vector<int>& nums, int k){  // Leetcode-1004
    int n = nums.size();
    int index=0, j=0, flip = 0;   
    int maxLen = INT_MIN;
    while(j<n){
        if(nums[j] != 1){
            if(flip == k){
                maxLen = max(maxLen,j-index);
                for(int i=index; i<j; i++) if(nums[i] == 0) index = i+1;
            }
            else flip++;  
        }
        j++;
    }
    maxLen = max(maxLen,j-index);
    return maxLen; 
}

int longestSubarray(vector<int>& nums){ // Leetcode-1493 (Similar to Leetcode-1004 and can be solved by same approach)
    // but there it another mpre optimized approach
    int n = nums.size();
    int zeroPos = -1;
    int i=0,j=0,count=0;
    int maxLen = INT_MIN;
    while(j<n){
        int pre = zeroPos;
        if(nums[j] == 0){
            count++;
            zeroPos = j;
        }
        if(count<=1) j++;
        else{
            maxLen = max(maxLen,j-i);
            i = pre + 1; // set index to the next of zero 
            count--;
            j++;
        }
    }
    maxLen = max(maxLen,j-i);
    return maxLen-1;
}

int SubarrayProductLessThanK(vector<int> &nums, int k){  // Leetcode-713
    if(k<=1) return 0;
    int n = nums.size();
    int i=0,j=0,count=0,product=1;
    while(j<n){
        product *= nums[j];
        while(product >= k){
            count += j-i;
            product /= nums[i++];
        }
        j++;
    }
    while(i<n) count += j-i++;
    return count;
} 


