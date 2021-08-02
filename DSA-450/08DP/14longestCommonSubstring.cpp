// longest common substring
// eg: abds , abcd -> o/p: 2

#include <bits/stdc++.h>
using namespace std;

// Top-Down approach DP
int substring(string s1, string s2, int n, int m)
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
                t[i][j] = 0;
            }
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m + 1; j++)
            ans = max(ans, t[i][j]);

    return ans;
}

int main()
{
    string s1 = "vikas", s2 = "viksa";
    cout << substring(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}