// question link: https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1#

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// it fails to update the third occurance as three as it finds the sum but of first occurance which is 1 and again make it two so now there are second and third repeated element but of same occurance

ll findSubarray(vector<ll> arr, ll n)
{
    ll count = 0;
    unordered_map<ll, ll> map;
    ll i = -1, sum = 0;
    map.insert(pair<ll, ll>(0, 1));
    while (i < arr.size() - 1)
    {
        i++;
        sum += arr[i];
        if (map.find(sum) != map.end())
        {
            auto it = map.find(sum);
            count += it->second;
            // cout << it->first << " " << it->second + 1 << endl;
            while (it != map.end() and (it->first == sum))
            {
                map.insert(pair<ll, ll>(sum, (it->second + 1)));
                it++;
            }
        }
        else
        {
            map.insert(pair<ll, ll>(sum, 1));
            cout << sum << " " << 1 << endl;
        }
    }
    return count;
}

int main()
{
    vector<ll> arr = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    cout << findSubarray(arr, arr.size());
    return 0;
}
