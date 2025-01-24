#include<bits/stdc++.h>
// #include<list>
using namespace std;

void display(list<int> &l){
    list<int> :: iterator it;
    for(it = l.begin(); it != l.end(); it++) cout<<*it<<" ";
    cout<<endl;
}

int main(){

//*********************************************************************************************************************//

    list<int> list1;  // List of length zero
    // list<int> list2(7);  // empty list of length 7

    list1.push_back(5); list1.push_back(7); list1.push_back(1); list1.push_back(9); list1.push_back(9); list1.push_back(12);
    display(list1);
    // list1.pop_back();
    // list1.pop_front();
    // list1.remove(9);  // removing both the nines 
    // list1.sort();  // ascending order
    // list1.reverse(); 
    // display(list1);

    // list<int> :: iterator iter;
    // iter = list1.begin(); 
    // cout<<*iter<<" ";
    // iter++;
    // cout<<*iter<<" ";
    // iter++;
    // cout<<*iter<<" ";
    // iter++;
    // cout<<*iter<<" ";
    // iter++;
    // cout<<*iter<<" ";

//*********************************************************************************************************************//

    list<int> list2(3);
    list<int> :: iterator iter;
    iter = list2.begin();
    *iter = 45;
    iter++;
    *iter = 6;
    iter++;
    *iter = 9;
    iter++;
    display(list2);
    cout<<"After merging list1 and list2: ";
    list1.merge(list2);
    display(list1); 

//*********************************************************************************************************************//


    return 0;
}