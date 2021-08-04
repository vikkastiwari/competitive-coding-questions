// longest common subsequence
#include <bits/stdc++.h>
using namespace std;

// recursive function
// int LCS(string s1, string s2, int n, int m)
// {
//     if (n == 0 || m == 0)
//         return 0;
//     else
//     {
//         if (s1[n - 1] == s2[m - 1])
//         {
//             return 1 + LCS(s1, s2, n - 1, m - 1);
//         }
//         else
//         {
//             return max(LCS(s1, s2, n, m - 1), LCS(s1, s2, n - 1, m));
//         }
//     }
//     return 0;
// }

// memoization - bottom up approach
// int LCS(string s1, string s2, int n, int m)
// {

//     int t[n + 1][m + 1]; // dont initialize it here
//     memset(t, -1, sizeof(t));
//     if (n == 0 || m == 0)
//         return 0;
//     if (t[n][m] != -1)
//         return t[n][m];
//     else
//     {
//         if (s1[n - 1] == s2[m - 1])
//         {
//             return t[n][m] = 1 + LCS(s1, s2, n - 1, m - 1);
//         }
//         else
//         {
//             return t[n][m] = max(LCS(s1, s2, n, m - 1), LCS(s1, s2, n - 1, m));
//         }
//     }
//     return 0;
// }

// Top-Down approach DP
int LCS(string s1, string s2, int n, int m)
{

    int t[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    return t[n][m];
}

int main()
{
    string s1 = "vikas", s2 = "viksa";
    cout << LCS(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}