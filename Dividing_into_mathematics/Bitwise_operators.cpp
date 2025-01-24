#include<bits/stdc++.h>
using namespace std;

int binary_to_decimal(string s);
string decimal_to_binary(int num);
int count_setbits(int n);
int max_power_of_2(int n);
int minimum_bit_flip(int a, int b);

int main(){

//**********************************************************************************************************************//

    // // string s = "10101";
    // string s = "001101";
    // cout<<"Binary number: "<<s<<endl;
    // cout<<"Decimal number: "<<binary_to_decimal(s)<<endl;

//**********************************************************************************************************************//

    // int n = 18;
    // cout<<"Decimal number: "<<n<<endl;
    // cout<<"Binary number: "<<decimal_to_binary(n)<<endl;

//**********************************************************************************************************************//

    // int num = 103;
    // cout<<endl;

    // cout<<"Left shifting: "<<endl;
    // cout<<"x << 1: "<<(num<<1)<<" and x*2: "<<num*2<<endl;
    // cout<<"x << 2: "<<(num<<2)<<" and x*(2^2): "<<num*pow(2,2)<<endl;
    // cout<<"x << 3: "<<(num<<3)<<" and x*(2^3): "<<num*pow(2,3)<<endl;
    // cout<<endl;

    // cout<<"Right shifting: "<<endl;
    // cout<<"x >> 1: "<<(num>>1)<<" and x/2: "<<num/2<<endl;
    // cout<<"x >> 2: "<<(num>>2)<<" and x/(2^2): "<<int(num/pow(2,2))<<endl;   
    // cout<<"x >> 3: "<<(num>>3)<<" and x/(2^3): "<<int(num/pow(2,3))<<endl;
    // cout<<endl;

//**********************************************************************************************************************//

    // int n = 18;
    // cout<<"num of set bits in "<<n<<": "<<__builtin_popcount(n)<<endl;   // in built function 
    // // it means number of 1s in the binary of 18 
    // cout<<"num of set bits in "<<n<<": "<<count_setbits(n)<<endl;

//**********************************************************************************************************************//

    // int n,temp;
    // cout<<"Enter your number: ";
    // cin>>n;
    // while(n!=0){
    //     temp = n;
    //     n = n & (n-1);
    // }
    // cout<<"Last number which can be written as power of 2: "<<temp<<endl;
    // cout<<"number which can be written just greater as power of 2: "<<temp*2<<endl;

//**********************************************************************************************************************//

    // int n;
    // cout<<"Enter number: ";
    // cin>>n;
    // cout<<"Maximum number is power of 2: "<<max_power_of_2(n)<<endl;

//**********************************************************************************************************************//

    // flip all the bits
    // for example 10101010 --> 01010101

//**********************************************************************************************************************//

    // int a,b;
    // cout<<"Enter a: ";
    // cin>>a;
    // cout<<"Enter b: ";
    // cin>>b;
    // cout<<"Binary of a: "<<decimal_to_binary(a)<<endl;
    // cout<<"Binary of b: "<<decimal_to_binary(b)<<endl;
    // cout<<"No of flips required to convert a number from "<<a<<" to "<<b<<": "<<minimum_bit_flip(a,b)<<endl;

//**********************************************************************************************************************//

    // int arr[] = {4,1,4,3,2,3,5,1,2};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int res = 0;
    // for(int i=0; i<n; i++){
    //     res = res^arr[i];
    // }
    // cout<<"Sigle element which is not duplicate in the array: ";
    // cout<<res<<endl;

//**********************************************************************************************************************//

    

//**********************************************************************************************************************//




    return 0;
}

int binary_to_decimal(string s){
    int n = s.length();
    int sum = 0;
    for(int i=0; i<n; i++){
        char ch = s[n-1-i];
        int num = ch - '0';
        // sum += num*pow(2,i);
        sum += num*(1 << i);
    }
    return sum;
}

string decimal_to_binary(int num){
    string s = "";
    while(num > 0){
        if(num%2 == 0) s = '0' + s;
        else s = '1' + s;
        // num /= 2;
        num = num >> 1;   // both have same meaning 
    }
    return s;
}

int count_setbits(int n){
    int count = 0;
    while(n > 0){
        count++;
        n = (n & n-1);
    }
    return count;
}

int max_power_of_2(int n){
    n = n | (n >> 1);
    n = n | (n >> 2);
    n = n | (n >> 4);
    n = n | (n >> 8);
    n = n | (n >> 16);
    return (n+1) >> 1;   // divide by 2 
}

int minimum_bit_flip(int a, int b){
    return __builtin_popcount(a^b);
}