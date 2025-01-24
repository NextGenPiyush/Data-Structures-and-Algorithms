#include<bits/stdc++.h>
// #include<unordered_set>  include this library for using sets in the code
// there is another headerfile which is #include<set>
// #include<unordered_map>  include this library for using maps in the code
using namespace std;

int count_distinct_integer(vector<int> &nums); // Leetcode-2442
int reverse(int val);

int maximum_string_pairs(vector<string> &arr);  // Leetcode-2744

bool is_anagram(string s1, string s2); // Leetcode-242

vector<int> twoSum(vector<int> &nums, int target); // Leetcode-1

bool uniqueOccurence(vector<int> &arr);  // Leetcode-1207

int main(){

//********************************************************************************************************************//

    // unordered_set<int> s;  // unordered set
    // s.insert(1);  s.insert(2);  s.insert(3);  s.insert(4);  s.insert(5);  s.insert(6);  s.insert(7);  // random order
    // // insertion time complexity: O(1)
    // // searching time complexity: O(1)
    // // deletion time complexity: O(1) 
    // for(int ele: s) cout<<ele<<" ";  cout<<endl;  // ptinting in random order

    // s.insert(1);  s.insert(2);  s.insert(3);  s.insert(4);  s.insert(5);  s.insert(6);  s.insert(7); // inserting same val
    // for(int ele: s) cout<<ele<<" ";  cout<<endl;  // only stored the unique elements hence will print the same

    // s.erase(2);  s.erase(10);  s.erase(5);  s.erase(20); // not give error if we erase the element ehich is not present
    // for(int ele: s) cout<<ele<<" ";  cout<<endl;  // only those elements will be erased which is present in the set 

    // unordered_set<int>::iterator itr;  // we can also print like this
    // for(itr = s.begin(); itr != s.end(); itr++) cout<<(*itr)<<" ";  cout<<endl; 

    // int target = 6;
    // if(s.find(target) != s.end()) cout<<"Target exist"<<endl;   
    // else cout<<"Target does not exist"<<endl;

    // cout<<"Size of the set: "<<s.size()<<endl;
    // // discuss more about s.end() and s.begin()

//********************************************************************************************************************//

    // Count Number of Distinct Integers After Reverse Operations (Leetcode-2442)

//********************************************************************************************************************//

    // Find Maximum Number of String Pairs (Leetcode-2744)

//********************************************************************************************************************//

    pair<string,char> p;
    p.first = "Piyush";  // must be string
    p.second = 'M';   // must be character 
    cout<<"Printing pair: "<<p.first<<" "<<p.second<<endl;

    unordered_map<string,int> m;     // map<key,value>
    pair<string,int> p1,p2,p3;
    // m.insert("Piyush",100); we cant insert like this 
    p1.first = "Piyush"; p1.second = 10; m.insert(p1);   // we have to insert separate pairs into map 
    p2.first = "Raghav"; p2.second = 6; m.insert(p2); 
    p3.first = "Harshit"; p3.second = 8; m.insert(p3);

    cout<<"Printing the map: "<<endl;
    for(pair<string,int> p: m) cout<<p.first<<" "<<p.second<<" "<<endl;

    m["Ravi"] = 20;  // we can also add new data like this
    m["Piyush"] = 30;  // we can also access and change 
    // cout<<m["Piyush"]<<endl;  // it will print 30 so can print the data like this 
    for(auto p: m) cout<<p.first<<" "<<p.second<<" "<<endl; // (auto) will detect automatically which data type is it

    cout<<"size of the map will be: "<<m.size()<<endl;
    m.erase("Piyush");  m.erase("Lokesh");  // only data of piyush will be deleted as lokesh was not present in the map
    cout<<"size after deleting: "<<m.size()<<endl;
    // try to explore about m.count() function
    // we use m.find() in the same way as we have done in sets if(m.find(target) != m.end()) target is present
    // here target will be the key, we find element as key (first part of pair) 

//********************************************************************************************************************//

    // Valid anagram? (Leetcode-242)

//********************************************************************************************************************//

    // two sum (Leetcode-1)

//********************************************************************************************************************//

    // Unique number of Occurences (Leetcode-1207)

//********************************************************************************************************************//



    return 0;
}

int count_distinct_integer(vector<int> &nums){   // Leetcode-2448
    int n = nums.size();
    unordered_set<int> s;

    // for(int i=0; i<n; i++) nums.push_back(reverse(nums[i]));
    // for(int i=0; i<nums.size(); i++) s.insert(nums[i]);  // will not insert the same value 

    for(int i=0; i<n; i++){      // in the question we have given task to pushback reverse integer into vector but
        s.insert(nums[i]);          // we can directly insert actual and reverse number at a same time in the set
        s.insert(reverse(nums[i]));
    }
    return s.size();  
}
int reverse(int val){
    int r=0;
    while(val>0){
        r *= 10;
        r += (val%10);
        val /= 10;
    }
    return r;
}

