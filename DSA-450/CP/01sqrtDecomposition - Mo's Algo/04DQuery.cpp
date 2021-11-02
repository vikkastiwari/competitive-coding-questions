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
    if (q1.left / rootN == q2.left / rootN)
        return q1.right > q2.right;
    return q1.left < q2.left;
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
    // curr_l at start , curr_r at end
    int curr_l = 0, curr_r = -1, l, r; // l, r indicates range of each query
    int res = 0;
    vector<int> freq(10 * N, 0); // frequency

    for (int i = 0; i < queries; i++)
    {
        l = q[i].left;
        r = q[i].right;
        l--; // converting to zero based indexing
        r--; // converting to zero based indexing

        // Four conditions
        while (curr_r < r)
        {
            curr_r++;                   // moving forward to include element's that falls in range from l to r
            freq[arr[curr_r]]++;        // adding distinct elelment's count
            if (freq[arr[curr_r]] == 1) // updating to 1 when distinct element is found
                res++;                  // add that element from count too
        }

        while (curr_l > l)
        {
            curr_l--;                   // move backward to include element from given l
            freq[arr[curr_l]]++;        // adding distinct element's count
            if (freq[arr[curr_l]] == 1) // updating to 1 when distinct element is found
                res++;                  // add that element from count too
        }

        while (curr_l < l)
        {
            freq[arr[curr_l]]--;        // removing element from range as it is not in range
            curr_l++;                   // moving forward
            if (freq[arr[curr_l]] == 0) // updating to 0 when distinct element is vanished from range
                res--;                  // remove that element from count too
        }

        while (curr_r > r)
        {
            freq[arr[curr_r]]--;        // removing frequency of current element as it is greater than r
            curr_r--;                   // decrement the counter
            if (freq[arr[curr_r]] == 0) // if the frequency of that element becomes zero than that element is vanished
                res--;                  // remove that element from count too
        }
        ans[q[i].index] = res; // adding our result in ans array
    }

    for (int i = 0; i < queries; i++)
        cout << ans[i] << endl;

    return 0;
}