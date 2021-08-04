// Minimum number of deletion in a string to make it palindrome
// OR
//  Minimum Insertion Steps to Make a String Palindrome
#include <bits/stdc++.h>
using namespace std;

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

int minNumberOfDeletion(string s1)
{
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    int lps = LCS(s1, s2, s1.length(), s2.length());
    // it will give us min number of insertion or deletion to make the string palindrome
    return s1.length() - lps;
}

int main()
{
    string s1 = "leetcode";
    cout << minNumberOfDeletion(s1) << endl;
    return 0;
}