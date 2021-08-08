#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll m = 1e9 + 7;

int maxKill(int power[], int bonus[], int e, int n)
{
    vector<pair<int, int>> mons;
    for (int i = 0; i < n; i++)
    {
        mons.push_back(make_pair(power[i], bonus[i]));
    }
    // for (auto i = 0; i < n; i++)
    // {
    //     cout << mons[i].first << " " << mons[i].second << endl;
    // }
    sort(mons.begin(), mons.end());
    int killed = 0;
    for (auto i = 0; i < n; i++)
    {
        if (mons[i].first <= e)
        {
            killed++;
            e += mons[i].second;
        }
    }
    return killed;
}

int main()
{
    int n;
    cin >> n;
    int e;
    cin >> e;
    int power[n];
    for (int i = 0; i < n; i++)
    {
        cin >> power[i];
    }
    int bonus[n];
    for (int i = 0; i < n; i++)
    {
        cin >> bonus[i];
    }
    int ans = maxKill(power, bonus, e, n);
    cout << ans << endl;
    return 0;
}