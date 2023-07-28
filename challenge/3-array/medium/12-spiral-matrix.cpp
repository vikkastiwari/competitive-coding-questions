#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &res){
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    cout << endl;
}

void spiralMatrix(vector < vector < int >> & matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> res;

    int top = 0; // traversing col, row wise - top to bottom 
    int left =0; // traversing row, col wise - left to right
    int right = m-1; // traversing row, col wise - right to left
    int bottom = n-1; // traversing col, row wise  - bottom to top

    //printing in spiral form
    while(top<=bottom && left <= right){
        // 1 - left to right
        for(int i=left;i<=right;i++){
            res.push_back(matrix[top][i]);
        }
        top++;
        // 2 - top to bottom
        for(int i=top;i<=bottom;i++){
            res.push_back(matrix[i][right]);
        }
        right--;
        // 3 - right to left
        if(top<=bottom){ // checks that row exist to be printed
            for(int i=right;i>=left;i--){
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        // 4 - bottom to top
        if(left<=right){ // checks that col exists to be printed
            for(int i=bottom;i>=top;i--){
                res.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    print(res);
}

int main(){
    vector<vector<int>> arr = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13, 14, 15, 16}};
    spiralMatrix(arr);
    return 0;
}