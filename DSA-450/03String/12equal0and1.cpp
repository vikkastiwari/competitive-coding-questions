// question link: https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/

#include <bits/stdc++.h>
using namespace std;

int count(string s)
{
    int c1 = 0, c2 = 0, ct = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            c1++;
        }
        else
        {
            c2++;
        }
        if (c1 == c2)
        {
            ct++;
        }
    }
    if (ct == 0)
        return 0;
    return ct;
}

int main()
{
    string s = "1010010100";
    cout << count(s) << endl;
    return 0;
}
