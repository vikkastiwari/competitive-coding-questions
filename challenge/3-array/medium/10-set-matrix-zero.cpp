#include <bits/stdc++.h>
using namespace std;

void setRowColToZero(vector<vector<int>> &copyArr, int i, int j){
    int n = copyArr.size();
    for(int a=0;a<n;a++){
        for(int b=0;b<copyArr[0].size();b++){
            if(i==a || j==b){
                copyArr[a][b] = 0;
            }
        }
    }
}

/**
 * @brief brute force approach
 * TC: O(2*(N*M))
 * 
 */

void setMatrixZero(vector<vector<int>> arr) {
    int n = arr.size();
    vector<vector<int>> copyArr = arr;
    for(int i=0;i<n;i++){
        for(int j=0;j<copyArr[0].size();j++){
            if(arr[i][j] == 0){
                setRowColToZero(copyArr,i,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<copyArr[0].size();j++){
            cout << copyArr[i][j] << " ";
        }
    }
}

int main(){
    vector<vector<int>> n = {{1,1,1},{1,0,1},{1,1,1}};
    setMatrixZero(n);
    return 0;
}