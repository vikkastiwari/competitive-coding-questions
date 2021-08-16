// https://www.interviewbit.com/problems/jump-game-array/
#include <bits/stdc++.h>
using namespace std;

int canJump(vector<int> &A)
{
    int n = A.size();
    int ct = A[0], i = 0;

    if (ct >= n - 1)
        return 1;
    while (i <= ct)
    {
        ct = max(ct, i + A[i]);
        if (ct >= n - 1)
            return 1;
        i++;
    }
    return 0;
}
int main()
{
    vector<int> v = {2, 3, 1, 1, 4};
    cout << canJump(v) << endl;
    return 0;
}