// question link: https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    for (int i = 0; i < m; i++)
    {
        nums1.push_back(nums2[i]);
    }
    sort(nums1.begin(), nums1.end());
    if ((n + m) % 2 != 0)
    {
        return nums1[(n + m) / 2];
    }
    else
    {
        return (float)(nums1[(n + m) / 2] + nums1[((n + m) / 2) - 1]) / (float)2;
    }
    return 0;
}

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
