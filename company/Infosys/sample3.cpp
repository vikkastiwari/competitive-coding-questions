#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll m = 1e9 + 7;

int lis(int arr[], int n)
{
    int lis[n];

    lis[0] = 1;

    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1 && (arr[i] & arr[j]) * 2 < arr[i] | arr[j])
                lis[i] = lis[j] + 1;
    }

    return *max_element(lis, lis + n);
}

int main()
{
    // int arr[] = {15, 6, 5, 12, 1};
    // int arr[] = {9, 17, 2, 15, 5, 2};
    int arr[] = {17, 16, 12, 2, 8, 17, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << lis(arr, n) << endl;
    return 0;
}
