#include<bits/stdc++.h>
#include<cmath>
using namespace std;

void initialize_vector(vector<int> &v, int n);
void display_vector(vector<int> &v);
bool linear_search(vector<int> &v, int x);
bool binary_search(vector<int> &v, int x);   // Leetcode-704
int get_index(vector<int> &v, int x);
int lower_bound(vector<int> &v, int x);
int upper_bound(vector<int> &v, int x);
int first_occ_idx(vector<int> &v, int x);
int last_occ_idx(vector<int> &v, int x);
pair<int,int> occurence(vector<int> &v, int x);
vector<int> occurence_2(vector<int> &v, int x);  // Leetcode-34
vector<int> occ_vector(vector<int> &v, int x);
int smallest_missing(vector<int> &v);
int square_root_1(int x);   // Leetcode-69
int square_root_2(int x);

int main(){

//*********************************************************************************************************************//

    // vector<int> v;
    // int n,x;
    // cout<<"Enter size of the array: ";
    // cin>>n;
    // initialize_vector(v,n);
    // cout<<"Element you want to search: ";
    // cin>>x;

    // // if(linear_search(v,x)) cout<<"Elemet is present"<<endl;  // Time complexity --> O(n)
    // // else cout<<"Element is absent"<<endl;

    // if(!binary_search(v,x)) cout<<"Element is not present in the array"<<endl; // Time complexity --> O(logn)
    // else cout<<"Element is present at "<<get_index(v,x)<<" index in the array"<<endl;

//*********************************************************************************************************************//

    // vector<int> v;   // take such cases which can make you understand 
    // int n,x;
    // cout<<"Enter size of the array: ";
    // cin>>n;
    // initialize_vector(v,n);
    // cout<<"Enter num: ";
    // cin>>x;
    // cout<<upper_bound(v,x)<<" index is the upper bound"<<endl;
    // cout<<lower_bound(v,x)<<" index is the lower bound"<<endl;

//*********************************************************************************************************************//

    // vector<int> v;
    // int n,x;
    // cout<<"Enter size of the array: ";
    // cin>>n;
    // initialize_vector(v,n);
    // cout<<"Enter num: ";                 // Leetcode-34 (first and last position of element in a sorted array)
    // cin>>x;
    // cout<<"First occurence index of "<<x<<" is: "<<first_occ_idx(v,x)<<endl;
    // cout<<"Last occurence index of "<<x<<" is: "<<last_occ_idx(v,x)<<endl;

//*********************************************************************************************************************//

    // vector<int> v;
    // int n,x;
    // cout<<"Enter size of the array: ";
    // cin>>n;
    // initialize_vector(v,n);
    // cout<<"Enter num: ";
    // cin>>x;

    // // pair<int,int> ans = occurence(v,x);
    // // if(ans.first != -1 && ans.second != -1){
    // //     cout<<"First occurence: "<<ans.first<<endl;
    // //     cout<<"Second occurence: "<<ans.second<<endl;
    // // } 
    // // else{
    // //     cout<<"Element not found in the array"<<endl;
    // // }

    // vector<int> ans = occurence_2(v,x);
    // if(ans[0] != -1 && ans[1] != -1){
    //     cout<<"First occurence: "<<ans[0]<<endl;
    //     cout<<"Second occurence: "<<ans[1]<<endl;
    // } 
    // else{
    //     cout<<"Element not found in the array"<<endl;
    // }

    // // vector<int> a = occ_vector(v,x);
    // // if(a[0] != -1 && a[1] != -1){
    // //     display_vector(a);
    // // } 
    // // else{
    // //     cout<<"Element not founf in the array"<<endl;
    // // } 
    // /* When you write display_vector(occ_vector(v, x));,
    // you are attempting to pass the temporary vector returned by occ_vector directly to display_vector. 
    // However, the parameter of display_vector is expecting a reference to a vector, not a temporary vector object */ 

//*********************************************************************************************************************//

    // vector<int> v;
    // int n;
    // cout<<"Enter the size of the array: ";
    // cin>>n;
    // initialize_vector(v,n);
    // if(smallest_missing(v) == -1) cout<<"nothing is missing"<<n;
    // else cout<<"Smallest missing element: "<<smallest_missing(v)<<endl;

//*********************************************************************************************************************//

    int x;
    cout<<"Enter number: ";
    cin>>x;
    // int result = square_root_1(x);
    // cout<<"square root of "<<x<<" is: "<<result<<endl;
    int result = square_root_2(x);
    cout<<"Square root of "<<x<<" is: "<<square_root_2(x)<<endl;

//*********************************************************************************************************************//

    // Implementing binary search algorithem using recursion 

//*********************************************************************************************************************//

    return 0;
}

