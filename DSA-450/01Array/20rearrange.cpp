// question link: https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/

#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n)
{
    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            neg++;
        }
        else
        {
            pos++;
        }
    }
    cout << neg << endl;
    cout << pos << endl;
    vector<int> arr1(neg);
    vector<int> arr2(pos);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            arr2[i] = arr[i];
        }
        else
        {
            arr1[i] = arr[i];
        }
    }

    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 2, 3, -4, -1, 4};
    int n = 5;
    sort(arr, arr + n);
    rearrange(arr, n);
    return 0;
}