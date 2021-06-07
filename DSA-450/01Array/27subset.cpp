// question link: https://practice.geeksforgeeks.org/problems/array-subset-of-another-array/0

#include <bits/stdc++.h>
using namespace std;

int findSubset(int a1[], int n, int a2[], int m)
{
    unordered_map<int, int> map;
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        map[a1[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        if (map.find(a2[i]) != map.end())
        {
            counter++;
        }
    }

    if (counter == m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int a1[] = {1, 2, 3, 4, 5, 6};
    int a2[] = {1, 2, 4};
    int n = 6, m = 3;
    cout << findSubset(a1, n, a2, m) << endl;
    return 0;
}