void initialize_vector(vector<int> &v,int n){
    cout<<"Enter you elements in the array: "<<endl;
    for(int i=0; i<n; i++){
        int x;  cin>>x;  v.push_back(x);
    }       
}

void display_vector(vector<int> &v){
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";  cout<<endl;
}

bool linear_search(vector<int> &v, int x){
    for(int i=0; i<v.size(); i++) if(x == v[i]) return true;
    return false;
}

bool binary_search(vector<int> &v, int x){   // Leetcode-704
    int n = v.size(), lowb = 0, upb = n-1;   // work only when vector is sorted (acsending or descending)
    while(lowb<=upb){   // when lower bound is less than upper bound then we can.t proceed further 
        int mid = lowb+((upb-lowb)/2);     // Time complexity: O(logn)

        // if(v[mid] == x) return true;       // in case of ascending order
        // else if(v[mid] < x) lowb = mid+1;
        // else upb = mid-1;

        if(v[mid] == x) return true;       // in case of descending order
        else if(v[mid] > x) lowb = mid+1;
        else upb = mid-1;
    }
    return false;
}

int get_index(vector<int> &v, int x){       // this function return index of target element 
    int n = v.size(), lowb = 0, upb = n-1;
    while(lowb<=upb){
        int mid = lowb+((upb-lowb)/2);   // Time complexity: O(n)

        // if(v[mid] == x) return mid;     // ascending order 
        // else if(v[mid] < x) lowb = mid+1;
        // else upb = mid-1;

        if(v[mid] == x) return mid;       // descending order
        else if(v[mid] > x) lowb = mid+1;
        else upb = mid-1;
    }
    return -1;  // it means elements not exist that's why return -1 index 
}

int lower_bound(vector<int> &v, int x){        

    //******************************** Method-1 ********************************//
    // int n = v.size();        // in case of ascending order
    // for(int i=0; i<n; i++){                  // Time complexity: O(n)
    //     if(v[i] >= x) return i-1;  // it means larger or same element found, now return i-1 index 
    // }
    // return n-1;  // it means target element x is largest element in vector

    //******************************** Method-2 ********************************//
    // int n = v.size();        // in case of descending order
    // for(int i=0; i<n; i++){                  // Time complexity: O(n)
    //     if(v[i] < x) return i;     // as soon as the smallest element found return index as it will be the lower bound 
    //     else if(v[i] == x) return i+1;   // if exact same element occure then the next upcoming index is ans 
    // }
    // return n;  // it means target element is smallest in vector

    //******************************** Method-3 ********************************//
    int n = v.size(), lowb = 0, upb = n-1, mid;
    while(lowb<=upb){                 // Time complexity: O(logn)
        mid = lowb+((upb-lowb)/2);    // in case od acsending order
        if(v[mid] == x) return mid-1;
        else if(v[mid] < x) lowb = mid+1;  
        else upb = mid-1;
    }
    return upb; // return upper bound after while loop if element is not found in the vector 

    //******************************** Method-4 ********************************//
    // int n = v.size(), lowb = 0, upb = n-1, mid;
    // while(lowb<=upb){                 // Time complexity: O(logn)
    //     mid = lowb+((upb-lowb)/2);   // in case of descending order
    //     if(v[mid] == x) return mid+1;
    //     else if(v[mid] > x) lowb = mid+1;  
    //     else upb = mid-1;
    // }
    // return lowb; // return lower bound after while loop if element is not found in the vector 
}

int upper_bound(vector<int> &v, int x){

    //******************************** Method-1 ********************************//
    // int n = v.size();        // in case of ascending order
    // for(int i=0; i<n; i++){                  // Time complexity: O(n)
    //     if(v[i] > x) return i;    // as soon as the larger element found then that will be upper bound 
    //     else if(v[i] == x) return i+1;  // when same element found then next eleemnt will be the greater one 
    // }
    // return n;  // it means target element x is largest element in vector

    //******************************** Method-2 ********************************//
    // int n = v.size();        // in case of descending order
    // for(int i=0; i<n; i++){                  // Time complexity: O(n)
    //     if(v[i] <= x) return i-1;   // as soon as either smalles or same element found retun index-1 as upper bound
    // }
    // return n-1;  // for smallest element in the vector 

    //******************************** Method-3 ********************************//
    int n = v.size(), lowb = 0, upb = n-1, mid;
    while(lowb<=upb){                        // Time complexity: O(logn)
        mid = lowb+((upb-lowb)/2);           // in case of ascending order
        if(v[mid] == x) return mid+1;
        else if(v[mid] < x) lowb = mid+1;
        else upb = mid-1;
    }
    return lowb;  // return lower bound after while loop if element is not found in the vector 

    //******************************** Method-4 ********************************//
    // int n = v.size(), lowb = 0, upb = n-1, mid;
    // while(lowb<=upb){                        // Time complexity: O(logn)
    //     mid = lowb+((upb-lowb)/2);           // in case of descending order
    //     if(v[mid] == x) return mid+1;
    //     else if(v[mid] > x) lowb = mid+1;
    //     else upb = mid-1;
    // }
    // return upb;  // return upper bound after while loop if element is not found in the vector 
}

