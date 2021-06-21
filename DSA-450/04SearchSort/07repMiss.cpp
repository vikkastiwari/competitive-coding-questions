// question link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#

#include <bits/stdc++.h>
using namespace std;

void findTwoElement(int *arr, int n)
{
    unordered_map<int, int> twice;
    for (int i = 0; i < n; i++)
    {
        twice[arr[i]]++;
    }
    sort(arr, arr + n);
    int missing = 0, rep = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == i)
            missing = i;
        if (twice[arr[i]] > 1)
            rep = i;
    }
    cout << rep << " " << missing;
}

int main()
{
    int arr[] = {4, 3, 6, 2, 1, 1};
    int n = sizeof(arr) / sizeof(int);
    findTwoElement(arr, n);
    return 0;
}