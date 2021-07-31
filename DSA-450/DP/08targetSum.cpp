#include <bits/stdc++.h>
using namespace std;

int subsetSum(int a[], int n, int sum)
{

    int dp[n + 1][sum + 1];

    //initialization
    for (int i = 0; i < sum + 1; i++)
        dp[0][i] = 0;

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {

            if (a[i - 1] == 0)
                dp[i][j] = dp[i - 1][j];

            else if (a[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];

            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int findTargetSumWays(int a[], int target, int n)
{

    int sum = 0;
    int num_zero = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (a[i] == 0)
            num_zero++;
    }

    if (sum < target || (sum + target) % 2 == 1)
        return 0;

    int ans = subsetSum(a, n, (sum + target) / 2);
    return pow(2, num_zero) * ans;
}

int main()
{

    int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int target = 1; // diff
    cout << findTargetSumWays(a, target, n) << endl;
    return 0;
}