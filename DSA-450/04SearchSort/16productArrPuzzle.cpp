// question link: https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1#

#include <bits/stdc++.h>
using namespace std;

// getting wrong ans for large inputs

vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    //code here
    vector<long long int> prodA;
    long long int prod = 1;
    if (n == 1)
    {
        if (nums[0] == 0)
        {
            prodA.push_back(0);
            return prodA;
        }
        else
        {
            prodA.push_back(nums[0]);
            return prodA;
        }
    }
    if (n == 2)
    {
        if (nums[0] == 0 and nums[1] == 1)
        {
            prodA.push_back(1);
            prodA.push_back(0);
            return prodA;
        }
        else if (nums[0] == 1 and nums[1] == 0)
        {
            prodA.push_back(0);
            prodA.push_back(1);
            return prodA;
        }
    }
    for (long long int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            prod *= nums[i];
        }
    }
    for (long long int i = 0; i < n; i++)
    {
        long long int temp = prod;
        if (nums[i] != 0)
        {
            long long int ap = (float)temp / nums[i];
            prodA.push_back(ap);
        }
        else if (nums[i] == 0)
        {
            prodA.push_back(prod);
        }
    }
    return prodA;
}
int main()
{
    vector<long long int> arr = {10, 3, 5, 6, 2};
    vector<long long int> prod = productExceptSelf(arr, arr.size());
    for (int i = 0; i < prod.size(); i++)
    {
        cout << prod[i] << " ";
    }
    cout << endl;
    return 0;
}