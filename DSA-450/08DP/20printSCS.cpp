// longest common subsequence
#include <bits/stdc++.h>
using namespace std;

// Top-Down approach DP
string LCS(string s1, string s2, int n, int m)
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
    int i = n, j = m;
    string s="";
    while (i > 0 && j > 0)
    {
        // at each comparison in back track we are adding results to our string s
        if (s1[i - 1] == s2[j - 1])
        {
            s.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (t[i - 1][j] > t[i][j - 1])
            {
                s.push_back(s1[i - 1]);
                i--;
            }
            else
            {
                s.push_back(s2[j - 1]);
                j--;
            }
        }
    }
    while (i > 0)
    {
        s.push_back(s1[i - 1]);
        i--;
    }
    while (j > 0)
    {
        s.push_back(s2[j - 1]);
        j--;
    }
    reverse(s.begin(), s.end());
    return s;
}

string printSuperSequence(string s1, string s2)
{
    string scs = LCS(s1, s2, s1.length(), s2.length());
    return scs;
}

int main()
{
    string s1 = "aggtab", s2 = "gxtxayb";
    cout << printSuperSequence(s1, s2) << endl;
    return 0;
}