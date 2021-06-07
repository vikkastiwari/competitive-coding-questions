// question link: https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621

#include <bits/stdc++.h>
using namespace std;

int find3Numbers(int arr[], int n, int X)
{
    //Your Code Here
    bool x = false;
    int first, last;
    for (int i = 0; i < n - 2; i++)
    {
        first = i + 1;
        last = n - 1;
        while (first < last)
        {
            if (first + arr[i] + last == X)
            {
                x = true;
                break;
            }
            else if (first + arr[i] + last > X)
            {
                last--;
            }
            else if (first + arr[i] + last < X)
            {
                first++;
            }
        }
    }
    return x;
}

int main()
{
    // int arr[] = {1, 4, 45, 6, 10, 8};
    int arr[] = {1, 4, 2, 6, 3};
    int n = 5;
    int X = 10;
    sort(arr, arr + n);
    cout << find3Numbers(arr, n, X) << endl;
    return 0;
}
