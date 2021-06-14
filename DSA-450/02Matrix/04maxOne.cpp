// question link: https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#

#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> arr)
{
    // code here
    int n = arr.size();
    int m = arr[0].size();
    int max = 0, row = -1;
    int rowel = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                count++;
            }
        }
        if (count > max)
        {
            max = count;
            row = i;
        }
    }
    return row;
}

int main()
{
    vector<vector<int>> n = {{0, 1, 1, 1},
                             {0, 0, 1, 1},
                             {1, 1, 1, 1},
                             {0, 0, 0, 0}};
    cout << rowWithMax1s(n) << endl;
    return 0;
}
