// question link: https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1

#include <bits/stdc++.h>
using namespace std;

int countBits(int n)
{
    int count = 0;
    while (n)
    {
        count = count + (n & 1);
        n = n >> 1;
    }
    return count;
}

int compare(int a, int b)
{
    int c1 = countBits(a);
    int c2 = countBits(b);

    if (c1 <= c2)
    {
        return 0;
    }
    return 1;
}

vector<int> sortByBit(vector<int> arr)
{
    stable_sort(arr.begin(), arr.end(), compare);
    return arr;
}

int main()
{
    vector<int> arr = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    vector<int> sorted = sortByBit(arr);
    for (int i = 0; i < sorted.size(); i++)
    {
        cout << sorted[i] << " ";
    }
    return 0;
}