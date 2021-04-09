#include <bits/stdc++.h>
using namespace std;

/*
Google Question

given an array = [2,5,1,2,4,25,5,7,5,3]
It should return 2

given an array = [1,2,3,1,2,5,7,3]
It should return 1

given an array = [2,5,1,4,8]
It should return undefined
*/

int checkRecurring(int *arr, int size)
{
    map<int, int> map;

    for (int i = 0; i < size; i++)
    {
        if (map.find(arr[i]) == map.end())
        {
            map[arr[i]] = 1;
        }
        else
        {
            // cout << arr[i] << endl;
            return arr[i];
        }
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << checkRecurring(arr, n) << endl;
    return 0;
}