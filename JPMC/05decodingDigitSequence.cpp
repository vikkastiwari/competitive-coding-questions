#include <bits/stdc++.h>
using namespace std;

int countDecoding(char *digits, int n)
{
    if (n == 0 || n == 1)
        return 1;
    if (digits[0] == '0')
        return 0; // as per given condition - no leading & trailing zero's
    int count = 0;
    // If the last digit is not 0,
    // then last digit must add
    // to the number of words
    if (digits[n - 1] > '0')
    {
        count = countDecoding(digits, n - 1);
        cout << "(n-1) if: " << count << endl;
    }
    // If the last two digits form a number smaller
    // than or equal to 26, then consider
    // last two digits and recur
    if (digits[n - 2] == '1' || (digits[n - 2] == '2' && digits[n - 1] < '7'))
    {
        count += countDecoding(digits, n - 2);
        cout << "(n-2) if: " << count << endl;
    }

    return count;
}

int countSeq(char *digits, int n)
{
    if (n == 0 || n == 1 && digits[0] == '0')
        return 0;
    return countDecoding(digits, n);
}

int main()
{
    int n;
    cin >> n;
    char digits[n];
    cin >> digits;
    cout << countSeq(digits, n) << endl;
    return 0;
}