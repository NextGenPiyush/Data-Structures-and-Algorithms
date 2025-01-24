#include<bits/stdc++.h>
using namespace std;

void print_all_subsequence(string &s){
    int n = s.length();
    for(int num=0; num<pow(2,n); num++){
        string str = "";
        for(int j=0; j<n; j++) if(num&(1<<j)) str+=s[j];  // similarly we can print subsequence of the array 
        cout<<"{"<<str<<"}"<<endl;
    }
}

int main(){

    string n;
    cin>>n;
    cout<<"Printing all the subsequence of the given string"<<endl;
    print_all_subsequence(n);


    return 0;
}