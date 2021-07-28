#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int weight, profit;
    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
};

bool cmp(struct Item a, struct Item b)
{
    double ratio1 = (double)(a.profit) / (double)(a.weight);
    double ratio2 = (double)(b.profit) / (double)(b.weight);
    return ratio1 > ratio2;
}

int fractionalKnapsack(int totalMass, Item arr[], int n)
{
    sort(arr, arr + n, cmp);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].profit << " " << arr[i].weight << " : " << ((double)arr[i].profit / arr[i].weight) << endl;
    }

    int currWeight = 0;
    double totalProfit = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (currWeight + arr[i].weight <= totalMass)
        {
            currWeight = currWeight + arr[i].weight;
            totalProfit = totalProfit + arr[i].profit;
        }
        else
        {
            int remain = totalMass - currWeight; // remaining space in bag
            totalProfit += arr[i].profit * ((double)remain / (double)arr[i].weight);
            break;
        }
    }
    return totalProfit;
}

int main()
{
    int W = 50;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << fractionalKnapsack(W, arr, n);
    return 0;
}