int maximum_string_pairs(vector<string> &arr){  // Leetcode-2744
    int n = arr.size();
    int count = 0;

    // for(int i=0; i<n-1; i++){    // brute force algorithem, time complexity: O(n^2)
    //     string rev = arr[i];
    //     reverse(rev.begin(),rev.end());
    //     for(int j=i+1; j<n; j++) if(rev == arr[i]) count++;
    // }

    // unordered_set<string> s;       // using unordered set data structure, time complexity: O(n)
    // for(int i=0; i<n; i++) s.insert(arr[i]);  // inserting all the elements in the unordered set
    // for(int i=0; i<n; i++){   // Traversing in the array O(n)
    //     string rev = arr[i];
    //     reverse(rev.begin(),rev.end());
    //     if(rev == arr[i]) continue;  // it means both the characters of the string are same ex "zz","aa" (Palindrome)
    //     else if(s.find(rev) != s.end()){  // only done when the string is not palindrome and finding will be done in O(1)
    //         count++;
    //         s.erase(arr[i]);   // erase the element after traversing the element from the set 
    //     }
    // }

    unordered_set<string> s;     // most optimized method (single traversal) 
    for(int i=0; i<n; i++){      // time complexity: O(n) traversing in the array 
        string rev = arr[i];
        reverse(rev.begin(),rev.end());       
        if(s.find(rev) != s.end()) count++; // no need to check (rev == arr[i]) condition as all the strings must be unique
        // we can also remove the elemenet from the set but no need to do that 
        else s.insert(arr[i]);
    }

    return count;
}

bool is_anagram(string s1, string s2){  // Leetcode-242
    if(s1.length() != s2.length()) return false;

    // sort(s1.begin(),s1.end());    
    // sort(s2.begin(),s2.end());  
    // if(s1 == s2) return true;    // another approach: we can make array of 26 size (no of alphabats) and make it into a 
    // else return false;      // frequency array and then check isf both the frequencies in the arrays are same or not

    // unordered_map<char,int> m1,m2;     // alternate approach using maps 
    // for(int i=0; i<s1.length(); i++){
    //     m1[s1[i]]++;  // it will find key and increase the value by one if(m1.find(s1[i]) != m1.end()) m1[s1[i]]++;
    //     m2[s2[i]]++;
    // }
    // for(auto x: m1){
    //     char ch1 = x.first;
    //     int freq1 = x.second;
    //     if(m2.find(ch1) != m2.end()){
    //         int freq2 = m2[ch1];
    //         if(freq1 != freq2) return false;
    //     }
    //     else return false; // if any character is present in the map-1 and not present in map-2 then return false
    // }
    // return true;

    unordered_map<char,int> map1;                        // optimized approach  
    for(int i=0; i<s1.length(); i++) map1[s1[i]]++;   // time complexity: O(n)
    for(int i=0; i<s1.length(); i++){
        char ch = s2[i];
        if(map1.find(ch) != map1.end()){
            map1[ch]--;
            if(map1[ch] == 0) map1.erase(ch);  // if any character is counted upto its max frequency the remove element 
        }                                     // from the map as soon as its value become zero
        else return false;  // if any character in s2 is not present in the map then return false
    }
    if(map1.size()>0) return false;  // if all the keys in the end are not deleted it means there are some extra charaters  
    return true;                      // in the s1 

}

vector<int> twoSum(vector<int> &nums, int target){     // Leetcode-1
    vector<int> ans;
    int n = nums.size();

    // for(int i=0; i<n-1; i++){        // Brute force algorithem
    //     for(int j=i+1; j<n; j++){    // Time complexity: O(n^2)
    //         if(nums[i] + nums[j] == target){
    //             ans.push_back(i);  ans.push_back(j); 
    //             return ans;
    //         }
    //     }
    // }
    
    unordered_map<int,int> m;  // map<key(element),value(index)>
    for(int i=0; i<n; i++){        // Time complexity: O(n)
        int rem = target - nums[i];     
        if(m.find(rem) != m.end()){   
            ans.push_back(m[rem]);
            ans.push_back(i);
        }
        else m[nums[i]] = i;
    }

    return ans;
}

bool uniqueOccurence(vector<int> &arr){   // Leetcode-1207
    int n = arr.size();
    unordered_map<int,int> map;
    unordered_set<int> set;
    for(int i=0; i<n; i++) map[arr[i]]++;  // Time complexity: O(n)
    for(auto ele: map){
        int freq = ele.second;
        if(set.find(freq) != set.end()) return false;  // because we have got the same frequency
        else set.insert(freq);
    }
    return true;  // if all the frequecies are inserted it means all are unique frequency 
}
 
