// question link: https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#

#include <bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int sum)
{
    // code here
    int low = 0, high = n - 1;
    int count = 0;
    sort(arr, arr + n);
    while (low < high)
    {
        if (arr[low] + arr[high] == sum)
        {
            count++;
        }
        if (arr[low] + arr[high] > sum)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sum;
        cin >> sum;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans = getPairsCount(arr, n, sum);
        cout << ans << endl;
    }
}