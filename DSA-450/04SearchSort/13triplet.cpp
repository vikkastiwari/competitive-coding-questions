// question link: https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1#

#include <bits/stdc++.h>
using namespace std;

long long countTriplets(long long arr[], int n, long long sum)
{
    // Your code goes here
    int count = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1;
        int h = n - 1;

        while (l < h)
        {
            if (arr[i] + arr[l] + arr[h] >= sum)
            {
                h--;
            }
            else if (arr[i] + arr[l] + arr[h] < sum)
            {
                // counting total combinations when sum is less than given value
                count += (h - l);
                l++;
            }
        }
    }
    return count;
}

// Driver program
int main()
{
    long long arr[] = {5, 1, 3, 4, 7};
    int n = sizeof arr / sizeof arr[0];
    int sum = 12;
    cout << countTriplets(arr, n, sum) << endl;
    return 0;
}
