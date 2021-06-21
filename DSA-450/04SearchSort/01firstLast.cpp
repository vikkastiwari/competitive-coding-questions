// question link: https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1

#include <bits/stdc++.h>
using namespace std;

void findFirstAndLast(int arr[], int n, int x)
{
    int f = INT_MAX, l = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            if (i < f)
            {
                f = i;
            }
            if (i > l)
            {
                l = i;
            }
        }
    }
    cout << f << " " << l << endl;
}

int main()
{
    int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int n = sizeof(arr) / sizeof(int);
    int x = 5;
    findFirstAndLast(arr, n, x);
    return 0;
}