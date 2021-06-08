// question link: https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621

#include <bits/stdc++.h>
using namespace std;


int trap(vector<int> &height)
{
    int n = height.size();
    if (n <= 2)
    {
        return 0;
    }

    int maxLeft = height[0];
    int left = 1;
    int maxRight = height[n - 1];
    int right = n - 2;

    int trapped = 0;

    while (left <= right)
    {
        if (maxLeft < maxRight)
        {
            if (maxLeft <= height[left])
            {
                maxLeft = height[left];
            }
            else
            {
                trapped += maxLeft - height[left];
            }
            left += 1;
        }
        else
        {
            if (height[right] > maxRight)
            {
                maxRight = height[right];
            }
            else
            {
                trapped += maxRight - height[right];
            }
            right -= 1;
        }
    }
    return trapped;
}

int main()
{
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(heights) << endl;
    return 0;
}
