// question link: https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1#

#include <bits/stdc++.h>
using namespace std;
#define MAX 500

int multiply(int x, int res[], int res_size)
{
    int prod, carry = 0;

    for (int i = 0; i < res_size; i++)
    {
        prod = res[i] * x + carry;

        res[i] = prod % 10;

        carry = prod / 10;
    }

    while (carry)
    {
        res[res_size] = carry % 10;
        carry /= 10;
        res_size++;
    }
    return res_size;
}

void factorial(int N)
{
    int res[MAX];

    res[0] = 1;
    int res_size = 1;

    for (int i = 2; i <= N; i++)
    {
        res_size = multiply(i, res, res_size);
    }

    for (int i = res_size - 1; i >= 0; i--)
        cout << res[i];
}

int main()
{
    int n = 5;
    factorial(n);
    return 0;
}