#include <bits/stdc++.h>
#define ll long long
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{

    // Base Case
    if (n == 0 || W == 0)
        return 0;

    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (wt[n - 1] > W)
    {
        return knapSack(W, wt, val, n - 1);
    }

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
    {
        return (max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1)));
    }
}

int main()
{
    // int val[] = {60, 100, 120};
    // int wt[] = {10, 20, 30};
    // int W = 50;

    // int wt[] = {1, 2, 3};
    // int val[] = {10, 15, 40};
    // int W = 6;

    int wt[] = {3, 4, 6, 5};
    int val[] = {2, 3, 1, 4};
    int W = 8;

    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}