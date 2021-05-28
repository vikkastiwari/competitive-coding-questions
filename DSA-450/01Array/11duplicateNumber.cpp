// question link: https://leetcode.com/problems/find-the-duplicate-number/

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    set<int> s1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (s1.find(nums[i]) != s1.end())
        {
            return nums[i];
        }
        else
        {
            s1.insert(nums[i]);
        }
    }
    return 0;
}

int main()
{
    vector<int> v = {1, 3, 4, 2, 2};
    cout << findDuplicate(v) << endl;
}