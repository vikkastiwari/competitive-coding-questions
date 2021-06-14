// question link: https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/

#include <bits/stdc++.h>
using namespace std;

int sortedMatrixMedian(vector<vector<int>> mat)
{
    int row = mat.size();
    int col = mat[0].size();
    int min = INT_MAX, max = INT_MIN;
    // as row of matrix is sorted it is given thats why we know min is in first col and max is in last col of matrix
    for (int i = 0; i < row; i++)
    {
        if (mat[i][0] < min)
            min = mat[i][0];

        if (mat[i][col - 1] > max)
            max = mat[i][col - 1];
    }
    //
    int desired = (row * col + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;

        // Find count of elements smaller than mid
        for (int i = 0; i < row; ++i)
            // no operator "+" matches these operands -- operand types are: std::vector<int, std::allocator<int>> + intC/C++(349)
            place += upper_bound(mat[i], mat[i] + col, mid) - mat[i];
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;

    return 0;
}

int main()
{
    vector<vector<int>> mat = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout << "Median is " << sortedMatrixMedian(mat) << endl;
    return 0;
}