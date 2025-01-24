#include<bits/stdc++.h>
using namespace std;

void hanoi(int n, char s, char h, char d);
void display_1(int arr[], int n, int idx);
void display_2(int arr[], int n);
void display_vector(vector<int> &v, int idx);
void max_of_arr(int arr[], int n, int &max_ele);
int maximum(int arr[], int n, int idx);
string remove_char_1(string ans, string str);
string remove_char_2(string ans, string str, int idx);
vector<int> remove_1(int arr[], int n, int idx, vector<int> &v);
void string_subsets(string empty, string str);
void storing_subsets(string empty, string str, vector<string> &v);
void storing_subsets(string empty, string str, vector<string> &v, bool flag);
void array_subsets(int arr[], int n, int idx, vector<int> v);
void helper_function(vector<vector<int>> &v, vector<int> ans, vector<int> &arr, int idx);
vector<vector<int>> subsets(vector<int> &arr);
void array_subsequence(int arr[], int n, int idx, vector<int> v, int k);
void permutation(string empty, string str);

int main(){

//*********************************************************************************************************************//

    // int n;
    // cout<<"Enter the number of disk: ";
    // cin>>n;
    // hanoi(n,'a','b','c');

//*********************************************************************************************************************//

    // int arr[] = {1,2,3,4,5,6,7};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // cout<<"Printing array: "<<endl;
    // // display_1(arr,n,0);
    // display_2(arr,n);
    // cout<<endl;

    // vector<int> v = {1,2,3,4,5,6,7,8,9,0,9,8,7,6,5};
    // cout<<"Printing vector: "<<endl;
    // display_vector(v,0);

//*********************************************************************************************************************//

    // int arr[] = {1,2,4,5,8,6,4,10,8,3,2,1};  // max value is 10
    // int n = sizeof(arr)/sizeof(arr[0]);
    // // int maximum = INT_MIN;
    // // max_of_arr(arr,n,maximum);
    // // cout<<"Maximum value in the array: "<<maximum<<endl;
    // cout<<"Maximum value in the array: "<<maximum(arr,n,0)<<endl;

//*********************************************************************************************************************//

    // string s = "Piyush Goyal";
    // cout<<s<<endl;
    // // string new_str;
    // // for(int i=0; i<s.length(); i++){    // without recursion 
    // //     if(s[i]!='y'){
    // //         // new_str += s[i];
    // //         new_str.push_back(s[i]);
    // //     }
    // // }
    // // cout<<new_str<<endl;
    // cout<<remove_char_1("",s)<<endl;
    // cout<<remove_char_2("",s,0)<<endl;

//*********************************************************************************************************************//

    // int arr[] = {1,2,3,1,2,4,3,2,1,78,53,1,1,5,6};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // vector<int> v;
    // v = remove_1(arr,n,0,v);
    // for(int i=0; i<v.size(); i++){
    //     cout<<v[i]<<" ";
    // }

//*********************************************************************************************************************//

    // // string s = "abc";
    // // // cout<<"Printing all subsets: "<<endl;
    // // // string_subsets("",s);

    // // vector<string> v;
    // // cout<<"Printing all subsets after storing in the vector: "<<endl;
    // // storing_subsets("",s,v);
    // // for(string ele : v){
    // //     cout<<ele<<endl;
    // // }

    // string s = "aab";
    // vector<string> v;
    // cout<<"Printing all subsets after storing in the vector: "<<endl;
    // storing_subsets("",s,v,true);
    // for(string ele : v){
    //     cout<<ele<<endl;
    // }

//*********************************************************************************************************************//

    // int arr[] = {1,2,3};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // vector<int> v;
    // array_subsets(arr,n,0,v);

//*********************************************************************************************************************//

    // vector<int> v = {1,2,3};
    // vector<vector<int>> ans;
    // ans = subsets(v);
    // for(int i=0; i<ans.size(); i++){
    //     cout<<"[";
    //     for(int ele: ans[i]){
    //         cout<<ele;
    //     }
    //     cout<<"]";
    //     cout<<endl;
    // }

//*********************************************************************************************************************//

    // int arr[] = {1,2,3,4,5,6};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // vector<int> v;
    // int k;
    // cout<<"Enter the number: ";
    // cin>>k;
    // if(k > n){
    //     cout<<"invalid input: "<<endl;
    //     return 0;
    // }
    // array_subsequence(arr,n,0,v,k);

//*********************************************************************************************************************//

    // string s = "abc";
    // cout<<"Printing all the permutations: "<<endl;
    // permutation("",s);

//*********************************************************************************************************************//

    return 0;
}

void hanoi(int n, char s, char h, char d){
    if(n==0) return;
    hanoi(n-1,s,d,h);              // n-1 disk from a->b using recusrion
    // cout<<s<<"->"<<d<<endl;        // biggest disk a->c
    hanoi(n-1,h,s,d);              // n-1 disk from b-> using recursion
}

void display_1(int arr[], int n, int idx){
    if(idx == n) return;
    cout<<arr[idx]<<" ";
    display_1(arr,n,idx+1);
}

