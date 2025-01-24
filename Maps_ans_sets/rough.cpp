#include<bits/stdc++.h>
using namespace std;

#include<set>
#include<unordered_set>

#include<unordered_map>
#include<map>


int main(){

//***********************************************************************************************************************//

    // unordered_set<int> s;
    // s.insert(1); s.insert(9); s.insert(8); s.insert(2); s.insert(3); s.insert(4); s.insert(5); s.insert(6); s.insert(7);
    // for(int ele : s) cout<<ele<<" ";  cout<<endl;
    // cout<<s.count(1)<<endl;

    // // The find() function returns an iterator to end() if a key is not there in the set, otherwise, an iterator 
    // // to the key position is returned
    // if(s.find(9) != s.end()){
    //     unordered_set<int>::iterator itr = s.find(9);
    //     cout<<(*itr)<<endl;
    // }
    // s.clear();  // remove all elements from the unordered set and empties it 
    // if(s.empty()) cout<<"Set is now empty"<<endl;  // confirmed that set is empty 

    // // there is a swap(set_1,set_2) function also which swaps the elements of two unordered_set

//***********************************************************************************************************************//

    // set<char> ch;  // automatically store element in increasing order
    // ch.insert('z');  ch.insert('a');  ch.insert('y'); ch.insert('b'); ch.insert('a');
    // for(char c : ch) cout<<c<<" ";  cout<<endl;  

    // set<char,greater<char>> ch2;  // automatically store element in decreasing order
    // ch2.insert('z');  ch2.insert('a');  ch2.insert('y'); ch2.insert('b'); ch2.insert('a');
    // for(char c : ch2) cout<<c<<" ";  cout<<endl;  

    // // insertion: O(logn)
    // // deletion: O(logn)

    // set<int> s1;
    // s1.insert(10); s1.insert(100); s1.insert(30); s1.insert(50); s1.insert(120); s1.insert(20); s1.insert(6); s1.insert(7);
    // set<int>::iterator itr;
    // for(itr = s1.begin(); itr != s1.end(); itr++) cout<<(*itr)<<" ";  cout<<endl;
    // set<int,greater<int>> s2(s1.begin(),s1.end());
    // set<int,greater<int>>::iterator itr2;
    // for(itr2 = s2.begin(); itr2 != s2.end(); itr2++) cout<<(*itr2)<<" ";  cout<<endl;
    // s2.erase(s2.begin(), s2.find(30)); // remove element strictly greater than 30
    // for(itr2 = s2.begin(); itr2 != s2.end(); itr2++) cout<<(*itr2)<<" ";  cout<<endl;

//***********************************************************************************************************************//

    // // there is another data structure named multiset<data_type> or multiset<data_type,greater<data_type>>
    // multiset<int,greater<int>> m;  // we can store single element multiple times in multiset data structure
    // m.insert(40); m.insert(30); m.insert(60); m.insert(50); m.insert(50); m.insert(10); m.insert(10); m.insert(10);
    // multiset<int,greater<int>>::iterator itr;
    // for (itr = m.begin(); itr != m.end(); ++itr) cout<<*itr<<" ";   cout<<endl;

    // multiset<int> m2(m.begin(), m.end());
    // multiset<int>::iterator itr2;
    // for (itr2 = m2.begin(); itr2 != m2.end(); ++itr2) cout <<*itr2<<" ";  cout<<endl;

    // cout<<"m2.count(10): "<<m2.count(10)<<endl;
    // m2.erase(m2.find(10));
    // cout<<"m2.count(10): "<<m2.count(10)<<endl;
    // m2.erase(10);
    // cout<<"m2.count(10): "<<m2.count(10)<<endl;

//***********************************************************************************************************************//

    // unordered_map<string,double> umap = {{"One", 1},{"Two", 2},{"Three", 3}};  // we can also do insertion like this
    // umap.insert(make_pair("e", 2.718));
    // umap.insert({"four",4});
    // unordered_map<string, double>::iterator itr; // printing will be done in random order as we have used unordered_map
    // for (itr = umap.begin(); itr != umap.end(); itr++) cout<<itr->first<<"  "<<itr->second<<endl;

//***********************************************************************************************************************//

    // map<int,int,greater<int>> m1; // automatically store pair<int,int> in decreasing order according to first int(key)
    // m1[1] = 40;   m1[2] = 30;   m1[3] = 60;   m1[4] = 20;   m1[5] = 50;   m1[6] = 50;   m1[7] = 10;
    // map<int,int,greater<int>>::iterator itr;
    // for(itr = m1.begin(); itr != m1.end(); ++itr) cout<<"("<<itr->first<<" "<<itr->second<<")  ";   cout<<endl;

    // map<int,int> m2(m1.begin(), m1.end());
    // map<int,int>::iterator itr2;
    // for (itr2 = m2.begin(); itr2 != m2.end(); ++itr2) cout<<"("<<itr2->first<<" "<<itr2->second<<")  ";   cout<<endl;
    // m2.erase(m2.begin(), m2.find(3));
    // for (itr2 = m2.begin(); itr2 != m2.end(); ++itr2) cout<<"("<<itr2->first<<" "<<itr2->second<<")  ";   cout<<endl;

//***********************************************************************************************************************//

    // read about hashing, There are very few chance that it is asked in the interview

//***********************************************************************************************************************//

    return 0;
}