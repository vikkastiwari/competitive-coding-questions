// question link: https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/

#include <bits/stdc++.h>
using namespace std;

void palin(string s)
{
    int n = s.length();
    bool table[n][n];
    memset(table, 0, sizeof(table)); // table filled with 0 upto n*n
    int maxLen = 1;                  // hence all substrings with len 1 are palindrome

    for (int i = 0; i < n; i++)
    {
        table[i][i] = true;
    }

    // checking for substring of length 2
    int start = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            start = i;
            table[i][i + 1] = true;
            maxLen = 2;
        }
    }

    // for length greater than 2
    for (int k = 3; k <= n; k++)
    {
        // starting index for palin length > 2
        for (int i = 0; i < n - k + 1; i++)
        {
            // end index of substring
            int end = k + i - 1;

            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome

            if (table[i + 1][end - 1] && s[i] == s[end])
            {
                table[i][end] = true;
                if (k > maxLen)
                {
                    // to print the long palin we take i in start
                    start = i;
                    maxLen = k;
                }
            }
        }
    }
    for (int i = start; i <= start + maxLen - 1; i++)
    {
        cout << s[i] << "";
    }
}

int main()
{
    string s = "vikassakiv";
    palin(s);
    return 0;
}
