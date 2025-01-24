#include<bits/stdc++.h>
using namespace std;

vector<int> lexicoGraphicalOrder(int n); // Leetcode-386
void func(int i, int n);
vector<int> result;

int main(){

//**********************************************************************************************************//

    // first question (go to lecture and try to understand)

//**********************************************************************************************************//

    int n;
    cout<<"Enter number: ";  cin>>n;
    vector<int> v = lexicoGraphicalOrder(n);
    cout<<"Printing in lexicoGraphicalOrder: "<<endl;
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";  cout<<endl;

//**********************************************************************************************************//


    return 0;
}

vector<int> lexicoGraphicalOrder(int n){  // Leetcode-386
    result.clear();
    func(0,n);
    return result;
}
void func(int i, int n){
    if(i > n) return;  // don't do anything
    if(i <= n and i != 0) result.push_back(i);
    // if(i != 0) for(int j=0; j<=9; j++) func(10*i + j, n);
    // else for(int j=1; j<=9; j++) func(10*i + j, n);
    for(int j = (i==0) ? 1 : 0; j<=9; j++) func(10*i + j, n);  // can write it in a single line
}


