// question link: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

#include <bits/stdc++.h>
using namespace std;

vector<int> countOccurence(vector<vector<int>> arr)
{
    // Your code here
    int top = 0, bottom = arr.size() - 1, left = 0, right = arr[0].size() - 1;
    int dir = 0;
    vector<int> ans;
    while (top <= bottom && left <= right)
    {
        if (dir == 0)
        {
            for (int i = left; i <= right; i++)
            {
                ans.push_back(arr[top][i]);
            }
            top += 1;
        }
        else if (dir == 1)
        {
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(arr[i][right]);
            }
            right -= 1;
        }
        else if (dir == 2)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(arr[bottom][i]);
            }
            bottom -= 1;
        }
        else if (dir == 3)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(arr[i][left]);
            }
            left += 1;
        }
        dir = (dir + 1) % 4;
    }
    return ans;
}

int main()
{
    vector<vector<int>> nums1 = {{1, 2, 3, 4},
                                 {5, 6, 7, 8},
                                 {9, 10, 11, 12},
                                 {13, 14, 15, 16}};

    vector<int> spiral = countOccurence(nums1);

    for (int i = 0; i < spiral.size(); i++)
    {
        cout << spiral[i] << " ";
    }
    return 0;
}
