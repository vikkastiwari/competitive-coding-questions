#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int path[n][2];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> path[i][j];
        }
    }
    int max_prev = max(path[0][0], path[0][1]);
    int min_prev = max(path[0][0], path[0][1]);
    int count = max_prev;
    for (int i = 1; i < n; i++)
    {
        int max_next = max(path[i][0], path[i][1]);
        int min_next = min(path[i][0], path[i][1]);

        int max_min = max(max_prev + max_next, max_prev + min_next);
        int min_max = max(min_prev + max_next, min_prev + min_next);
        if ()
            break;
        if (max(path[i][0], path[i][1]) > prev)
        {
            prev = max(path[i][0], path[i][1]);
            count += prev;
        }
    }
    cout << count << endl;
    return 0;
}