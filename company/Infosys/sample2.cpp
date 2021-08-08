#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     long n;
//     cin >> n;
//     long k;
//     cin >> k;
//     vector<vector<long>> pairs;
//     int j = 0;
//     set<int> temp;
//     for (long i = 1; i <= n; i++)
//     {
//         temp.insert(i);
//     }

//     // for (long i = 0; i < pairs.size(); i++)
//     // {
//     //     for (long j = 0; j < pairs[i].size(); j++)
//     //     {
//     //         cout << pairs[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }

//     long count = 0;
//     for (long i = 0; i < pairs.size(); i++)
//     {
//         if (pairs[i][1] % pairs[i][0] == 0)
//         {
//             count++;
//         }
//     }
//     cout << count % 10000 << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int getMaxNumberOfWays(int coins[], int n, int sum)
{
    int t[n + 1][sum + 1];
    // initialization
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum; j++)
            if (coins[i - 1] <= j)
                t[i][j] = t[i - 1][j] + t[i][j - coins[i - 1]];
            else
                t[i][j] = t[i - 1][j];

    return t[n][sum];
}

signed main()
{
    int n, k;
    cin >> n >> k;
    int coins[n];
    for (int i = 0; i < n; i++)
        coins[i] = i;

    cout << getMaxNumberOfWays(coins, n, k) << endl;
    return 0;
}