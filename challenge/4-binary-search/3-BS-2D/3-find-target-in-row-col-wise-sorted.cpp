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
 * @brief better approach
 * TC: O(n*logm)
 * 
 * @param matrix 
 * @return * void 
 */
void findTargetInMatrix(vector<vector<int>> &matrix, int n, int m, int target) {
    for(int i=0;i<n;i++){
        //call bs on ith row
        int ans = bs(matrix[i],m,target);
        if(ans != -1){
            cout << "true" << endl;
            return;
        }
    }
    cout << "false" << endl;
}

/**
 * @brief Optimised find target in 2d matrix
 * TC: O(log(n+m)) // we will visit row and col once only and that too selectively
 * SC: O(1)
 * 
 * @param matrix 
 * @param n 
 * @param m 
 * @param target 
 * @return * void 
 */
void findTargetInMatrixOpt(vector<vector<int>> &matrix, int n, int m, int target){
    // will start from first row's last element (0,m-1)
    // here row will be in decreasing order and col will be in increasing order
    // similarly we can also start from first col's last index (n-1,0)

    int row = 0, col = m-1; 
    while(row<n && col>=0){
        if(matrix[row][col] == target) {
            cout << " true" << endl;
            return;
        }else if(matrix[row][col] > target){
            /**
             * We need the smaller elements to reach the target. 
             * But the column is in increasing order and so 
             * it contains only greater elements. So, we will 
             * eliminate the column by decreasing the current 
             * column value by 1(i.e. col–) and thus we will 
             * move row-wise.
             */
            col--;
        }else {
            /**
             * In this case, We need the bigger elements to 
             * reach the target. But the row is in decreasing 
             * order and so it contains only smaller elements. 
             * So, we will eliminate the row by increasing the 
             * current row value by 1(i.e. row++) and thus 
             * we will move column-wise.
             */
            row++;
        }
    }
    cout << "false" << endl;
}

int main(){
    int n = 3,m = 3, target = 17;
    vector<vector<int>> mat = {
        {1, 3, 7},
        {6, 13, 15},
        {14, 20, 21}
    };
    findTargetInMatrixOpt(mat,n,m,target);
    return 0;
}