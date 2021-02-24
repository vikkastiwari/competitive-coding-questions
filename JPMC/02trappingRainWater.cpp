// C++ program to find maximum amount of water that can
// be trapped withighn given set of bars.
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <iostream>
using namespace std;

int findWater(int arr[], int n)
{
    // initialize output
    int result = 0;

    // maximum element on left and right
    int left_max = 0, right_max = 0;

    // indices to traverse the array
    int low = 0, high = n - 1;

    while (low <= high)
    {
        if (arr[low] < arr[high])
        {
            if (arr[low] > left_max)
                // update max in left
                left_max = arr[low];
            else
            {
                // water on curr element = max - curr
                result += left_max - arr[low];
                // cout << "left_max - arr[low]: " << left_max - arr[low] << " ";
            }
            low++;
        }
        else
        {
            if (arr[high] > right_max)
                // update right maximum
                right_max = arr[high];
            else
            {
                result += right_max - arr[high];
                // cout << "right_max - arr[high]: " << right_max - arr[high] << " ";
            }
            high--;
        }
        // cout << endl;
    }
    return result;
}

int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // int arr[] = {3, 0, 1, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum water that can be accumulated is " << findWater(arr, n) << endl;
}
