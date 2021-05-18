#include <bits/stdc++.h>
using namespace std;

// Function for swapping the array elements
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Partitioning of the array
int Partition(int arr[], int lowerIndex, int upperIndex)
{
    int pivot, index, i;
    index = lowerIndex;
    pivot = upperIndex;
    for (i = lowerIndex; i < upperIndex; i++)
    {
        if (arr[i] < arr[pivot])
        {
            swap(&arr[i], &arr[index]);
            index++;
        }
    }
    swap(&arr[pivot], &arr[index]);
    return index;
}

int quickSort(int arr[], int lowerIndex, int upperIndex)
{
    int pindex; // pivot index
    if (lowerIndex < upperIndex)
    {
        pindex = Partition(arr, lowerIndex, upperIndex);
        quickSort(arr, lowerIndex, pindex - 1); // Recursively calling function
        quickSort(arr, pindex + 1, upperIndex);
    }
    return 0;
}

int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n);

    cout << "Sorted Array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }

    return 0;
}