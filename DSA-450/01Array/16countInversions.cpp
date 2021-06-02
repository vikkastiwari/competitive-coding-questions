// question link: https://practice.geeksforgeeks.org/problems/inversion-of-array/0

#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> arr, vector<int> temp, int low, int mid, int high)
{
    int i, j, k, inv_count = 0;
    i = low, j = mid, k = low;

    while (i <= mid - 1 && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }

    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }

    while (j <= high)
    {
        temp[k++] = arr[j++];
    }

    for (i = low; i <= high; i++)
        arr[i] = temp[i];

    return inv_count;
}

int mergeSort(vector<int> arr, vector<int> temp, int low, int high)
{
    int inv_count = 0;
    if (low < high)
    {
        int mid = (low + high) / 2;
        inv_count += mergeSort(arr, temp, low, mid);
        inv_count += mergeSort(arr, temp, mid + 1, high);

        inv_count += merge(arr, temp, low, mid + 1, high);
    }
    return inv_count;
}

int main()
{
    vector<int> arr = {1, 20, 6, 4, 5};
    vector<int> temp(arr.size());
    int low = 0, high = arr.size();
    int inversion = mergeSort(arr, temp, low, high - 1);
    cout << inversion << endl;
    return 0;
}