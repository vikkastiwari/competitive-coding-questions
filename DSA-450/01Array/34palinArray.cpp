// question link: https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1#

#include <bits/stdc++.h>
using namespace std;

int PalinArray(vector<int> a)
{ //add code here.
    vector<int> palin;
    int n = a.size();
    if (n == 0)
        return 0;

    for (int i = 0; i < n; i++)
    {
        int num = a[i];
        int sum = 0, dig;
        while (num > 0)
        {
            dig = num % 10;
            sum = sum * 10 + dig;
            num = num / 10;
        }
        if (sum == a[i])
        {
            palin.push_back(sum);
        }
    }

    if (palin.size() == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    vector<int> arr = {111, 222, 333, 244};
    cout << PalinArray(arr);
    return 0;
}