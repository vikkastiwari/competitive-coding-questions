// question link: https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/

#include <bits/stdc++.h>
using namespace std;

// we cant use extra space either we would have seperated values in two arrays +Ve , -ve respectively and arranged them accordingly.
// space = O(1) and this code do not maitain the order

void rearrange(int arr[], int n)
{
    int i = 0, j = n - 1;
    // arr=[all +ve, all -ve];
    while (i <= j)
    {
        if (arr[i] < 0 && arr[j] > 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        else if (arr[i] > 0 && arr[j] < 0)
        {
            i++;
            j--;
        }
        else if (arr[i] > 0)
        {
            i++;
        }
        else if (arr[j] < 0)
        {
            j--;
        }
    }
    cout << i << endl;
    // i==0 indicates all negative - after
    // i==n indicates all positive - before
    if (i == 0 || i == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {
        int k = 0;
        // i is the start of negative values in array

        while (k < n && i < n)
        {
            swap(arr[k], arr[i]);
            k += 2;
            i++;
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, -4, -1, 4};
    int n = 6;
    rearrange(arr, n);

    return 0;
}