// question link: https://practice.geeksforgeeks.org/problems/inversion-of-array/0

#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> arr, vector<int> temp, int low, int mid, int high)
{
    int i, j, k, inv_count = 0;
    i = low, j = mid, k = high;

    return inv_count;
}

int mergeSort(vector<int> arr, vector<int> temp, int low, int high)
{
    int inv_count = 0;
    while (low < high)
    {
        int mid = (low + high) / 2;
        inv_count += mergeSort(arr, temp, low, mid);
        inv_count += mergeSort(arr, temp, mid + 1, high);

        inv_count += merge(arr, temp, low, mid, high);
    }
    return inv_count;
}

int main()
{
    vector<int> arr = {1, 20, 6, 4, 5};
    vector<int> temp(arr.size());
    int low = 0, high = arr.size();
    int inversion = mergeSort(arr, temp, low, high);
    return 0;
}