#include <bits/stdc++.h>
using namespace std;

long long int maximizeSum(long long int a[], int n, int k)
{
    // Your code goes here
    sort(a, a + n);

    long long int sum = 0;
    long long int ct_zero = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            ct_zero++;
    }

    if (ct_zero == n)
        return 0;

    long long int op = k;

    for (long long int i = 0; i < n; i++)
    { // remove neg and reduce negations
        if (op > 0 && a[i] < 0)
        {
            a[i] = -a[i];
            op--;
        }
    }

    sort(a, a + n);

    if ((op > 0) and op % 2 != 0)
    {
        a[0] = -a[0];
    }

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    return sum;
}

int main()
{
    int N = 5, K = 1;
    long long int arr[] = {1, 2, -3, 4, 5};
    cout << maximizeSum(arr, N, K);
    return 0;
}