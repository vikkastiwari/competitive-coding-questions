#include <bits/stdc++.h>
using namespace std;

void solve(char s, char d, char h, int n, int &count)
{
    if (n == 1)
    {
        cout << "moving plate "
             << n
             << " from " << s << " to " << d;
        cout << endl;
        count += 1;
        return;
    }
    solve(s, h, d, n - 1, count); // source to helper
    cout << "moving plate "
         << n
         << " from " << s << " to " << d;
    cout << endl;
    count += 1;
    solve(h, d, s, n - 1, count); // helper to destination
}

int main()
{
    int n = 4;
    char s = 'A', h = 'B', d = 'C'; // source pole, helper pole, destination pole
    int count = 0;
    solve(s, d, h, n, count);
    cout << "Count: " << count << endl;
    return 0;
}