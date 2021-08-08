#include <bits/stdc++.h>
using namespace std;
#define N 1001

int MaximumPath(int Mat[][N])
{
    int result = 0;
    int dp[N][N + 2];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < N; i++)
        dp[0][i + 1] = Mat[0][i];

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dp[i][j] = max(dp[i - 1][j - 1],
                           max(dp[i - 1][j],
                               dp[i - 1][j + 1])) +
                       Mat[i][j - 1];
        }
    }

    for (int i = 0; i <= N; i++)
        result = max(result, dp[N - 1][i]);

    return result;
}

int main()
{
    int Mat[N][N] = {{1, 1},
                     {2, 2},
                     {3, 3}};

    cout << MaximumPath(Mat) << endl;
    return 0;
}
