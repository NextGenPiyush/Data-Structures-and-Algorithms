#include<bits/stdc++.h>
using namespace std;

bool IsIsomorphic(string str1, string str2);  // leetcode-205

int main(){

//******************************************************************************************************************//

    // string str = "abbcdeffghh";
    // int n = str.length();       
    // int count = 0;
    // for(int i=0; i<n; i++){
    //     if(n == 1) break; // if n = 1; then we will break the loop and count = 0;
    //     if(n == 2 && str[0]!=str[1]){  // if n = 2 and both character are different then count = 1 and break the loop
    //         count++;
    //         break;
    //     }
    //     if(i == 0 && str[i] != str[i+1]) count++;
    //     else if(i == n-1 && str[i-1] != str[i]) count++;
    //     else if(str[i] != str[i+1] && str[i-1] != str[i]) count++;
    // }
    // cout<<"Number of times the neighbouring character are different from each other: "<<count<<endl;

//******************************************************************************************************************//

    // string str = "Piyush Goyal@@#@%";
    // cout<<str<<endl;
    // sort(str.begin(),str.end());  // sort according to ascii value 
    // cout<<str<<endl;

    // string str1,str2;       // Leetcode-242
    // cout<<"Enter string-1: ";
    // getline(cin,str1);
    // cout<<"Enter string-2: ";
    // getline(cin,str2);
    // sort(str1.begin(),str1.end());
    // sort(str2.begin(),str2.end());
    // cout<<endl<<"After sorting: "<<endl;
    // cout<<"String-1: "<<str1<<endl;
    // cout<<"String-2: "<<str2<<endl;  
    // if(str1 == str2) cout<<"These strings are anagrams "<<endl;  // anagram are just like permutation of same characters
    // else cout<<"These strings are not anagrams "<<endl;  
    

//******************************************************************************************************************//

    // string str = "aaabcbdggfhdsbdnsbaagfb";  // only lowercase alphabatic string 
    // int n = str.length();
    // int max = INT_MIN;
    // for(int i=0; i<n; i++){  // Time complexity: O(n^2) not a optimal method 
    //     int count = 0;       // will discuss the same question while learning hashmaps
    //     for(int j=i; j<n; j++) if(str[i] == str[j]) count++;
    //     if(max < count) max = count;
    // }
    // for(int i=0; i<n; i++){
    //     int count = 0;
    //     for(int j=i; j<n; j++) if(str[i] == str[j]) count++;
    //     if(max == count) cout<<str[i]<<" "<<max<<endl;
    // }

//******************************************************************************************************************//

    // string str;
    // getline(cin,str);  // all lower case character 
    // int n = str.length();
    // int max = INT_MIN;  // will discuss the same question while learning hashmaps
    // int index = -1;
    // vector<int> v(26);  // automatically initialized to 0
    // for(int i=0; i<n; i++) v[int(str[i]) - 97]++;
    // for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    // for(int i=0; i<v.size(); i++){
    //     if(max < v[i]){
    //         max = v[i];
    //         index = i;
    //     }
    // }
    // cout<<endl<<char(index+97)<<" is repeating "<<max<<" times"<<endl;

//******************************************************************************************************************//

    // string str = "Raghav is a maths teacher. He is a DSA mentor as well.";
    // stringstream ss(str);     // stringstream variable_name(string)
    // vector<string> v; 
    // string temp;
    // int max_count = INT_MIN;
    // while(ss>>temp) v.push_back(temp);
    // sort(v.begin(),v.end());
    // for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    // for(int i=1; i<v.size(); i++){
    //     int count = 1;
    //     if(v[i] == v[i-1]) count++;
    //     max_count = max(max_count,count);
    // }
    // cout<<endl;
    // for(int i=1; i<v.size(); i++){
    //     int count = 1;
    //     if(v[i] == v[i-1]) count++;
    //     if(count == max_count) cout<<v[i]<<" "<<max_count<<endl;
    // }
    
//******************************************************************************************************************//

    // string str1 = "123456";
    // string str2 = "123456789878888887";
    // int x = stoi(str1);     // stoi --> string to integer
    // cout<<x<<endl;
    // long long y = stoll(str2);   // stoll --> string to long long
    // cout<<y<<endl;

    // int max_num = INT_MIN;
    // vector<string> v = {"0123","0023","456","00182","940","2901"};
    // for(int i=0; i<v.size(); i++) max_num = max(max_num,stoi(v[i]));    // make sure that leading zeros will be ignored
    // cout<<"Maximum number in the vector of string: "<<max_num<<endl;

//******************************************************************************************************************//

    // vector<string> v = {"flight","flower","flow"};  // already present in lexographical order 
    // int n = v.size();    // Leetcode-14
    // string first = v[0];
    // string second = v[n-1];
    // string s = "";
    // for(int i=0; i<min(first.length(),second.length()); i++){
    //     if(first[i] == second[i]) s += first[i];
    //     else break;
    // }
    // cout<<s<<endl;

//******************************************************************************************************************//

    // string str1,str2;
    // getline(cin,str1);
    // getline(cin,str2);
    // if(IsIsomorphic(str1,str2)) cout<<"Strings are Isomorphic "<<endl;
    // else cout<<"Strings are not Isomorphic "<<endl;

//******************************************************************************************************************//

    string s1 = "abzaef";  
    string s2 = "abcaef";  
    cout<<s1.compare(s2)<<endl;  // it will print 1 
    // case-1: s1 == s2 then it will print zero (0)
    // case-2: s1 > s2 then it will print positive number (1)
    // case-1: s1 < s2 then it will print negative number (-1)

//******************************************************************************************************************//

    return 0;
}

bool IsIsomorphic(string str1, string str2){   // leetcode-205
    if(str1.length() != str2.length()) return false;
    vector<int> v(52,1000);  // we have assumed 52 characters (26 lowercase + 26 uppercase)
    for(int i=0; i<str1.length(); i++){  // cheking relation from string1 to string2
        int idx = int(str1[i]);
        if(v[idx] == 1000) v[idx] = str1[i] - str2[i];
        else if(v[idx] != (str1[i]-str2[i])) return false;
    }
    for(int i=0; i<v.size(); i++) v[i] = 1000;
    for(int i=0; i<str1.size(); i++){  // cheking relation from string2 to string1
        int idx = int(str2[i]);
        if(v[idx] == 1000) v[idx] = str2[i] - str1[i];
        else if(v[idx] != (str2[i]-str1[i])) return false;
    }
    return true;
}
