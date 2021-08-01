#include <bits/stdc++.h>
using namespace std;

int minProductSubset(int a[], int n)
{
    if (n == 0)
        return 0;

    int min_pos = INT_MAX;
    int ct_neg;
    int ct_zero;
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
        if (a[i] > 0)
        {
            min_pos = min(min_pos, a[i]);
        }
        prod = prod * a[i];
    }
    if (ct_zero == n || (ct_neg == 0 && ct_zero > 0))
    {
        return 0;
    }
    if (ct_neg == 0 && ct_zero == 0)
    {
        return min_pos;
    }
    if (!(ct_neg & 1) && ct_neg != 0) // even check
    {
        prod = prod / max_neg;
    }
    return prod;
}

int main()
{
    int a[] = {-1, -1, -2, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);
    cout << minProductSubset(a, n);
    return 0;
}
