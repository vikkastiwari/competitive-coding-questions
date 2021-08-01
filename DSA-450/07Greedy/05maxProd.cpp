#include <bits/stdc++.h>
using namespace std;

int minProductSubset(int a[], int n)
{
    if (n == 0)
        return 0;

    int ct_neg = 0;
    int ct_zero = 0;
    int max_neg = INT_MIN;
    int prod = 1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            ct_zero++;
            continue;
        }
        if (a[i] < 0)
        {
            max_neg = max(max_neg, a[i]);
            ct_neg++;
        }
        prod = prod * a[i];
    }
    // cout << prod << endl;
    if (ct_zero == n)
    {
        return 0;
    }
    if (ct_neg & 1) // odd check
    {
        if (ct_neg == 1 && ct_zero > 0 && (ct_zero + ct_neg == n))
            return 0;
        prod = prod / max_neg;
    }
    return prod;
}

int main()
{
    int a[] = {-5, 0, 0, 0};
    int n = sizeof(a) / sizeof(a[0]);
    cout << minProductSubset(a, n);
    return 0;
}
