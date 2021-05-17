#include <bits/stdc++.h>
using namespace std;

void mergeArray(int arr[], int low, int mid, int high)
{
    int size1 = mid - low + 1;
    int size2 = high - mid;

    int leftArr[size1], rightArr[size2];

    // Filling elements in left array
    for (int i = 0; i < size1; i++)
    {
        leftArr[i] = arr[low + i];
    }

    // Filling elements in right array
    for (int j = 0; j < size2; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0;   // traverse in leftArray
    int j = 0;   // traverse in rightArray
    int k = low; // traverse in original Array

    // comparing two arrays and merging them respectively
    while (i < size1 && j < size2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // inserting remaining elements
    while (i < size1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < size2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high)
{ // this function divides the array until it can't be divided into half

    if (low < high)
    {
        int mid = (low + (high - 1)) / 2;

        // dividing
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // merging
        mergeArray(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 5, 4, 4, 3, 3, 2, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n);

    cout << "Sorted Array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }

    return 0;
}