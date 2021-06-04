// question link: https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1#

#include <bits/stdc++.h>
using namespace std;

long long maxProduct(int *arr, int n)
{
    long long max, min, prod;
    max = min = prod = arr[0];

    for (int i = 1; i < n; i++)
    {
        // we are swapping because when we multiply small -ve number (-18 < -2)
        // with minimal possible -ve value from given array we get maximum product
        if (arr[i] < 0)
        {
            swap(min, max);
        }

        min = std::min((long long)arr[i], min * arr[i]);
        max = std::max((long long)arr[i], max * arr[i]);

        if (max > prod)
            prod = max;
    }

    return prod;
}

int main()
{
    int n = 4;
    int arr[] = {6, -3, -10, 2};
    cout << maxProduct(arr, n) << endl;
    return 0;
}
