// question link: https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1#

#include <bits/stdc++.h>
using namespace std;

int FindMaxSum(vector<int> arr, int n)
{
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    int i;

    for (i = 1; i < n; i++)
    {
        /* current max excluding i */
        excl_new = (incl > excl) ? incl : excl;

        /* current max including i */
        incl = excl + arr[i];
        excl = excl_new;
    }

    return ((incl > excl) ? incl : excl);
}

int main()
{
    vector<int> arr = {5, 5, 10, 100, 200, 5};
    cout << FindMaxSum(arr, arr.size());
}
