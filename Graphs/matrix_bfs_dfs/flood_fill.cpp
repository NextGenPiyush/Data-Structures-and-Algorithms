#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color);  // Leetcode-733
void dfs(vector<vector<int> > &image, int currRow, int currCol, int initialColor, int newColor);


int main(){

    return 0;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){  // Leetcode-733
    if(color == image[sr][sc]) return image;
    dfs(image, sr, sc, image[sr][sc], color);
    return image;
}

// The below function will do dfs from currRow, currCol to it's neighbours containing initialCOlor
void dfs(vector<vector<int> > &image, int currRow, int currCol, int initialColor, int newColor){
    int n = image.size(); // total rows
    int m = image[0].size(); // total cols
    if(currRow < 0 || currCol < 0 || currRow >= n || currCol >= m) return; // you are outside the Grid
    if(image[currRow][currCol] != initialColor) return; // if the cell you landed is not of initial color
    
    image[currRow][currCol] = newColor;
    dfs(image, currRow+1, currCol, initialColor, newColor); // down
    dfs(image, currRow, currCol-1, initialColor, newColor); // left
    dfs(image, currRow-1, currCol, initialColor, newColor); // up
    dfs(image, currRow, currCol+1, initialColor, newColor); // right
}