#include<bits/stdc++.h>
using namespace std;

void print_inc_dec(int n, int i);
void print_sum_odd(int a, int b, int &sum);
// void print_sum_odd(int a, int b);  // not possible in this case, it is necessary to pass
// reffernce of sum = 0 in the main function to the function print_sum_odd
bool is_power_of_2(int n);

int main(){

//******************************************************************************************************************//

    // int n;
    // int idx = 1;
    // cout<<"Enter number: ";
    // cin>>n;
    // print_inc_dec(n,idx);

//******************************************************************************************************************//

    // int a,b;
    // cout<<"Enter number-1: ";
    // cin>>a;
    // cout<<"Enter number-2: ";
    // cin>>b;
    // int sum = 0;
    // print_sum_odd(a,b,sum);
    // cout<<"Sum of odd numbers between "<<a<<" and "<<b<<" is: "<<sum<<endl;
    // // print_sum_odd(a,b);  // not possbile in this case
    
//******************************************************************************************************************//

    // int n;
    // cout<<"Enter number: ";
    // cin>>n;
    // if(is_power_of_2(n) == 1){
    //     cout<<n<<" can be expressed as power of 2"<<endl;
    // }
    // else{
    //     cout<<n<<" can't be expressed as power of 2"<<endl;
    // }

//******************************************************************************************************************//

    return 0;
}

void print_inc_dec(int n, int i){
    if(i>n){
        return;
    }
    cout<<i<<" ";
    print_inc_dec(n,i+1);
    if(i>1){
        cout<<i-1<<" ";
    }
    else{
        return;
    }
}

void print_sum_odd(int a, int b, int &sum){  // here we cannot do this question by taking 
                                             // int sum = 0 inside the function
    if(a>b){
        return;
    }
    if(a%2 != 0){
        sum += a;
        print_sum_odd(a+2,b,sum);
    }
    else{
        print_sum_odd(a+1,b,sum);
    }
}

// void print_sum_odd(int a, int b){    // wring output we cannot do like this
//     int sum = 0;
//     if(a>b){
//         cout<<"a is greater than b now: "<<endl;
//         cout<<sum<<endl;
//         return;
//     }
//     if(a%2 != 0){
//         sum += a;
//         print_sum_odd(a+2,b);
//     }
//     else{
//         print_sum_odd(a+1,b);
//     }
// }

bool is_power_of_2(int n){
    if(n==1){
        return true;
    }
    if(n%2 != 0){
        return false;
    }
    return is_power_of_2(n/2);
}