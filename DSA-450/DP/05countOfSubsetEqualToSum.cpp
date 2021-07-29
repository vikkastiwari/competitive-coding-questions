#include <bits/stdc++.h>
using namespace std;

int subsetSum(int a[], int sum, int n)
{
    int t[n + 1][sum + 1];

    // Initialization
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
            {
                t[i][j] = 1;
            }
            if (j != 0 and i == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    // i is n and j is sum
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (a[i - 1] <= j)
            {
                // sum because we have to count total possibilities
                t[i][j] = t[i - 1][j - a[i - 1]] + t[i - 1][j];
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
    int w[] = {2, 3, 5, 6, 8, 10};
    int n = sizeof(w) / sizeof(w[0]);
    int sum = 10;
    cout << subsetSum(w, sum, n);
    return 0;
}