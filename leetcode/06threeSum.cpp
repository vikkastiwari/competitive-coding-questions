// question link: https://leetcode.com/problems/3sum/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    int n = nums.size();

    if (n == 0 || (n == 1 and nums[0] == 0))
        return result;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        int start = i + 1;
        int end = n - 1;
        while (start < end)
        {
            int sum = nums[i] + nums[start] + nums[end];
            if (sum > 0)
            {
                end--;
            }
            else if (sum < 0)
            {
                start++;
            }
            else
            {
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[start]);
                temp.push_back(nums[end]);
                result.push_back(temp);
            }
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}