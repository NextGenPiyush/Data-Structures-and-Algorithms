#include<bits/stdc++.h>
using namespace std;

int sum_of_digits_1(int n);
int sum_of_digits_2(int n, int &sum);
int sum_of_digits_3(int n);
void reverse_number_1(int n);
void reverse_number_2(int n);
int reverse_number_3(int n);
int count_step_1(int n);
int count_step_2(int n);
int func(int n);

int main(){

//*******************************************************************************************************************//

    // int n;
    // cout<<"Enter number: ";
    // cin>>n;
    // int sum = 0;
    // // cout<<"Sum of digits of the number: "<<sum_of_digits_1(n)<<endl;
    // cout<<"Sum of digits of the number: "<<sum_of_digits_2(n,sum)<<endl;

//*******************************************************************************************************************//

    // int n;
    // cout<<"Enter number: ";
    // cin>>n;
    // cout<<"Reversing number: "<<endl;
    // // reverse_number_1(n);
    // // reverse_number_2(n);
    // reverse_number_3(n);

//*******************************************************************************************************************//

    // int n;
    // cout<<"Enter number: ";
    // cin>>n;
    // cout<<"When n is even then n->n/2 and odd then n->n-1"<<endl;
    // // cout<<"Steps required to reduce number to zero: "<<count_step_1(n)<<endl;;
    // cout<<"Steps required to reduce number to zero: "<<count_step_2(n)<<endl;;

//*******************************************************************************************************************//

    // // predict the output
    // cout<<func(7)<<endl;

//*******************************************************************************************************************//


    return 0;
}

int sum_of_digits_1(int n){
    int sum = 0;
    while(n > 0){
        sum += n%10;
        n /= 10;      
    }
    return sum;
}

int sum_of_digits_2(int n, int &sum){
    if(n==0){
        return sum;
    }
    sum += n%10;
    sum_of_digits_2(n/10,sum);
}

int sum_of_digits_3(int n){
    if(n>=0 && n<=9){
        return n;
    }
    return (n%10) + sum_of_digits_3(n/10);
}

void reverse_number_1(int n){
    // while(n>0){
    //     cout<<n%10<<"";
    //     n /= 10;
    // }
    
    int ans = 0;   // we can also do like this 
    while(n>0){
        ans = ans*10 + n%10;     
        n /= 10;
    }
}

void reverse_number_2(int n){
    if(n>=0 && n<=9){
        cout<<n<<"";
        return;
    }
    cout<<n%10<<"";
    reverse_number_2(n/10);
}

int reverse_number_3(int n){
    static int ans = 0;
    if(n==0) return ans;
    ans = (ans*10) + (n%10);
    reverse_number_3(n/10);
}

int count_step_1(int n){                  // space complexity O(n)
    int static count = 0;
    if(n==0){
        return count;
    }
    else if(n%2 == 0){
        count_step_1(n/2);
    }
    else{
        count_step_1(n-1);
    }
    count++;
    return count;
}

int count_step_2(int n){              // space complixity O(logn)
    if(n==1){            // we can also write base case for 1
        return 1;
    }
    // if(n==0){
    //     return 0;
    // }
    else if(n%2 == 0){
        return 1 + count_step_1(n/2);
    }
    else{
        return 1 + count_step_1(n-1);
    }
}

int func(int n){
    if(n<=1) return 1;
    if(n%2 == 0) return func(n/2);
    return func(n/2) + func((n/2) + 1);
}
