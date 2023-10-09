#include <bits/stdc++.h>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int row = mat.size(), col = mat[0].size();
    int i = 0, j = col -1;
    while(i>=0 && i<row && j>=0 && j<col){

        // finding nums in all 4 directions
        int up = i-1<0 ? -1 : mat[i-1][j];
        int down = i+1>=row ? -1 : mat[i+1][j];
        int left = j-1<0 ? -1 : mat[i][j-1];
        int right = j+1>=col ? -1 : mat[i][j+1];

        // check if current is peak
        if(mat[i][j] > up && mat[i][j] > left && mat[i][j] > right && mat[i][j] > down)
            return {i, j};
        
        // get maxm among 4 direction
        int maxVal=max({up, down, left, right});
        
        // move in max direction
        if(up == maxVal) i--;
        else if(down == maxVal) i++;
        else if(left == maxVal) j--;
        else if(right == maxVal) j++;
    }
    return {-1,-1};
}


int main(){
    int n = 36;
    vector<vector<int>> mat = {{10,20,15},{21,30,14},{7,16,32}};
    vector<int> res = findPeakGrid(mat);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}