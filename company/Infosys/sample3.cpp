#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n;
    cin >> n;
    long a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    int max = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1] && ((a[i] & a[i + 1]) * 2 < (a[i] | a[i + 1])))
        {
             // cout << a[i] << " " << a[i + 1] << endl;
            count += 1;
            if (count > max)
            {
                max = count;
            }
        }
        else
        {
            count = 0;
        }
    }
    cout << max + 1 << endl;
    return 0;
}