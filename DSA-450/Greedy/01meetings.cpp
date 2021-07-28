// Link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#

#include <bits/stdc++.h>
using namespace std;

int fn(const pair<int, int> &x, const pair<int, int> &y)
{
    if (x.second != y.second)
    {
        return x.second < y.second;
    }

    return x.first < y.first;
}

int maxMeetings(int s[], int e[], int n)
{
    // Your code here
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(make_pair(s[i], e[i]));
    }

    // for (auto i = 0; i < n; i++)
    // {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }

    sort(v.begin(), v.end(), fn);

    int i = 0, j;
    int count = 1;
    for (auto j = 1; j < n; j++)
    {
        if (v[j].first >= v[i].second)
        {
            count++;
            i = j;
        }
    }
    return count;
}

int main()
{
    int n = 8;
    // int start[n] = {1, 3, 0, 5, 8, 5};
    // int end[n] = {2, 4, 6, 7, 9, 9};

    int start[n] = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924};
    int end[n] = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252};

    int ans = maxMeetings(start, end, n);
    cout << ans << endl;
    return 0;
}