// question link: https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/

#include <bits/stdc++.h>
using namespace std;

int subZero(vector<int> arr)
{
    int sum = 0, flag = 0;
    // to store prefix sum(ps) and visit in map
    // [[ps1:1],[ps2:1]...[psn:1]]
    // if ps1 repeats in map means the subarray consist some value (eg. -ve value) that makes the value decrease to zero
    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0 || arr[i] == 0 || map[sum])
        {
            flag = 1;
            break;
        }
        else
        {
            // marking visited
            map[sum] = 1;
        }
    }
    flag ? cout << "true" : cout << "false";
    return 0;
}

int main()
{
    vector<int> arr = {4, 2, -3, 1, 6};
    subZero(arr);
    return 0;
}