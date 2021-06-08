// question link: https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1

#include <bits/stdc++.h>
using namespace std;

int minLenSubGreaterSum(vector<int> arr, int sum)
{
    int n = arr.size();
    int minLen = n;
    int start = 0, end = 0;
    int currentSum = 0;

    if (sum > accumulate(arr.begin(), arr.end(), 0))
        return 0;

    while (end < n)
    {
    }
    return minLen;
}

int main()
{
    vector<int> arr = {12, 4, 7, 9, 2, 23, 25, 41, 30,
                       40, 28, 42, 30, 44, 48, 43, 50};
    int sum = 7;
    cout << minLenSubGreaterSum(arr, sum) << endl;
    return 0;
}