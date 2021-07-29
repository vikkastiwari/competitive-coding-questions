#include <bits/stdc++.h>
using namespace std;

int subsetSum(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    if (sum % 2 != 0)
    {
        return false;
    }
    sum /= 2;

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

    if (t[n][sum])
        return true;

    return false;
}

int main()
{
    int w[] = {1, 5, 5, 11, 3, 3};
    int n = sizeof(w) / sizeof(w[0]);
    cout << subsetSum(w, n) << endl;
    return 0;
}