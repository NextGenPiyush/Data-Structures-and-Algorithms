#include<bits/stdc++.h>
using namespace std;

void print_vector(vector<int> v);

vector<int> running_sum(vector<int> v);      // Leetcode-1480
vector<int> running_product(vector<int> v);           
vector<int> sufix_sum(vector<int> v);           
vector<int> sufix_product(vector<int> v);

int sum_between_idx(vector<int> v, int a, int b);
void partition_check(vector<int> v);

vector<int> product_except_self_1(vector<int> &v);   // Leetcode-238
vector<int> product_except_self_2(vector<int> &v);
vector<int> product_except_self_3(vector<int> &v);   // without using division

void penalty(string s);  // Leetcode-2483

int maxSatisfaction(vector<int> &satisfaction);

vector<int> AnswerQueries(vector<int> &num, vector<int> &queries);

int main(){

//********************************************************************************************************//

    // vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    // print_vector(v);
    // print_vector(running_sum(v));
    // print_vector(running_product(v));
    // print_vector(sufix_sum(v));
    // print_vector(sufix_product(v));

//********************************************************************************************************//

    // vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    // print_vector(v);
    // int a,b;
    // cout<<"Enter starting index: ";
    // cin>>a;
    // cout<<"Enter ending index: ";
    // cin>>b;
    // cout<<"Sum from index "<<a<<" to "<<b<<": "<<sum_between_idx(v,a,b)<<endl;

//********************************************************************************************************//

    // vector<int> v = {1,2,3,4,5,7,8};
    // print_vector(v);
    // partition_check(v);

//********************************************************************************************************//

    // vector<int> v = {1,2,3,4,5,6,7,8,9,10};   // Leetcode-238
    // // vector<int> v = {1,2,3,4,5,6,7,0,9,10};   
    // // vector<int> v = {1,0,3,4,0,6,7,0,9,10};  
    // print_vector(v);
    // // print_vector(product_except_self_1(v));
    // // print_vector(product_except_self_2(v));
    // print_vector(product_except_self_3(v));      // without using division

//********************************************************************************************************//

    string s = "YYNY";  // Leetcode-2483
    cout<<s<<endl;
    penalty(s);

//********************************************************************************************************//

    // vector<int> v1 = {2,3,4,5};
    // vector<int> v2 = {3,2,5,15};
    // print_vector(AnswerQueries(v1,v2));

//********************************************************************************************************//


    return 0;
}

void print_vector(vector<int> v){   
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";  cout<<endl;
}

vector<int> running_sum(vector<int> v){  // array of sum of all the previous element upto each particular index
    int n = v.size();
    vector<int> ans(n);    // we can also do it without making new vector as it is taking more space 
    ans[0] = v[0];
    for(int i=1; i<n; i++) ans[i] = v[i] + ans[i-1];    // here v[i] = v[i] + v[i-1] should be writen 
    return ans;   // here v should be return
}

vector<int> running_product(vector<int> v){  
    int n = v.size();
    vector<int> ans(n);   
    ans[0] = v[0];
    for(int i=1; i<n; i++) ans[i] = v[i] * ans[i-1];    // here v[i] = v[i] + v[i-1] should be writen 
    return ans;   // here v should be return
}

vector<int> sufix_sum(vector<int> v){
    int n = v.size();
    for(int i=n-2; i>=0; i--) v[i] = v[i] + v[i+1];
    return v;
}   

vector<int> sufix_product(vector<int> v){
    int n = v.size();
    for(int i=n-2; i>=0; i--) v[i] = v[i] * v[i+1];
    return v;
}            

int sum_between_idx(vector<int> v, int a, int b){
    vector<int> ans = running_sum(v);
    if(a == 0) return ans[b];   
    else return ans[b]-ans[a-1];
}

void partition_check(vector<int> v){
    vector<int> ans = running_sum(v);      // Time complexity: O(n)
    int temp;
    for(int i=0; i<ans.size(); i++){
        if(2*ans[i] == ans[ans.size()-1]){ // sum from 0 -> (i)th index == (i+1)th index -> (ans.size()-1)th index
            cout<<"Yes, it can be partitions after "<<i<<" index"<<endl;
            temp = i;   // ans[x] == ans[ans.size()-1]-ans[x] --> 2ans[x] == ans[ans.size()-1]
            break;  // we can also apply the condition of [sum_between_idx(ans,0,i) == sum_between_idx(ans,i+1,ans.size()-1)]
        }
    }
    vector<int> v1, v2;
    for(int i=0; i<v.size(); i++){
        if(i<=temp) v1.push_back(v[i]);   // separating original vector into two vectors 
        else v2.push_back(v[i]);
    }
    print_vector(v1);
    print_vector(v2);
}

