#include <bits/stdc++.h>
using namespace std;

int getMaxProfit(int wt[], int val[], int n, int W)
{
    int t[n + 1][W + 1];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < W + 1; j++)
            if (j == 0 || i == 0)
                t[i][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(t[i - 1][j],
                              val[i - 1] + t[i][j - wt[i - 1]]);
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][W];
}

signed main()
{
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val) / sizeof(val[0]);

    cout << getMaxProfit(wt, val, n, W) << endl;
    return 0;
}