// question link: https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/

#include <bits/stdc++.h>
using namespace std;

int twiceBS(int price[], int n)
{
    int min = *min_element(price, price + n);
    int max = *max_element(price, price + n);
    int profit = 0;

    if (max == price[0])
    {
        return 0;
    }

    // further logic
    return 0;
}

int main()
{
    int price[] = {10, 22, 5, 75, 65, 80};
    int n = 6;
    cout << twiceBS(price, n) << endl;
    return 0;
}
