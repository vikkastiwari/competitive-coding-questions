#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Set the Matrix Zero
 * TC: O(2*N*M)
 * SC: O(1)
 * 
 * @param arr 
 * @return * void 
 */
void setMatrixZero(vector<vector<int>> &arr) {
    int n = arr.size();
    int m = arr[0].size();
    // int col[m] = {0}; ---> matrix[0][..] - first row
    // int row[n] = {0}; ---> matrix[..][0] - first col
    int col0 = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                // mark the ith row in first col
                arr[i][0] = 0;
                // mark the jth col in first row
                if(j != 0) 
                // we can mark only if 
                // its not first position in first column 
                    arr[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][j] != 0){
                // check for col and row respectively
                if(arr[0][j] == 0 || arr[i][0] == 0){
                    arr[i][j] = 0;
                }
            }
        }
    }

    // making first row zero if arr[0][0] == 0
    if(arr[0][0] == 0){
        for(int j=0;j<m;j++) arr[0][j] = 0;
    }

    // making first col zero if col0 == 0
    if(col0 == 0){
        for(int i=0;i<n;i++) arr[i][0] = 0;
    }
}

int main(){
    vector<vector<int>> arr = {{1,1,1},{1,0,1},{1,1,1}};
    setMatrixZero(arr);
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}