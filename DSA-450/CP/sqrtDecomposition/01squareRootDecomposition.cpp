#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 2, mod = 1e9 + 7;

signed main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int len = sqrtl(n) + 1;
    vector<int> b(len); // for precomputation - we will store sum of intervals based on len calculated

    for (int i = 0; i < n; i++)
    {
        b[i / len] += v[i];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--; // zero based indexing

        int sum = 0;
        for (int i = l; i <= r;)
        {
            if (i % len == 0 && i + len - 1 <= r)
            {
                sum += b[i / len];
                i += len;
            }
            else
            {
                sum += v[i];
                i++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}