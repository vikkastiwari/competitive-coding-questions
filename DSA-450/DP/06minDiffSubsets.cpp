#include <bits/stdc++.h>
using namespace std;

vector<int> subsetSum(int a[], int sum, int n)
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
            if (a[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - a[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    vector<int> possibilities;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == n and t[i][j] == true)
            {
                possibilities.push_back(j);
            }
        }
    }

    return possibilities;
}

int minDiffSubset(int a[], int n)
{

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    vector<int> sets = subsetSum(a, sum, n);
    for (int i = 0; i < sets.size(); i++)
    {
        cout << sets[i] << " ";
    }
    cout << endl;

    int minDiff = INT_MAX;
    for (int i = 0; i < sets.size(); i++)
    {
        minDiff = min(minDiff, abs(sum - 2 * sets[i]));
    }
    return minDiff;
}

int main()
{
    int w[] = {1, 2, 7};
    int n = sizeof(w) / sizeof(w[0]);
    cout << minDiffSubset(w, n) << endl;
    return 0;
}