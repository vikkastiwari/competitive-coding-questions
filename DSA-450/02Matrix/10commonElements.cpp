// question link: https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/

#include <bits/stdc++.h>
using namespace std;

vector<int> findCommon(vector<vector<int>> &nums)
{
    vector<int> common;
    unordered_map<int, int> map;

    // marking all row 0 elements as present
    for (int j = 0; j < nums[0].size(); j++)
    {
        map[nums[0][j]] = 1;
    }

    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[0].size(); j++)
        {
            // we initialize first row with 1, here i=0
            //  then when i =1 we check in map if the count of that element is 1
            // increment it by 1, now the count is 2 in map of that element
            // now in second row i=2 if the element is present then we compare the count of that element in map which is also now 2 with i.
            if (map[nums[i][j]] == i)
            {
                map[nums[i][j]] = i + 1;

                if ((i == nums.size() - 1) && map[nums[i][j]] == nums.size())
                {
                    common.push_back(nums[i][j]);
                }
            }
        }
    }

    return common;
}

int main()
{
    vector<vector<int>> nums = {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
    vector<int> result = findCommon(nums);

    for (int j = 0; j < result.size(); j++)
    {
        cout << result[j] << " ";
    }
    cout << endl;

    return 0;
}