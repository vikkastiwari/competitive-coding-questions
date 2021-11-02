#include <bits/stdc++.h>
using namespace std;

int maximumSumSubarray(int K, vector<int> &arr)
{
    int N = arr.size();
    int i = 0;
    int j = 0;
    int sum = 0;
    int mx = INT_MIN;
    while (j < N)
    {
        sum = sum + arr[j]; // we are adding next element in the sum as we removed first element in elseif block

        if (j - i + 1 < K)
            j++; // increament j until the size of the window is not equal to k

        else if ((j - i + 1) == K) // when window size hit to the required window size (k)
        {
            mx = max(mx, sum);  // selecting max of mx and sum
            sum = sum - arr[i]; // removing first elements value from the sum
            i++;
            j++;
        }
    }
    return mx;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 3;
    int ans = maximumSumSubarray(k, arr);
    cout << ans << endl;
    return 0;
}