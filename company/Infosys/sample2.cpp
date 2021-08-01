#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n;
    cin >> n;
    long k;
    cin >> k;

    vector<vector<long>> pairs;
    int j = 0;
    set<int> temp;
    for (long i = 1; i <= n; i++)
    {
        temp.insert(i);
    }

    // for (long i = 0; i < pairs.size(); i++)
    // {
    //     for (long j = 0; j < pairs[i].size(); j++)
    //     {
    //         cout << pairs[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    long count = 0;
    for (long i = 0; i < pairs.size(); i++)
    {
        if (pairs[i][1] % pairs[i][0] == 0)
        {
            count++;
        }
    }
    cout << count % 10000 << endl;
    return 0;
}