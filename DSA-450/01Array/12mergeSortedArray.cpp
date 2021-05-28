// question link: https://leetcode.com/problems/merge-sorted-array/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for (int i = 0; i < n; i++)
    {
        nums1[m] = nums2[i];
        m++;
    }
    sort(nums1.begin(), nums1.end());
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;
    merge(nums1, m, nums2, n);
    for (int i = 0; i < m + n; i++)
    {
        cout << nums1[i] << " ";
    }
}