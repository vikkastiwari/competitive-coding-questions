// Fibonacci using Recursive and Iterative method
#include <bits/stdc++.h>
using namespace std;

int fibonacci(int num)
{
    // Handling base case
    if (num == 0 || num == 1)
    {
        return num;
    }
    // Handling recursive case
    else
    {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << "Recursive method" << endl;
    for (int i = 0; i < n; i++)
    {
        int fib = fibonacci(i);
        cout << fib << " ";
    }
    cout << endl;

    cout << "Iterative method" << endl;
    int fibArray[n];

    // handling base case in iterative method
    fibArray[0] = 0;

    if (n > 1)
    {
        fibArray[1] = 1;
    }

    // handling recursive case in iterative method
    for (int i = 2; i < n; i++)
    {
        fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
    }

    // printing the values
    for (int i = 0; i < n; i++)
    {
        cout << fibArray[i] << " ";
    }
    cout << endl;
    return 0;
}