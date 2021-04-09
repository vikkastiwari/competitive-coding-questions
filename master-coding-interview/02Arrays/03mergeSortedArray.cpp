#include <bits/stdc++.h>
using namespace std;

// we are creating function pointer that points to the array that we will be returned.
int *mergeArray(int *arr1, int *arr2, int size1, int size2)
{
    if (size1 == 0)
    {
        return arr2;
    }
    if (size2 == 0)
    {
        return arr1;
    }

    int *arr = new int[size1 + size2];
    int index1 = 0, index2 = 0, index = 0;

    while (index1 < size1 && index2 < size2)
    {
        // Check if current element of first
        // array is smaller than current element
        // of second array. If yes, store first
        // array element and increment first array
        // index. Otherwise do same with second array
        if (arr1[index1] <= arr2[index2])
        {
            arr[index] = arr1[index1];
            index1++;
        }
        else
        {
            arr[index] = arr2[index2];
            index2++;
        }
        index++;
    }

    // Store remaining elements of first array
    while (index1 < size1)
    {
        arr[index++] = arr1[index1++];
    }

    // Store remaining elements of second array
    while (index2 < size2)
    {
        arr[index++] = arr2[index2++];
    }
    return arr;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int arr2[] = {3, 4, 5, 7, 8, 9, 10, 11};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int *arr = mergeArray(arr1, arr2, size1, size2);

    cout << "Merged Array: " << endl;
    for (int i = 0; i < size1 + size2; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;

    return 0;
}