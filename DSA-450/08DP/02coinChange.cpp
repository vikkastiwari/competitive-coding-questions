#include <bits/stdc++.h>
using namespace std;
// unbounded knapsack
int coinChange(int a[], int k, int n)
{
    int t[n + 1][k + 1];
    // memset(t, 0, sizeof(t));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < k + 1; j++)
        {
            if (i == 0 and j != 0)
            {
                t[i][j] = 0;
            }
            if (j == 0)
            {
                t[i][j] = 1;
            }
        }
    }

    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < k + 1; j++)
    //     {
    //         cout << t[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // i is n and j in M
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < k + 1; j++)
        {
            if (a[i - 1] > k)
            {
                t[i][j] = t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j - a[i - 1]] + t[i - 1][j];
            }
        }
    }

    return t[n][k];
}

int main()
{
    int a[] = {1, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 7;
    cout << coinChange(a, k, n);
    return 0;
}