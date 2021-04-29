#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#//
// } Driver Code Ends

// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n)
{
    // Your code here
    int steps = 0, counter = 0;
    for (int i = 0; i < n;)
    {
        if (arr[i] != 0)
        {
            steps = arr[i];
            for (int j = 0; j < steps; j++)
            {
                i++;
                if (arr[i] == 0)
                {
                    break;
                }
            }
            counter++;
        }
        else
        {
            break;
        }
    }
    return counter;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << minJumps(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends