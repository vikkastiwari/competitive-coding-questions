// question link: https://leetcode.com/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 1)
        return 1;

    sort(nums.begin(), nums.end());

    vector<int> seq;
    int count = 0, max = 0;
    seq.push_back(nums[0]);

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            seq.push_back(nums[i]);
        }
    }
    for (int i = 0; i < seq.size(); i++)
    {
        if (i > 0 && (seq[i] == seq[i - 1] + 1))
        {
            count++;
        }
        else
        {
            count = 1;
        }
        if (count > max)
            max = count;
    }
    return max;
}

int main()
{
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(arr) << endl;
    return 0;
}
