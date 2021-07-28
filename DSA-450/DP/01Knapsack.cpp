#include <bits/stdc++.h>
using namespace std;

// 01 knapsack

int knapsack(int w[], int v[], int m, int n)
{
    int t[n + 1][m + 1];
    memset(t, 0, sizeof(t));

    // i is n and j in M
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (w[i - 1] > m)
            {
                return t[i][j] = t[i - 1][j];
            }
            else
            {
                t[i][j] = max(v[n - 1] + t[i - 1][j - w[i - 1]], t[i - 1][j]);
            }
        }
    }

    //
    return t[n][m];
}

int main()
{
    int w[] = {10, 20, 30};
    int v[] = {60, 100, 120};
    int n = sizeof(v) / sizeof(v[0]);
    int m = 50; // size of bag
    cout << knapsack(w, v, m, n);
    return 0;
}