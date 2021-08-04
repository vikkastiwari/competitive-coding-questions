#include <bits/stdc++.h>
using namespace std;
// define s based on constraint given
#define s 1000

int t[s + 1][s + 1];

int Solve(int arr[], int i, int j)
{
    if (i >= j)
    {
        t[i][j] = 0;
        return 0;
    }

    if (t[i][j] != -1)
        return t[i][j];

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp_ans = Solve(arr, i, k) + Solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        // g1 - first solve call
        // g2 - second solve call
        // arr[i - 1] * arr[k] * arr[j] for g1 and g2 multiplication
        ans = min(ans, temp_ans);
    }

    return t[i][j] = ans;
}

signed main()
{
    int n = 5;
    int arr[] = {40, 20, 30, 10, 30};
    memset(t, -1, sizeof(t));

    cout << Solve(arr, 1, n - 1) << endl;
    return 0;
}