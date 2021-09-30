#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 2, mod = 1e9 + 7;

// https://www.spoj.com/problems/RMQSQ/

/*
i/p -
3
1 4 1
2
1 1
1 2

o/p-
4
1
*/

signed main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int len = (int)sqrtl(n) + 1; // convert len to ceil value
    vector<int> b(len, mod);     // for precomputation - we will store sum of intervals based on len calculated

    for (int i = 0; i < n; i++)
    {
        b[i / len] = min(b[i / len], v[i]);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int ans = mod;
        for (int i = l; i <= r;)
        {
            // considering min from precomputed values
            if (i % len == 0 && i + len - 1 <= r)
            {
                ans = min(ans, b[i / len]);
                i += len;
            }
            else // considering values paritially from array for min in given range
            {
                ans = min(ans, v[i]);
                i++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
