#include <bits/stdc++.h>
using namespace std;

// int MaxSumDifference(int a[], int n)
// {
//     sort(a, a + n);
//     vector<int> seq;
//     for (int i = 0; i < n / 2; i++)
//     {
//         seq.push_back(a[i]);
//         seq.push_back(a[n - i - 1]);
//     }
//     if (n % 2 != 0)
//     {
//         seq.push_back(a[n / 2]);
//     }

//     int maxSum = 0;
//     for (int i = 0; i < seq.size() - 1; i++)
//     {
//         maxSum += abs(seq[i + 1] - seq[i]);
//     }
//     maxSum += abs(seq[n - 1] - seq[0]);

//     return maxSum;
// }

int MaxSumDifference(int a[], int n)
{
    sort(a, a + n);
    int maxSum = 0;
    for (int i = 0; i < n / 2; i++)
    {
        maxSum -= (2 * a[i]);
        maxSum += (2 * (a[n - i - 1]));
    }

    return maxSum;
}

int main()
{
    int a[] = {1, 2, 4, 8};
    int n = sizeof(a) / sizeof(a[0]);

    cout << MaxSumDifference(a, n) << endl;
    return 0;
}