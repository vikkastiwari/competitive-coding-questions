#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> arr, int n, int target) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid]==target){
            return mid;
        }
        if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1; 
        }
    }
    return ans;
}

/**
 * @brief optimised
 * TC: O(n+logm)
 * 
 * @param matrix 
 * @return * void 
 */
void findTargetInMatrix(vector<vector<int>> &matrix, int n, int m, int target) {
    for(int i=0;i<n;i++){
        if(matrix[i][m-1]==target){
            cout << "true" << endl;
            return;
        }
        else if(matrix[i][m-1]>target){
            //call bs on ith row
            int ans = bs(matrix[i],m,target);
            if(ans != -1){
                cout << "true" << endl;
                return;
            }

        }else{
            continue;
        }
    }
    cout << "false" << endl;
}

/**
 * @brief Optimised find target in 2d matrix
 * TC: O(log(n*m))
 * SC: O(1)
 * 
 * @param matrix 
 * @param n 
 * @param m 
 * @param target 
 * @return * void 
 */
void findTargetInMatrixOpt(vector<vector<int>> &matrix, int n, int m, int target){
    int low = 0, high = (n*m)-1;
    while(low<=high){
        int mid = (low+high)/2;
        int row = mid/m, col = mid%m;

        if(matrix[row][col] == target) {
            cout << " true" << endl;
            return;
        }else if(matrix[row][col] < target){
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }
    cout << "false" << endl;
}

int main(){
    int n = 3,m = 4, target = 7;
    vector<vector<int>> mat = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};
    findTargetInMatrixOpt(mat,n,m,target);
    return 0;
}