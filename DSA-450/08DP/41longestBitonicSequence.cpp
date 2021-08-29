#include <bits/stdc++.h>
using namespace std;

int lbs(vector<int> arr, int n)
{
    int i, j;

    int *lis = new int[n];
    for (i = 0; i < n; i++)
        lis[i] = 1;

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    int *lds = new int[n];
    for (i = 0; i < n; i++)
        lds[i] = 1;

    for (i = n - 2; i >= 0; i--)
        for (j = n - 1; j > i; j--)
            if (arr[i] > arr[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, lis[i] + lds[i] - 1);

    return ans;
}

// LBS
int longestSubsequenceLength(const vector<int> &A)
{
    int ans = lbs(A, A.size());
    return ans;
}

int main()
{
    vector<int> A = {1, 11, 2, 10, 4, 5, 2, 1};
    cout << longestSubsequenceLength(A) << endl;
    return 0;
}