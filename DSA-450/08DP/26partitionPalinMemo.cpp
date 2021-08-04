#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];

bool isPallindrome(string X, int i, int j)
{
    while (i <= j)
    {
        if (X[i] != X[j])
            return false;
        i++, j--;
    }

    return true;
}

int partitionPalin(string s, int i, int j)
{
    if (i >= j || isPallindrome(s, i, j))
        return 0;

    if (t[i][j] != -1)
        return t[i][j];

    int temp, ans=INT_MAX;
    for (int k = i; k < j; k++)
    {
        temp = partitionPalin(s, i, k) + partitionPalin(s, k + 1, j) + 1;
        ans = min(ans, temp);
    }
    return t[i][j] = ans;
}

int main()
{
    string s = "nitik";
    int i = 0, j = s.length() - 1;
    memset(t, -1, sizeof(t));
    cout << partitionPalin(s, i, j) << endl;
    return 0;
}