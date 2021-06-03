// question link: https://leetcode.com/problems/roman-to-integer/

#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
    int last = roman[s[s.length() - 1]];

    for (int i = s.length() - 2; i >= 0; i--)
    {
        if (roman[s[i]] < roman[s[i + 1]])
        {
            last = last - roman[s[i]];
        }
        else
        {
            last = last + roman[s[i]];
        }
    }
    return last;
}

int main()
{
    string n = "LVIII";
    cout << romanToInt(n) << endl;
    return 0;
}
