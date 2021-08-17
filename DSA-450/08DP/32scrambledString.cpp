#include <bits/stdc++.h>
using namespace std;

bool solve(string x, string y)
{
    if (x.length() != y.length())
        return false;
    if (x.compare(y) == 0)
        return true;
    if (x.length() <= 1)
        return false;

    int n = x.length();
    for (int i = 1; i <= n - 1; i++)
    {
        bool cond1 = (solve(x.substr(0, i), y.substr(n - i, i))) && (solve(x.substr(i, n - i), y.substr(0, n - i)));

        bool cond2 = (solve(x.substr(0, i), y.substr(0, i))) && (solve(x.substr(i, n - i), y.substr(i, n - i)));

        if (cond1 || cond2)
            return true;
    }
    return false;
}

int main()
{
    string x = "great", y = "eatrg";
    cout << solve(x, y) << endl;
    return 0;
}