#include<bits/stdc++.h>
using namespace std;
int main(){

//*******************************************************************************************************************//

    // char str[10] = {'a','b','c','d','e'};   // string is a character array
    // cout<<str<<endl;  // '\0' is automatically placed in the end 

    // char str2[5] = "abcd";  // we cannot give 5 characters in the string if size is 5 
    // char c = '\0';   // null character
    // cout<<c<<endl;   // print empty space (print nothing)
    // cout<<(int)c<<endl;  // ascii value is zero
    // cout<<str[5]<<endl;  // print nothing, it means string end with null character 
    // cout<<(int)str[5]<<endl;

//*******************************************************************************************************************//

    // char str3[] = {'a','b','c','d','e','f','g','\0'}; // necessary to put '\0' in the end when size is not mentioned
    // for(int i=0; str3[i]!='\0'; i++) cout<<str3[i]<<" ";   
    // cout<<endl<<str3<<endl;

    // char str4[] = {'a','b','c','d','e','f','g','\0','i','j','k','l'};   
    // for(int i=0; str4[i]!='\0'; i++) cout<<str4[i]<<" ";  // it will print upto null character only 
    // cout<<str4<<endl;

//*******************************************************************************************************************//

    // string str = "Piyush Goyal";  // string is pre defined data type in the c++ language 
    // cout<<str<<endl;  
    // cout<<str.size()<<endl;  // make sure that the actual size of string is 13 as '\0' is also included in the end
    // cout<<(int)str[12]<<endl;  
    
    // string s1,s2,s3;
    // // cin>>s1;   // it will not consider space and character after the space 
    // // cout<<s1<<endl;
    // cin>>s1>>s2;
    // cout<<s1<<" "<<s2<<endl;
    // cin.ignore(); // Ignore the newline character left in the buffer
    // getline(cin,s3);  // it will consider spacing between the two characters 
    // cout<<s3<<endl;

//*******************************************************************************************************************//

    // string str;
    // getline(cin,str);
    // int count = 0;
    // for(int i=0; str[i]!='\0'; i++) if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u') count++;
    // cout<<"Number of vovels in the string: "<<count<<endl;
    // cout<<str<<endl;
    // str[0] = 'O';
    // cout<<str<<endl;

    // for(int i=0; str[i]!='\0'; i++) if(i%2 == 0) str[i] = 'a';   // updating even index to character 'a'
    // cout<<str<<endl;

//*******************************************************************************************************************//

    // string str = "My name is Piyush Goyal";
    // // int size = str.length();  // it will not include null character at the end of the string
    // int size = str.size();  // we can use both length() or size() function
    // cout<<str<<endl;
    // cout<<"Size of string is: "<<size<<endl;
    // str.push_back('o'); 
    // // str.push_back("orange");  // we can only pushback character not string
    // str.append("orange"); // or we can also write (str + "orange") 
    // cout<<str<<endl;
    // str.pop_back();
    // str.pop_back();
    // cout<<str<<endl;
    
//*******************************************************************************************************************//

    // string str1 = "abc";
    // string str2 = "def";
    // cout<<str1+str2<<endl;
    // str2 = str2 + "   Piyush";
    // cout<<str1+" "+str2<<endl;
    // string str3 = str1 + 'a';   // we can also add character in the string using '+' operator 
    // cout<<str3<<endl;

//*******************************************************************************************************************//

    // string str = "Piyush Goyal";
    // int n = str.length();
    // cout<<str<<endl;

    // reverse(str.begin(),str.end());
    // cout<<str<<endl;

    // reverse(str.begin(),str.end()-1);
    // cout<<str<<endl;

    // reverse(str.begin()+2,str.begin()+5);  // we want to revrese string from index 2 to 4
    // cout<<str<<endl;

    // reverse(str.begin(),str.begin()+(n/2));  // revresing half of the string
    // cout<<str<<endl;

//*******************************************************************************************************************//

    // string str = "Piyush Goyal enc@##@";   
    // int n = str.length();
    // int size = 4;
    // cout<<str<<endl;
    // for(int i=0; i<n; i++) cout<<str<<"  "<<str.substr(i)<<endl;   
    // cout<<endl;  // substr(index,size) --> start from index upto the size in the string
    // for(int i=0; i<n; i++) cout<<str<<" "<<str.substr(i,size)<<endl;
    // cout<<endl<<"second half string: "<<endl;
    // cout<<str.substr(n/2)<<endl;

//*******************************************************************************************************************//

    // int x = 12345;
    // // string str = string(x); // error
    // // string str = (string)x; // error  // type casting is not possible

    // string str = to_string(x);  // converting number to the string
    // cout<<str<<endl;   // helpful in finding length
    // cout<<"Length: "<<str.length()<<endl;

    // // int length = (x == 0) ? 1 : int(log10(x) + 1);  // another way to find length 
    // // cout<<"Length of the number: "<<length<<endl;

//*******************************************************************************************************************//
    
    return 0;
}