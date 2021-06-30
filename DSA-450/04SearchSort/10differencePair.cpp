// question link: https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1#

#include <bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n)
{
    //code
    if (size == 0)
        return false;
    if (size == 1 and arr[0] == n)
        return true;
    sort(arr, arr + size);
    int i = 0, j = 1;
    while (i < size and j < size)
    {
        if (i != j and arr[j] - arr[i] == n)
        {
            return true;
        }
        if (arr[j] - arr[i] < n)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return false;
}

int main()
{
    int arr[] = {2, 4, 5, 7, 7, 6};
    int x = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findPair(arr, n, x);
    return 0;
}
