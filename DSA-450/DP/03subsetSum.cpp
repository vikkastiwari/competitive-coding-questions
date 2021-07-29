#include <bits/stdc++.h>
using namespace std;

int subsetSum(int a[], int sum, int n)
{
    bool t[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
            {
                t[i][j] = true;
            }
            if (j != 0 and i == 0)
            {
                t[i][j] = false;
            }
        }
    }

    // i is n and j is sum
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (a[i - 1] <= sum)
            {
                t[i][j] = t[i - 1][j - a[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum];
}

int main()
{
    int w[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(w) / sizeof(w[0]);
    int sum = 9;
    cout << subsetSum(w, sum, n);
    return 0;
}