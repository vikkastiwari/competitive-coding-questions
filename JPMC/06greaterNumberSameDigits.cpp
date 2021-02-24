#include <bits/stdc++.h>
using namespace std;

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void findNext(char digit[], int n)
{
    int i, j;
    for (i = n - 1; i > 0; i--)
    {
        if (digit[i] > digit[i - 1])
            break;
    }
    if (i == 0)
    {
        cout << "Not Possible" << endl;
        return;
    }
    int x = digit[i - 1], smallest = i;
    // cout << "X: " << x << ' ' << "Smallest=i: " << smallest << endl;
    for (j = i + 1; j < n; j++)
    {
        if (digit[smallest] > digit[j] && digit[j] > x)
        {
            smallest = j;
        }
    }
    swap(&digit[smallest], &digit[i - 1]);
    sort(digit + i, digit + n);
    cout << digit << endl;
    return;
}

int main()
{
    int n;
    cin >> n;
    char digits[n];
    cin >> digits;
    findNext(digits, n);
    return 0;
}