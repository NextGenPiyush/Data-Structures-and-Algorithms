#include<bits/stdc++.h>
using namespace std;

int fibo(int n);
int pow(int x, int n);
int stairs_1(int n);
int stairs_2(int n);
int maze_path(int sr, int sc, int er, int ec);
int maze_2(int row, int column);
void print_maze_path(int sr, int sc, int er, int ec, string s);
void print_maze_path_2(int er, int ec, string s);
void pip(int n);

int main(){

//**********************************************************************************************************************//

    // int n;
    // cout<<"Enter the element number of fibonaci series: ";
    // cin>>n;
    // cout<<n<<" element is: "<<fibo(n)<<endl;

//**********************************************************************************************************************//

    // int a,b;
    // cout<<"Enter a: ";
    // cin>>a;
    // cout<<"Enter b: ";
    // cin>>b;
    // cout<<"a raise to the power b: "<<pow(a,b)<<endl;

//**********************************************************************************************************************//

    // int n;
    // cout<<"Enter the number of stairs: ";
    // cin>>n;
    // cout<<"if person can climb 1 or 2 stairs at a time: "<<endl;
    // cout<<"Number of possible combination of climbing the stairs: "<<stairs_1(n)<<endl;
    // cout<<"if person can climb 1,2 and 3 stairs at a time: "<<endl;
    // cout<<"Number of possible combination of climbing the stairs: "<<stairs_2(n)<<endl;

//**********************************************************************************************************************//

    // int n,m;
    // cout<<"Enter the number of rows: ";
    // cin>>n;
    // cout<<"Enter the number of colums: ";
    // cin>>m;
    // cout<<"Total number of possible ways of reaching ("<<n<<","<<m<<"): "<<maze_path(1,1,n,m)<<endl;
    // // print_maze_path(1,1,n,m,"");
    // print_maze_path_2(n,m,"");
    // // cout<<"Total number of possible ways of reaching ("<<n<<","<<m<<"): "<<maze_2(n,m)<<endl;

//**********************************************************************************************************************//

    // int n;
    // cout<<"Enter number: ";
    // cin>>n;
    // pip(n);

//**********************************************************************************************************************//

    return 0;
}

int fibo(int n){
    if(n==1 || n==2){     // we have started the fibonaci seris as: 1 1 2 3 5 8 .....
        return 1;
    }
    else{
        return fibo(n-1) + fibo(n-2);
        // int leftAns = fibo(n-1);
        // int leftAns = fibo(n-1);
        // return leftAns + rightAns;
    }
}

int pow(int x, int n){
    int ans;
    if(n==0){
        return 1;
    }
    else if(n%2 == 0){       // here time complexity is O(logn)
        ans = pow(x,n/2);
        return ans*ans;
    }
    else{
        ans = pow(x,n/2);
        return x*ans*ans;
    }
    // return x*pow(x,n-1);   // here time complexity is O(n)
}

int stairs_1(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    return stairs_1(n-1) + stairs_1(n-2);
}

int stairs_2(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;
    return stairs_2(n-1) + stairs_2(n-2) + stairs_2(n-3);
}

int maze_path(int sr, int sc, int er, int ec){
    if(sr>er || sc>ec){
        return 0;
    }
    if(sr==er || sc==ec){
        return 1;
    }
    int rightWay =  maze_path(sr,sc+1,er,ec);
    int downWay =  maze_path(sr+1,sc,er,ec);
    return rightWay + downWay; 
}

void print_maze_path(int sr, int sc, int er, int ec, string s){
    if(sr>er || sc>ec){
        return;
    }
    if(sr==er && sc==ec){
        cout<<s<<endl;
        return;
    }
    print_maze_path(sr,sc+1,er,ec,s+'R');
    print_maze_path(sr+1,sc,er,ec,s+'D');
}

int maze_2(int row, int column){
    if(row<1 || column<1) return 0;
    if(row==1 && column==1) return 1;
    int rightWay = maze_2(row, column-1);
    int downWay = maze_2(row-1, column);
    return rightWay + downWay;
}

void print_maze_path_2(int er, int ec, string s){
    if(er<1 || ec<1){
        return;
    }
    if(er==1 && ec==1){
        cout<<s<<endl;
        return;
    }
    print_maze_path_2(er,ec-1,s+'R');   // rightway
    print_maze_path_2(er-1,ec,s+'D');   // downway
}

void pip(int n){
    if(n==0){
        return;
    }
    // cout<<"pre: "<<n<<endl;
    cout<<n<<" ";
    pip(n-1);
    // cout<<"In: "<<n<<endl;
    cout<<n<<" ";
    pip(n-1);
    // cout<<"Post: "<<n<<endl;
    cout<<n<<" ";
}