void display_2(int arr[], int n){
    if(n == 0) return;
    display_2(arr,n-1);
    cout<<arr[n-1]<<" ";
}

void display_vector(vector<int> &v, int idx){
    if(idx == v.size()) return;
    cout<<v[idx]<<" ";
    display_vector(v,idx+1);
}

void max_of_arr(int arr[], int n, int &max_ele){    // we can also do it by taking extra input (int idx = 0;)
    if(n == 0) return;
    max_ele = max(max_ele,arr[n-1]);
    max_of_arr(arr,n-1,max_ele);
}

int maximum(int arr[], int n, int idx){
    if(idx == n) return INT_MIN;
    return max(arr[idx],maximum(arr,n,idx+1));
}
    
string remove_char_1(string ans, string str){
    if(str.length() == 0) return ans;
    if(str[0] != 'y') return remove_char_1(ans+str[0],str.substr(1)); // remove all 'y' characters from the string 
    else return remove_char_1(ans,str.substr(1));
}

string remove_char_2(string ans, string str, int idx){
    if(idx == str.length()) return ans;
    if(str[idx] == 'y') return remove_char_2(ans,str,idx+1);
    else return remove_char_2(ans+str[idx],str,idx+1);
}

vector<int> remove_1(int arr[], int n, int idx, vector<int> &v){
    if(idx == n) return v;
    if(arr[idx] == 1) return remove_1(arr,n,idx+1,v);
    else{
        v.push_back(arr[idx]);
        return remove_1(arr,n,idx+1,v);
    }
}

void string_subsets(string empty, string str){    // we can also do it by passing int idx;
    // if(str.length() == 0){
    if(str == ""){
        if(empty == "") cout<<"{}"<<endl;
        else cout<<"{"<<empty<<"}"<<endl;
        return;
    }
    string_subsets(empty+str[0],str.substr(1));
    string_subsets(empty,str.substr(1));
}

void storing_subsets(string empty, string str, vector<string> &v){
    if(str == ""){
        if(empty == "") v.push_back("{}");
        else v.push_back("{"+empty+"}");
        return;
    }
    storing_subsets(empty+str[0],str.substr(1),v);
    storing_subsets(empty,str.substr(1),v);
}

void storing_subsets(string empty, string str, vector<string> &v, bool flag){
    if(str == ""){
        if(empty == "") v.push_back("{}");
        else v.push_back("{"+empty+"}");
        return;
    }
    char ch = str[0];
    if(str.length()==1){
        if(flag == true) storing_subsets(empty+ch,str.substr(1),v,true);
        storing_subsets(empty,str.substr(1),v,true);
        return;
    }
    char dh = str[1];
    if(ch == dh){
        if(flag == true) storing_subsets(empty+ch,str.substr(1),v,true);
        storing_subsets(empty,str.substr(1),v,false);
    }
    else{
        if(flag == true) storing_subsets(empty+ch,str.substr(1),v,true);
        storing_subsets(empty,str.substr(1),v,true);
    }
}

void array_subsets(int arr[], int n, int idx, vector<int> v){
    if(idx == n){
        for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
        cout<<endl;
        return;
    }
    array_subsets(arr,n,idx+1,v);
    v.push_back(arr[idx]);
    array_subsets(arr,n,idx+1,v);
}

void helper_function(vector<vector<int>> &v, vector<int> ans, vector<int> &arr, int idx){
    if(idx == arr.size()){
        v.push_back(ans);
        return;
    }
    helper_function(v,ans,arr,idx+1);
    ans.push_back(arr[idx]);    
    helper_function(v,ans,arr,idx+1);
}

vector<vector<int>> subsets(vector<int> &arr){
    vector<vector<int>> v;
    vector<int> ans;
    helper_function(v,ans,arr,0);
    return v;
}

void array_subsequence(int arr[], int n, int idx, vector<int> v, int k){
    if(idx == n){
        if(v.size()==k){
            for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
            cout<<endl;
        }
        return;
    }
    if(v.size()+(n-idx)<k) return;        // time complexity will improve
    array_subsequence(arr,n,idx+1,v,k);
    v.push_back(arr[idx]);
    array_subsequence(arr,n,idx+1,v,k);
}

void permutation(string empty, string str){
    if(str.size() == 0){
        cout<<empty<<endl;
        return;
    }
    for(int i=0; i<str.size(); i++){
        if(i==0){
            // empty += str[i];
            // str = str.substr(i+1);
            permutation(empty+str[i],str.substr(i+1));
        }
        else if(i>0 && i<str.size()) permutation(empty+str[i],str.substr(0,i)+str.substr(i+1));
        else{
            // empty += str[i];
            // str = str.substr(0,i);
            permutation(empty+str[i],str.substr(0,i));
        }
        // char ch = str[i];                // we can also do it without making separate if-else condition
        // string left = str.substr(0,i);
        // string right = str.substr(i+1);
        // permutation(empty+ch,left+right);
    }
}