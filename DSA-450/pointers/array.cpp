//case 1
#include <bits/stdc++.h>
using namespace std;

void show(int *num)
{
    cout << *num << " ";
}
int len(int *num, int *n)
{
    int c = 0;
    int maxp = 0;
    for (int i = 0; i < *n; i++)
    {
        c++;
        if (num[i] > maxp)
        {
            maxp = num[i];
        }
    }
    return maxp;
}
int main()
{
    int a[] = {3, 2, 1, 6, 7, 4, 5, 0, 10, 8};
    for (int i = 0; i < 10; i++)
    {
        show(&a[i]);
    }
    cout << endl;
    int n = 10;
    cout << len(a, &n);
    return 0;
}


// case 2

#include <bits/stdc++.h>
using namespace std;

int solve(int &f, int &e, int *arr)
{
    int sum = 0;
    for (int i = 0; i < f; i++)
    {
        sum += arr[i];
    }
    return f + e + sum;
}

int main()
{
    int f, e;
    // cin >> f >> e;
    f = 5, e = 3; // op = 3
    int arr[5];
    int ct = 0;
    for (int i = 0; i < f; i++)
    {
        arr[i] = ct++;
    }
    cout << solve(f, e, arr);
    return 0;
}
