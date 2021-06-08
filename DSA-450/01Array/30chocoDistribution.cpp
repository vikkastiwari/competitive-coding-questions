// question link: https://www.geeksforgeeks.org/chocolate-distribution-problem/

#include <bits/stdc++.h>
using namespace std;

/* 
First Approach
Time Complexity = O(N^2)
Space Complexity = O(N)
*/

int chocoDistribution(vector<int> pack, int studs)
{
    int n = pack.size();
    vector<int> itr;
    vector<int> minDiff;

    if (pack.size() == 0 || studs == 0)
        return 0;

    if (studs > pack.size())
        return -1;

    sort(pack.begin(), pack.end());

    for (int i = 0; i < n; i++)
    {
        int start = pack[i];
        if ((n - i) >= studs)
        {
            for (int j = i; j < i + studs; j++)
            {
                itr.push_back(pack[j]);
            }
            minDiff.push_back((*max_element(itr.begin(), itr.end())) - (*min_element(itr.begin(), itr.end())));
            itr.clear();
        }
    }

    return *min_element(minDiff.begin(), minDiff.end());
}

/*
Second optimal Approach 
Time Complexity = O(NLogN)
Space Complexity = O(1)
*/

int chocoDistribution2(vector<int> pack, int studs)
{
    if (pack.size() == 0 || studs == 0)
        return 0;

    if (studs > pack.size())
        return -1;

    sort(pack.begin(), pack.end());

    int minDiff = INT_MAX;

    for (int i = 0; i + studs - 1 < pack.size(); i++)
    {
        int diff = pack[i + studs - 1] - pack[i]; // subarray of size studs
        if (diff < minDiff)
        {
            minDiff = diff;
        }
    }
    return minDiff;
}

int main()
{
    vector<int> pack = {12, 4, 7, 9, 2, 23, 25, 41, 30,
                        40, 28, 42, 30, 44, 48, 43, 50};
    int studs = 7;
    cout << chocoDistribution2(pack, studs) << endl;
    return 0;
}