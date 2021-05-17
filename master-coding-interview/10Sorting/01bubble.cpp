#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - 1 - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{

    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << sizeof(arr) << endl;
    cout << sizeof(arr[0]) << endl;
    BubbleSort(arr, n);
    cout << "Sorted Array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
    return 0;
}
