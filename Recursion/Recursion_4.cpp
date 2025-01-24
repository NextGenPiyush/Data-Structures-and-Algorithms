#include<bits/stdc++.h>
using namespace std;

void sub_array(vector<int> empty, int arr[], int n, int idx);
bool check_palindrome(string s, int stidx, int endidx);
int greatest_common_divisor_1(int a, int b);
int greatest_common_divisor_2(int a, int b);
void binary_string_1(string s, int n);
void binary_string_2(string s, int n);
void combination_sum_1(vector<int> v, int arr[], int n, int target);  // repeated ans aarhe h 
void combination_sum_2(vector<int> v, int arr[], int n, int target, int idx);  // problem solved
void generate_paranthesis(string empty, int open, int close, int n);
int kth_symbol(int n, int k);   // time complexity O(n)

int main(){

//******************************************************************************************************************//    

    // int arr[] = {1,2,3,4};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // cout<<"Printing subarrays: "<<endl;
    // // for(int i=0; i<n; i++){
    // //     for(int k=i; k<n; k++){
    // //         for(int j=i; j<=k; j++){
    // //             cout<<arr[j]<<" ";              // printing subarrays
    // //         }
    // //         cout<<endl;
    // //     }
    // // }

    // vector<int> v;
    // sub_array(v,arr,n,0);

//******************************************************************************************************************//    

    // // string s = "abcdcba";
    // string s = "abcdcef";
    // if(check_palindrome(s,0,s.size()-1) == 1){
    //     cout<<"String is a palindrome "<<endl;
    // }
    // else{
    //     cout<<"String is not a palindrome"<<endl;
    // }

//******************************************************************************************************************//    

    // int a,b;
    // cout<<"Enter num-1: ";
    // cin>>a;
    // cout<<"Enter num-2: ";
    // cin>>b;
    // cout<<"Greatest common divisor: "<<greatest_common_divisor_1(a,b)<<endl;
    // cout<<"Greatest common divisor: "<<greatest_common_divisor_2(a,b)<<endl;

//******************************************************************************************************************//    

    // int n;
    // cout<<"Enter length of binary string: ";
    // cin>>n;
    // binary_string_1("",n);
    // cout<<endl<<"no consecutive ones: "<<endl;
    // binary_string_2("",n);

//******************************************************************************************************************//    

    // int target;
    // cout<<"Enter your target: ";
    // cin>>target;
    // vector<int> v;
    // int arr[] = {2,3,5};   // distinct num, we can use a particular number unlimited times to get the target 
    // int n = sizeof(arr)/sizeof(arr[0]);
    // // combination_sum_1(v,arr,n,target);   // give repeated ans 
    // combination_sum_2(v,arr,n,target,0); 

//******************************************************************************************************************//    

    // int n;
    // cout<<"Enter number: ";
    // cin>>n;
    // generate_paranthesis("",0,0,n);

//******************************************************************************************************************//    

    // int n,k;
    // cout<<"Enter n: ";
    // cin>>n;
    // cout<<"Enter k: ";
    // cin>>k;
    // cout<<"ans: "<<kth_symbol(n,k)<<endl;

//******************************************************************************************************************//    

    

//******************************************************************************************************************//    



//******************************************************************************************************************//    



//******************************************************************************************************************//    



    return 0;
}

void sub_array(vector<int> empty, int arr[], int n, int idx){   // will work in unique elements only 
    if(idx == n){    
        for(int i=0; i<empty.size(); i++){
            cout<<empty[i];
        }
        cout<<endl;
        return;
    }
    sub_array(empty,arr,n,idx+1);
    if(empty.size() == 0 || arr[idx-1] == empty[empty.size()-1]){
    empty.push_back(arr[idx]);
    sub_array(empty,arr,n,idx+1);
    }
}

bool check_palindrome(string s, int stidx, int endidx){
    if(stidx >= endidx){
        return true;
    }
    if(s[stidx] == s[endidx]){
        return check_palindrome(s,stidx+1,endidx-1);
    }
    else{
        return false;
    }
}

int greatest_common_divisor_1(int a, int b){    // time complexity O(min(a,b));
    int c = min(a,b);
    int d = max(a,b);
    for(int i=c; i>=2; i--){
        if(c%i == 0 && d%i == 0){
            return i;
        }
    }
    return 1;
}

int greatest_common_divisor_2(int a, int b){     // time complexity O(log(a+b))
    if(a == 0){
        return b;
    }
    return greatest_common_divisor_2(b%a,a);       // dry run this code for both case when a>b and a<b   
}

void binary_string_1(string s, int n){
    if(s.length() == n){
        cout<<s<<endl;
        return;
    } 
    binary_string_1(s+'0',n);    // here we can also do by decrementing n by 1 and change the base case to if(n==0)
    binary_string_1(s+'1',n);
}

void binary_string_2(string s, int n){    // no consecutive 1s ones
    if(s.length() == n){
        cout<<s<<endl;
        return;
    } 
    binary_string_2(s+'0',n);    
    if (s == "" || s[s.length()-1] == '0') binary_string_2(s+'1',n);
}
    
void combination_sum_1(vector<int> v, int arr[], int n, int target){
    if(target == 0){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(target<0) return;
    for(int i=0; i<n; i++){
        v.push_back(arr[i]);
        combination_sum_1(v,arr,n,target-arr[i]);
        v.pop_back();
    }
}

void combination_sum_2(vector<int> v, int arr[], int n, int target, int idx){   // try to dry run with proper diagram
    if(target == 0){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(target<0) return;
    for(int i=idx; i<n; i++){
        v.push_back(arr[i]);
        combination_sum_2(v,arr,n,target-arr[i],i);
        v.pop_back();
    }
}

void generate_paranthesis(string empty, int open, int close, int n){
    if(open == n && close == n){
        cout<<empty<<" ";
        return;
    } 
    if(close<open) generate_paranthesis(empty+')',open,close+1,n);
    if(open<n) generate_paranthesis(empty+'(',open+1,close,n);
}

int kth_symbol(int n, int k){   // time complexity O(n)
   if(n==1){
    return 0;
   }
   if(k%2==0){
        int PrevAns = kth_symbol(n-1,k/2);
        if(PrevAns == 0) return 1;
        else return 0;
   }
   else{
        int PrevAns = kth_symbol(n-1,k/2+1);
        return PrevAns;
   }
}

