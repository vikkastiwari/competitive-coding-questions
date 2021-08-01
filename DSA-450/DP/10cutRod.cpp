#include <bits/stdc++.h>
using namespace std;

int getMaxProfit(int length[], int price[], int n, int L)
{
    int t[n + 1][L + 1];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < L + 1; j++)
            if (j == 0 || i == 0)
                t[i][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < L + 1; j++)
        {
            if (length[i - 1] <= j)
            {
                t[i][j] = max(t[i - 1][j],
                              price[i - 1] + t[i][j - length[i - 1]]);
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][L];
}

signed main()
{
    int L = 100;
    int price[] = {10, 30, 20};
    int length[] = {5, 10, 15};
    int n = sizeof(price) / sizeof(price[0]);

    cout << getMaxProfit(length, price, n, L) << endl;
    return 0;
}