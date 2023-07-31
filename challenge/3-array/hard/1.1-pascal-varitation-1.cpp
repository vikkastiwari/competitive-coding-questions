#include <bits/stdc++.h>
using namespace std;

/**
 * @brief - Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
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
 * @return * res
 */

int nCr(int n, int r)
{
    long long res = 1;

    // calculating nCr:
    // 6C3 = (6*5*4) / (3*2*1)
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i); // (6*5*4)
        res = res / (i + 1); // (6*5*4) / (3*2*1)
    }
    return res;
}

int pascalTriangle(int row, int col){
    int element = nCr(row - 1, col - 1);
    return element;
}

int main(){
    int row = 7;
    int col = 4;
    cout << pascalTriangle(row,col) << endl;
    return 0;
}