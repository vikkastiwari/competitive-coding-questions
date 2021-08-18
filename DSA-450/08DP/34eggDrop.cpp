#include <bits/stdc++.h>
using namespace std;

int solve(int e, int f)
{
    if (f == 0 || f == 1)
        return f;
    if (e == 1) // when e=1 in worst case we will traverse from 1 to f;
        return f;

    int ans = INT_MAX;
    for (int i = 1; i <= f; i++)
    {
        int temp = 1 + max(solve(e - 1, i - 1), solve(e, f - i)); // we are taking max coz we want the worst possibilty to be handled efficiently

        ans = min(ans, temp);
    }
    return ans;
}

int main()
{
    int f, e;
    // cin >> f >> e;
    f = 5, e = 3; // op = 3
    cout << solve(e, f);
    return 0;
}