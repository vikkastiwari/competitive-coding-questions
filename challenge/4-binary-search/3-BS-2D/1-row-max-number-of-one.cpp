#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

/**
 * @brief bruteforce
 * TC: O(n*m)
 * 
 * @param num 
 * @return * void 
 */
void findRowWithMaxOnes(vector<vector<int>> num){
   int row = -1;
   for(int i=0;i<num.size();i++){
        int rowct = 0;
        int cnt = count(num[i].begin(), num[i].end(), 1);
        if(rowct < cnt){
            rowct = cnt;
            row = i;
        }
   }
   cout << row << endl;
}

/**
 * @brief optimised
 * TC: O(n*logm)
 * 
 * @param matrix 
 * @return * void 
 */
void rowWithMaxOnes(vector<vector<int>> &matrix) {
    int cnt_max = 0;
    int index = -1;
    int n = matrix.size(), m = matrix[0].size();

    //traverse the rows:
    for (int i = 0; i < n; i++) {
        // get the number of 1's:
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    cout << index << endl;
}

int main(){
    int n = 36;
    vector<vector<int>> mat = {{0,0,1},{0,1,0},{1,1,1}};
    rowWithMaxOnes(mat);
    return 0;
}