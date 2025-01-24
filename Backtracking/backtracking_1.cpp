#include<bits/stdc++.h>
using namespace std;

void permutation_of_string(string str, unordered_set<char> &s, vector<string> &v);
void permutation(string input, string output);
void permutation_2(string &str, int i);

vector<vector<char>> grid;
vector<vector<string>> result;
bool canPlaceQueen(int row, int col, int n);
void func(int row, int n);
vector<vector<string>> nQueen(int n); // Leetcode-51

int ans;
int ratInMaze(vector<vector<int>> &grid, int n);
void f(vector<vector<int>> &grid, int n, int i, int j);
bool canWeGo(int n, int row, int col, vector<vector<int>> &grid);

int main(){

//************************************************************************************************************//

    // vector<string> v;  // approach_1   
    // string str;  
    // unordered_set<char> s;
    // cin >> str;
    // for (int i = 0; i < str.size(); i++) s.insert(str[i]);
    // permutation_of_string("", s, v);
    // for(string ele: v) cout<<ele<<" ";
    // cout<<endl;

    // permutation("abc","");  // approach_2

    // string str1 = "abc";  // approach_3
    // string str2 = "aba";
    // permutation_2(str2,0);

//************************************************************************************************************//

    // int n;
    // cin>>n;
    // nQueen(n);
    // for(int i=0; i<result.size(); i++){
    //     for(int j=0; j<result[i].size(); j++) cout<<result[i][j]<<endl;
    //     cout<<endl;
    // }

//************************************************************************************************************//

    vector<vector<int>> grid = {
        {0,0,1,0,0,1,0},
        {1,0,1,1,0,0,0},
        {0,0,0,0,1,0,1},
        {1,0,1,0,0,0,0},
        {1,0,1,1,0,1,0},
        {1,0,0,0,0,1,0},
        {1,1,1,1,0,0,0}};
    cout<<ratInMaze(grid,7)<<endl;

//************************************************************************************************************//



    return 0;
}

void permutation_of_string(string str, unordered_set<char> &s, vector<string> &v){
    if(s.empty()){
        v.push_back(str);
        return;
    }
    // Create a vector from the set to iterate safely
    vector<char> elements(s.begin(), s.end());
    for(char ch : elements){
        s.erase(ch); // Remove the character from the set
        permutation_of_string(str + ch, s, v);
        s.insert(ch); // Add the character back to the set
    }
}
void permutation(string input, string output){
    if(input.size() == 0){
        cout<<output<<endl;
        return;
    }
    for(int i=0; i<input.size(); i++){
        char ch = input[i];
        string left = input.substr(0,i);  // we are calculating substring again again in the for loop
        string right = input.substr(i+1); // not a very good time complexity
        string rem = left+right;       // this is also not a good optimization of space
        permutation(rem,output+ch);
    }
}
void permutation_2(string &str, int i){
    if(i == str.size()-1){
        cout<<str<<endl;
        return;
    }
    unordered_set<char> s;
    for(int idx=i; idx<str.size(); idx++){
        if(s.count(str[idx])) continue; // to handle repeated calls where there will be repeated characters 
        s.insert(str[idx]);    // present in the given string
        swap(str[idx],str[i]);
        permutation_2(str,i+1);
        swap(str[idx],str[i]);  // backtracking
    }
}

bool canPlaceQueen(int row, int col, int n){
    for(int i=row-1; i>=0; i--) if(grid[i][col]=='Q') return false;  // we are attacked by column
    for(int i=row-1,j=col-1; i>=0 and j>=0; i--,j--) if(grid[i][j]=='Q') return false; // attacked by left_diag
    for(int i=row-1,j=col+1; i>=0 and j<n; i--,j++) if(grid[i][j]=='Q') return false; // attacked by right_diag
    return true; // no attack found
}
void func(int row, int n){
    if(row == n){  // we got one possible ans
        vector<string> temp;
        for(int i=0; i<n; i++){
            string res = "";
            for(int j=0; j<n; j++) res += grid[i][j];
            temp.push_back(res);
        }
        result.push_back(temp);
        return;
    }
    for(int col=0; col<n; col++){
        if(canPlaceQueen(row,col,n)){
            grid[row][col] = 'Q';
            func(row+1,n);
            grid[row][col] = '.'; // backtracking 
        }
    }
}
vector<vector<string>> nQueen(int n){ // Leetcode-51
    grid.clear();
    result.clear();
    grid.resize(n,vector<char> (n,'.'));
    func(0,n);
    return result;
}
int ratInMaze(vector<vector<int>> &grid, int n){
    ans = 0;
    f(grid,n,0,0);
    return ans;
}
void f(vector<vector<int>> &grid, int n, int i, int j){
    if(i==n-1 and j==n-1){
        ans += 1;
        return;
    }
    grid[i][j] = 2;  // visited 
    if(canWeGo(n,i,j-1,grid)) f(grid,n,i,j-1); // left
    if(canWeGo(n,i-1,j,grid)) f(grid,n,i-1,j); // up
    if(canWeGo(n,i,j+1,grid)) f(grid,n,i,j+1); // right
    if(canWeGo(n,i+1,j,grid)) f(grid,n,i+1,j); // bottom
    grid[i][j] = 0;
}
bool canWeGo(int n, int row, int col, vector<vector<int>> &grid){
    return row>=0 and col>=0 and row<n and col<n and grid[row][col] == 0;
}
