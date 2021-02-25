#include <bits/stdc++.h>
#define ll long long
using namespace std;

void announce_winner(vector<string> &votes)
{
    map<string, int> mapObj;
    for (auto &str : votes)
    {
        mapObj[str]++;
    }
    int maxVal = 0;
    string winner;
    for (auto &entry : mapObj)
    {
        string key = entry.first;
        int val = entry.second;
        // cout << "key:" << key << ' ' << "Value:" << val << endl;
        if (val > maxVal)
        {
            maxVal = val;
            winner = key;
        }
        // If there is a tie, pick lexicographically smaller.
        else if (val == maxVal && winner > key)
        {
            winner = key;
        }
    }
    cout << winner << endl;
}

int main()
{
    vector<string> votes = {"john", "johnny", "jackie", "johnny", "john", "jackie", "jamie", "jamie", "john", "johnny", "jamie", "johnny", "john"};
    announce_winner(votes);
    return 0;
}