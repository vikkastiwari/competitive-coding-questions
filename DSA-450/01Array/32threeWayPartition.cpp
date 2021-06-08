// question link: https://leetcode.com/problems/excel-sheet-column-title/

#include <bits/stdc++.h>
using namespace std;

void threePartition(vector<int> arr, int a, int b)
{
    int n = arr.size();
    int start = 0, end = n - 1;
    int i = 0;
    // dutch flag algorithm
    while (i < end)
    {
        if (arr[i] < a)
        {
            swap(arr[i++], arr[start++]);
        }
        else if (arr[i] > b)
        {
            swap(arr[i], arr[end--]);
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 4};
    int a = 2, b = 3;
    threePartition(arr, a, b);
    return 0;
}