int first_occ_idx(vector<int> &v, int x){
    int n = v.size(), lowb = 0, upb = n-1, mid;
    while(lowb<=upb){                                // Time complexity: O(logn)
        mid = lowb + ((upb-lowb)/2);
        if(v[mid] == x){   
            if(v[mid-1] == x && (mid-1)>=0) upb = mid-1;  // (mid-1)>=0 will reduce the chances of error
            else return mid;                       // as when mid = 0 then mid-1 will be the out of index
        }
        else if(v[mid] < x) lowb = mid+1;  // in case of increasing order
        // else if(v[mid] > x) lowb = mid+1;  // in case of decreasing order
        else upb = mid-1;
    }
    return -1;   // if element is absent in the vector 
}

int last_occ_idx(vector<int> &v, int x){
    int n = v.size();
    int lowb = 0;
    int upb = n-1;
    int mid;
    while(lowb<=upb){
        mid = lowb + ((upb-lowb)/2);
        if(v[mid] == x){
            if(v[mid+1] == x && (mid+1)<n){
                lowb = mid+1;
            }
            else{
                return mid;
            }
        }
        else if(v[mid] < x){
            lowb = mid+1;
        }
        else{
            upb = mid-1;
        }
    }
    return -1;
}

pair<int,int> occurence(vector<int> &v, int x){
    int n = v.size();
    int first_occ = -1;
    int last_occ = -1;
    int low = 0;
    int high = n-1;
    int mid;
    while(low<=high){
        mid = low+((high-low)/2);
        if(v[mid] == x){
            first_occ = mid;
            last_occ = mid;
            while(first_occ>0 && v[first_occ-1]==x){
                first_occ--;
            }
            while(last_occ<n-1 && v[last_occ+1]==x){
                last_occ++;
            }
            return {first_occ,last_occ};
        }
        else if(v[mid] < x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return {first_occ,last_occ};
}

vector<int> occurence_2(vector<int> &v, int x){   // Leetcode-34
    int n = v.size();
    int first_occ = -1;
    int last_occ = -1;
    int low = 0;
    int high = n-1;
    int mid;
    while(low<=high){
        mid = low+((high-low)/2);
        if(v[mid] == x){
            first_occ = mid;
            last_occ = mid;
            while(first_occ>0 && v[first_occ-1]==x){
                first_occ--;
            }
            while(last_occ<n-1 && v[last_occ+1]==x){
                last_occ++;
            }
            return {first_occ,last_occ};
        }
        else if(v[mid] < x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return {first_occ,last_occ};
}

vector<int> occ_vector(vector<int> &v, int x){
    int n = v.size();
    vector<int> occ;
    int first_occ = -1;
    int last_occ = -1;
    int low = 0;
    int high = n-1;
    int mid;
    while(low<=high){
        mid = low+((high-low)/2);
        if(v[mid] == x){
            first_occ = mid;
            last_occ = mid;
            while(first_occ>0 && v[first_occ-1]==x){
                first_occ--;
            }
            while(last_occ<n-1 && v[last_occ+1]==x){
                last_occ++;
            }
            occ.push_back(first_occ);
            occ.push_back(last_occ);
            return occ;
        }
        else if(v[mid] < x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    occ.push_back(first_occ);
    occ.push_back(last_occ);
    return occ;
}
    
int smallest_missing(vector<int> &v){
    int n = v.size(), low = 0, high = n-1, mid, ans = -1;
    while(low<=high){
        mid = low+((high-low)/2);
        if(v[mid] == mid) low = mid+1;
        else{
            ans = mid;
            high = mid-1;
        }
    }
    return ans;  // return -1 when all the element equal to their index it means no missing element 
}

int square_root_1(int x){   // Leetcode-69
    for(int i=0; i<x; i++){      // code valid only for perfect square numbers 
        if(i*i == x) return i;   // Time complexity: O(n)
    }
    return -1;  // when there is no square root found 
}

int square_root_2(int x){
    int low = 0, high = x, mid = -1;
    while(low<=high){
        mid = low+((high-low)/2);
        long long n = (long long)mid;  // we have taken long long to be executed for large numbers 
        long long y = (long long)x;    // Time complexity: O(logn)
        if(n*n == y) return mid;
        else if(n*n > y) high = mid-1;
        else low = mid+1;
    }
    return high;  // return just smaller number if the number is not a prefect sqaure (for ex: 20, ans will be 4)
}