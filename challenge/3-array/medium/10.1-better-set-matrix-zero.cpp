#include <bits/stdc++.h>
using namespace std;

void setMatrixZero(vector<vector<int>> arr) {
    int n = arr.size();
    int m = arr[0].size();
    int row[n] = {0};
    int col[m] = {0};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i] == 1 || col[j] == 1){
                arr[i][j] = 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j] << " ";
        }
    }
}

int main(){
    vector<vector<int>> n = {{1,1,1},{1,0,1},{1,1,1}};
    setMatrixZero(n);
    return 0;
}