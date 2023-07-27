#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Brute Force
 * TC: O(N*N) - linearly iterated to push value and for updating og matrix
 * SC: O(N)
 * 
 * @param arr 
 * @return * void 
 */
void rotateMatrixBy90Sol1(vector<vector<int>> &arr) {
    int n = arr.size();
    int m = arr[0].size();
    vector<int> val;
    // this is how we dynamically allocate size of nested vector
    // vector < vector < int >> rotated(n, vector < int > (n, 0));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            val.push_back(arr[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        int itr = i;
        for(int j=0;j<m;j++){
            arr[i][j] = val[itr];
            itr = itr + n;
        }
    }
}

/**
 * @brief optimal solution
 * 
 * @param matrix 
 * @return * void 
 */
void rotateMatrixBy90Sol2(vector < vector < int >> & matrix) {
    int n = matrix.size();
    //transposing the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    //reversing each row of the matrix
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main(){
    // vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> arr = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    rotateMatrixBy90Sol2(arr);
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}