#include <bits/stdc++.h>
using namespace std;

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

int patterMatching(string s1, string s2, int n, int m)
{
    int lcs = LCS(s1, s2, s1.length(), s2.length());
    if (lcs == s1.length())
    {
        return true;
    }
    return false;
}

int main()
{
    string s1 = "AXY", s2 = "AXDCYB";
    // to check whether s1 is substring of s2 or not
    cout << patterMatching(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}