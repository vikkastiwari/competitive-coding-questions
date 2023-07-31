#include <bits/stdc++.h>
using namespace std;

/**
 * @brief - Given the row number n. Print the n-th row of Pascal’s triangle.
 * 
 *  We can optimize this calculation by the following observation. 
 *  Assume, given r = 7, c = 4. 
 *  Now, n = r-1 = 7-1 = 6 and r = c-1 = 4-1 = 3
 *  Let’s calculate 6C3 = 6! / (3! *(6-3)!) = (6*5*4*3*2*1) / ((3*2*1)*(3*2*1))
 *  This will boil down to (6*5*4) / (3*2*1)
 *  So, nCr = (n*(n-1)*(n-2)*.....*(n-r+1)) / (r*(r-1)*(r-2)*....1)
 * 
 * TC: O(r)
 * SC: O(1)
 * 
 * @param n 
 * @param r 
 * @return res 
 */

int nCr(int n, int r)
{
    long long res = 1;
    // calculating nCr:
    // 6C3 = (6*5*4) / (3*2*1)
    for (int i = 0; i < r; i++) { // r times
        res = res * (n - i); // (6*5*4)
        res = res / (i + 1); // (6*5*4) / (3*2*1)
    }
    return res;
}

/**
 * @brief Naive Approach
 * 
 * TC: O(n*r)
 * SC: O(1)
 * 
 */
void printPascalTriangleRowNaive(int row){
    for(int i=1;i<=row;i++){ // n times
        int element = nCr(row - 1, i - 1);
        cout << element << " ";
    }
    cout << endl;
}

/**
 * @brief Optimal approach
 * TC: O(n)
 * SC: O(1)
 * 
 * formula (ans * (row - col)) / col;
 * row = n;
 * col = i;
 */
void printPascalTriangleRowOptimal(int row) {
    long long ans = 1;
    cout << ans << " "; // printing 1st element

    for (int i = 1; i < row; i++) {
        ans = ans * (row - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    int row = 5;
    printPascalTriangleRowOptimal(row);
    return 0;
}