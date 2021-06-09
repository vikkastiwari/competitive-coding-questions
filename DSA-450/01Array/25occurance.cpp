// question link: https://practice.geeksforgeeks.org/problems/count-element-occurences/1

#include <bits/stdc++.h>
using namespace std;

int countOccurence(vector<int> arr, int k)
{
    // Your code here
    int n = arr.size();
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[arr[i]]++;
    }
    int count = 0;
    for (auto x : map)
    {
        if (x.second > (n / k))
            count++;
    }
    return count;
}

int main()
{
    vector<int> nums1 = {3, 1, 2, 2, 1, 2, 3, 3};
    int k = 4;
    cout << countOccurence(nums1, k) << endl;
    return 0;
}
