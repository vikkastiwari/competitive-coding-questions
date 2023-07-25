#include <bits/stdc++.h>
using namespace std;

void setRowColToZero(vector<vector<int>> &copyArr, int i, int j){
    int n = copyArr.size();
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            if(i==a || j==b){
                copyArr[a][b] = 0;
            }
        }
    }
}

void setMatrixZero(vector<vector<int>> arr) {
    int n = arr.size();
    vector<vector<int>> copyArr = arr;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 0){
                setRowColToZero(copyArr,i,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << copyArr[i][j] << " ";
        }
    }
}

int main(){
    vector<vector<int>> n = {{1,1,1},{1,0,1},{1,1,1}};
    setMatrixZero(n);
    return 0;
}