vector<int> product_except_self_1(vector<int> &v){    // Leetcode-238
    int product = 1, idx = -1, zeros = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i] == 0){
            zeros++;
            idx = i;
            continue;
        } 
        product *= v[i];   // product variable contain the product of all the values except zero
    }
    for(int i=0; i<v.size(); i++){
        if(zeros>1){
            v[i] = 0;   // make all the elements to zero af the number of zeros are greater than one 
            continue;
        }
        if(idx == -1) v[i] = product/v[i];  // it means there is no zero in the oroginal array
        else{
            if(i == idx) v[i] = product;  // it means there is one zero in the original array at idx index
            else v[i] = 0;  // if there is one zero than execpt that index all ans will be zero 
        }
    }
    return v;
}

vector<int> product_except_self_2(vector<int> &v){  
    int n = v.size();
    int product_1 = 1;  // product of all the terms including zeros
    int product_2 = 1; // product of all the terms excluding all the eros
    int noz = 0;    
    for(int i=0; i<n; i++){
        if(v[i] == 0) noz++;
        product_1 *= v[i];
        if(v[i] != 0) product_2 *= v[i];
    }
    if(noz > 1) product_2 = 0;  // if noz>1 then all the element will become zero
    for(int i=0; i<n; i++){
        if(v[i] == 0) v[i] = product_2;
        else v[i] = product_1/v[i];
    }
    return v;
}

vector<int> product_except_self_3(vector<int> &v){     // without using division
    int n = v.size();
    vector<int> pre(n),suf(n);
    pre[0] = 1;
    // suf[n-1] = 1;         // here we are using an extra array
    int product_1 = 1;
    int product_2 = 1;
    for(int i=1; i<n; i++){
        product_1 = product_1 * v[i-1];
        pre[i] = product_1;
    }
    for(int i=n-2; i>=0; i--){
        product_2 = product_2 * v[i+1];  
        // suf[i] = product_2;  // here we are using an extra array named suf[]
        pre[i] *= product_2;
    }
    // for(int i=0; i<n; i++){
    //     v[i] = pre[i]*suf[i];   or pre[i] = pre[i]*suf[i] and return pre
    // }
    // return v;
    return pre;    // we have done it by using only one extra array 
}   

void penalty(string s){   // Leetcode-2483
    int n = s.length();
    int count_n = 0, count_y = 0;
    int min_ele = INT_MAX;
    vector<int> pre(n+1);     // prefix sum 
    vector<int> suf(n+1);     // sufix sum 

    pre[0] = 0;
    for(int i=1; i<=n; i++){
        if(s[i-1] == 'N') count_n++;
        pre[i] = count_n;
    }
    suf[n] = 0;
    for(int i=n-1; i>=0; i--){
        if(s[i] == 'Y') count_y++;
        suf[i] = count_y;
    }
    for(int i=0; i<=n; i++) pre[i] += suf[i];
    for(int i=0; i<=n; i++) min_ele = min(min_ele,pre[i]);
    for(int i=0; i<=n; i++){
        if(pre[i] == min_ele){
            cout<<"For minimum penalty shop must be closed at "<<i<<"th hour"<<endl;
            return;
        }
    }
}

int maxSatisfaction(vector<int> &satisfaction){
    int n = satisfaction.size();
    sort(satisfaction.begin(),satisfaction.end());
    int suf[n];
    suf[n-1] = satisfaction[n-1];
    for(int i=n-2; i>=0; i--) suf[i] = suf[i+1] + satisfaction[i];
    int idx = -1;
    for(int i=0; i<n; i++){
        if(suf[i]>=0){
            idx = i;
            break;
        }
    }
    if(idx == -1) return 0;
    int x = 1;
    int maxSum = 0;
    for(int i=idx; i<n; i++){
        maxSum += satisfaction[i];
        x++;
    }
    return maxSum;
}

vector<int> AnswerQueries(vector<int> &num, vector<int> &queries){
    int n = num.size();
    int m = queries.size();
    vector<int> ans(m);
    sort(num.begin(),num.end());
    for(int i=1; i<m; i++) num[i] += num[i-1];  // making num a prefix sum of num
    for(int i=0; i<m; i++){
        int length = 0;

        // for(int j=0; j<n; j++){               // this is a linear search, but we can also use binary search
        //     if(num[j] > queries[i]) break;
        //     length++;
        // }

        int low = 0;        // binary search 
        int high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(num[mid]>queries[i]) high = mid-1;
            else{
                low = mid+1;
                length = mid+1;
            }    
        }

        ans[i] = length;
    }
    return ans;
}