
#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)(res);
}

/**
 * @brief brute force approach
 * TC: ~ O(n*n*r) ~ O(n^3)
 * SC: using ans to return and not compute so we can neglect it
 * 
 */
vector<vector<int>> pascalTriangleNaive(int n) {
    vector<vector<int>> ans;

    for (int row = 1; row <= n; row++) {
        vector<int> tempLst;
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}

/**
 * @brief Optimal approach
 * TC: O(n^2)
 * SC: O(1)
 * 
 */
void printRow(int row){
    long long ans = 1;
    cout << ans << " "; // printing 1st element

    for (int i = 1; i < row; i++) {
        ans = ans * (row - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}

void pascalTriangleOptimal(int row){
    for(int i=1;i<=row;i++){
        printRow(i);
    }
}

int main()
{
    int n = 5;
    // naive
    // vector<vector<int>> ans = pascalTriangleNaive(n);
    // for (auto itr : ans) {
    //     for (auto el : itr) {
    //         cout << el << " ";
    //     }
    //     cout << endl;
    // }

    // optimal
    pascalTriangleOptimal(n);
    return 0;
}
