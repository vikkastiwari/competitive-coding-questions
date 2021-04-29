#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n)
{

    // Your code here
    int max_till = 0, max_end = 0;
    for (int i = 0; i < n; i++)
    {
        max_end += arr[i];
        if (max_till < max_end)
        {
            max_till = max_end;
        }
        if (max_end < 0)
        {
            max_end = 0;
        }
    }
    return max_till;
}

// { Driver Code Starts.

int main()
{
    int t, n;

    cin >> t;   //input testcases
    while (t--) //while testcases exist
    {

        cin >> n; //input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; //inputting elements of array

        cout << maxSubarraySum(a, n) << endl;
    }
}
// } Driver Code Ends