#include<bits/stdc++.h>
// #include<map>
using namespace std;

int main(){

//*********************************************************************************************************************//    

    map<string,int> marks;
    marks["Piyush"] = 98;
    marks["Haary"] = 87;
    marks["Rohan"] = 91;
    marks.insert({{"Harsh",88},{"Kapil",85}});
    map<string,int> :: iterator iter;
    for(iter = marks.begin(); iter != marks.end(); iter++) cout<<(*iter).first<<" "<<(*iter).second<<endl;

    cout<<"the size is: "<<marks.size()<<endl;
    cout<<"the max size is: "<<marks.max_size()<<endl;
    cout<<"the empty return value is: "<<marks.empty()<<endl;  // return zero if not empty 

//*********************************************************************************************************************//    

    return 0;
}