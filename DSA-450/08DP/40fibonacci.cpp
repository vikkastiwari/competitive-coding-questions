#include <bits/stdc++.h>
using namespace std;

int t[1001];

//memoization - bottom-up approach
// int fibo(int n)
// {
//     if (n == 0 || n == 1)
//         return n;

//     if (t[n] != -1)
//         return t[n];

//     return t[n] = fibo(n - 1) + fibo(n - 2);
// }

// tabulation - top-down approach
int fibo(int n)
{
    if (n == 0 || n == 1)
        return n;

    t[0] = 0;
    t[1] = 1;

    for (int i = 2; i < n + 1; i++)
    {
        t[i] = t[i - 1] + t[i - 2];
    }
    return t[n];
}

int main()
{
    int n = 12;
    // memset(t, -1, sizeof(t)); // for bottom up approach
    for (int i = 0; i < n; i++)
    {
        cout << fibo(i) << endl;
    }
    return 0;
}