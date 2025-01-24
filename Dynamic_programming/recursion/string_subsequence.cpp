#include<bits/stdc++.h>
using namespace std;

void print_all_subsequence_1(string &str, int idx, string &sub){ // this is more space optimized 
    if(idx == str.length()){                                   // as it is passed by refference  
        cout<<"{"<<sub<<"}"<<endl;
        return;
    }
    // sub.push_back(str[idx]);  
    print_all_subsequence_1(str,idx+1,sub+=str[idx]); // we can also use push_back() function before calling 
    sub.pop_back();  // backtraking         
    print_all_subsequence_1(str,idx+1,sub); 
}

void print_all_subsequence_2(string &str, int idx, string sub){  // this is space consuming
    if(idx == str.length()){             // as every time a new string is created and not passed by refference
        cout<<"{"<<sub<<"}"<<endl;
        return;
    }
    print_all_subsequence_2(str,idx+1,sub+str[idx]); // similarly we can print the subsequence of the array 
    print_all_subsequence_2(str,idx+1,sub);
}

// Time complexity: O(2^n) 
// Space complexity: O(n) whene n is the length of the string given

int main(){

    string str;
    cin>>str;
    cout<<"Printing all the subsequence of the given string"<<endl;
    string sub = "";
    print_all_subsequence_1(str,0,sub);
    // print_all_subsequence_2(str,0,sub);



    return 0;
}