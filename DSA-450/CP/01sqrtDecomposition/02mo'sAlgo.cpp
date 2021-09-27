#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 2;
const ll mod = 1e9 + 7;
int rootN;

struct Q
{
    int index, left, right;
};

Q q[N]; // define array q with Q struct

bool compare(Q q1, Q q2)
{
    if (q1.left / rootN == q2.right / rootN)
        return q1.right > q2.right;
    return q1.left / rootN < q2.left / rootN;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    rootN = sqrtl(n);
    int queries;
    cin >> queries;
    for (int i = 0; i < queries; i++)
    {
        int l, r;
        cin >> l >> r;
        q[i].left = l;
        q[i].right = r;
        q[i].index = i;
    }

    sort(q, q + queries, compare);

    vector<int> ans(queries);
    int curr_l = 0, curr_r = -1, l, r; // l, r indicates range of each query
    int res = 0;
    for (int i = 0; i < queries; i++)
    {
        l = q[i].left;
        r = q[i].right;
        l--;
        r--;

        // Four conditions
        while (curr_r < r)
        {
            curr_r++;
            res += arr[curr_r];
        }

        while (curr_l > l)
        {
            curr_l--;
            res += arr[curr_l];
        }

        while (curr_l < l)
        {
            res -= arr[curr_l];
            curr_l++;
        }

        while (curr_r > r)
        {
            res -= arr[curr_r];
            curr_r--;
        }
        ans[q[i].index] = res;
    }

    for (int i = 0; i < queries; i++)
        cout << ans[i] << endl;

    return 0;
}