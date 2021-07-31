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

int diffSubset(int a[], int diff, int n)
{
    int tsum = 0;
    for (int i = 0; i < n; i++)
    {
        tsum += a[i];
    }
    // mathematical equation
    // in one of our subset the sum of all the elements is always going to be s1
    int s1 = (tsum + diff) / 2; // equation from s1-s2=diff & s1+s2=tsum
    int ans = subsetSum(a, s1, n);
    return ans;
}

int main()
{
    int w[] = {0, 0, 0, 0, 0, 0, 0, 0, 1};
    int n = sizeof(w) / sizeof(w[0]);
    int diff = 1;
    cout << diffSubset(w, diff, n) << endl;
    return 0;
}