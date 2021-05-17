/* Insertion Sort

  Time Complexity = O(n^2)
  Space Complexity = O(1)
*/
#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    // traverse once and place all the elements in their right place

    // for loop helps us to traverse
    for (int i = 1; i < n; i++)
    {
        int num = arr[i];
        int j = i - 1;
        // while loop helps us to place all the elements at their right position
        while (j >= 0 && arr[j] > num)
        {
            arr[j + 1] = arr[j];
            j = j - 1; // counter
        }
        arr[j + 1] = num;
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    cout << "Sorted Array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}