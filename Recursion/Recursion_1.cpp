#include<bits/stdc++.h>
using namespace std;

void print(int n);
int factorial(int n);
void print_n_1(int n);
void print_n_1(int n, int i);
void print_1_n(int n);
void print_1_n(int i, int n);
int sum_1_n(int n);
void sum_1_n(int sum, int n);
int power(int a, int b);
int power_recursion(int a, int b);

int main(){

//******************************************************************************************************************//

    // int n;
    // cout<<"How many times you want to print: ";
    // cin>>n;
    // print(n);

//******************************************************************************************************************//

    // int n;
    // cout<<"Enter number: ";
    // cin>>n;

    // if(n < 0){
    //     cout<<"Factorial of negative number is not possible "<<endl;
    // }
    // // else{
    // //     int a = 1;
    // //     for(int i=1; i<=n; i++){
    // //         a *= i;
    // //     }
    // //     cout<<"Factorial of "<<n<<" is: "<<a<<endl; 
    // // } 

    // cout<<"Factorial of "<<n<<" is: "<<factorial(n)<<endl; 

//******************************************************************************************************************//

    // int n;
    // cout<<"Enter number: ";
    // cin>>n;
    // cout<<"Printing number from "<<n<<" to 1: "<<endl;
    // // print_n_1(n);
    // print_n_1(n,1);

//******************************************************************************************************************//

    // int n;
    // cout<<"Enter number: ";
    // cin>>n;
    // cout<<"Printing number from 1 to "<<n<<": "<<endl;
    // // print_1_n(n);
    // print_1_n(1,n);

//******************************************************************************************************************//

    // int n;
    // cout<<"Enter number: ";
    // cin>>n;
    // cout<<"Sum of number from 1 to "<<n<<": "<<sum_1_n(n)<<endl;
    // sum_1_n(0,n);    // we can overload function with same name and different parameter and return type

//******************************************************************************************************************//

    // int a,b;
    // cout<<"Enter value of a: ";
    // cin>>a;
    // cout<<"Enter value of b: ";
    // cin>>b;
    // // cout<<"a raise to the power b (a^b): "<<power(a,b);   // without using recursion
    // cout<<"a raise to the power b (a^b): "<<power_recursion(a,b);

//******************************************************************************************************************//

    return 0;
}

void print(int n){
    if(n==0) return;
    cout<<"Good Morning: "<<n<<endl;
    print(n-1);
}

int factorial(int n){
    if(n==0 || n==1) return 1;
    int ans = n * factorial(n-1);
    return ans;   // we can directly return without using new variable ans 
}

void print_n_1(int n){
    if(n==0) return;
    cout<<n<<endl;
    print_n_1(n-1);
}

void print_n_1(int n, int i){
    if(i==n+1) return;
    print_n_1(n,i+1);
    cout<<i<<endl;
}

void print_1_n(int n){
    if(n==0) return;
    print_1_n(n-1);
    cout<<n<<endl;
}

void print_1_n(int i, int n){
    if(i>n) return;
    cout<<i<<endl;
    print_1_n(i+1,n);
}

int sum_1_n(int n){
    if(n==0) return 0;
    return n + sum_1_n(n-1);
}

void sum_1_n(int sum, int n){
    if(n==0){
        cout<<sum<<endl;
        return;
    }
    sum_1_n(sum+n,n-1);
}

int power(int a, int b){
    if(a == 0) return 0;
    int ans = 1;
    for(int i=1; i<=b; i++) ans *= a;
    return ans;
}

int power_recursion(int a, int b){
    if(a == 0) return 0;
    if(b == 0) return 1;
    return a * power_recursion(a,b-1);
}