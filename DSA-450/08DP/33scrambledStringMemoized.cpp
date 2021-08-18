#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

bool solve(string x, string y)
{
    string key = x + " " + y;

    if (x.length() != y.length()) // we wont store this coz if the length is only not same then it is never going to be the scrambled string
        return false;

    if (mp.find(key) != mp.end())
        return mp[key];

    if (x.compare(y) == 0)
    {
        mp[key] = true;
        return true;
    }
    if (x.length() <= 1)
    {
        mp[key] = false;
        return false;
    }

    int n = x.length();
    int flag = false;
    for (int i = 1; i <= n - 1; i++)
    {
        // substr(start,len)
        bool cond1 = (solve(x.substr(0, i), y.substr(n - i, i))) && (solve(x.substr(i), y.substr(0, n - i)));

        bool cond2 = (solve(x.substr(0, i), y.substr(0, i))) && (solve(x.substr(i, n - i), y.substr(i, n - i)));

        if (cond1 || cond2)
        {
            flag = true;
            break;
        }
    }
    return mp[key] = flag;
}

int main()
{
    string x = "great", y = "eatrg";
    cout << solve(x, y) << endl;
    return 0;
}