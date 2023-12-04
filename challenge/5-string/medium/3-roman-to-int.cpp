#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Roman to Integer
 * 
 * @param s 
 * @return * int 
 */
int romanToInt(string s)
{
    unordered_map<char, int> m;

    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (m[s[i]] < m[s[i + 1]])
        {
            res -= m[s[i]];
        }
        else
        {
            res += m[s[i]];
        }
    }
    return res;
}

int main()
{
    string s = "MCMXCIV";
    int res = romanToInt(s);
    cout << res << endl;
    return 0;
}