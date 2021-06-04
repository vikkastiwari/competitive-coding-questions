// question link: https://practice.geeksforgeeks.org/problems/count-element-occurences/

#include <bits/stdc++.h>
using namespace std;

int countOccurence(int arr[], int n, int k)
{
    // Your code here
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
    int n = 8;
    int arr[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int k = 4;
    cout << countOccurence(arr, n, k) << endl;
    return 0;
}
