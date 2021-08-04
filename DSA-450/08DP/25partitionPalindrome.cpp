#include <bits/stdc++.h>
using namespace std;

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

    int temp, ans;
    for (int k = i; k < j; k++)
    {
        temp = partitionPalin(s, i, k) + partitionPalin(s, k + 1, j) + 1;
        ans = min(ans, temp);
    }
    return ans;
}

int main()
{
    string s = "nitin";
    int i = 0, j = s.length() - 1;
    cout << partitionPalin(s, i, j) << endl;
    return 0;
}