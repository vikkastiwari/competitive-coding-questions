#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    // base case
    if (n < 0)
    {
        return 0;
    }
    if (n == 0 || n == 1)
    {
        return 1;
    }
    // recursive case
    else
    {
        // fact(5) = 5*4*3*2*1
        return n * fact(n - 1);
    }
}

int main()
{
    int num;
    cin >> num;
    int factorial = fact(num);
    cout << num << ": " << factorial << endl;
    return 0;
}
