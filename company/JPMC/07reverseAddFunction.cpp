#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll reverse(ll n)
{
    ll rev = 0;
    while (n > 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

bool isPalindrome(ll n)
{
    return (reverse(n) == n);
}

void reverseadd(ll n)
{
    ll rev_n = 0;
    while (n <= 4294967295)
    {
        // Reversing
        rev_n = reverse(n);

        // Adding the reversed nber with the original
        n = n + rev_n;

        // Checking palindrome or not
        if (isPalindrome(n))
        {
            cout << n << endl;
            break;
        }
        else if (n > 4294967295)
        {
            cout << "No palindrome exist" << endl;
        }
    }
}

int main()
{
    reverseadd(196);
    reverseadd(256);
    return 0;
}