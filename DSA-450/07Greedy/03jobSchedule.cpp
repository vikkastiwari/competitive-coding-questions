
#include <bits/stdc++.h>
using namespace std;

struct Job
{
    char id;    // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n)
{
    // sort jobs in decreasing order of profit
    sort(arr, arr + n, comparison);

    int seq[n];
    bool track[n]; // track of assigning jobs in gant chart

    for (int i = 0; i < n; i++)
    {
        track[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
        {
            if (track[j] == false)
            {
                track[j] = true;
                seq[j] = i;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (track[i])
            cout << arr[seq[i]].id << " ";
        // in seq the index is stored which is scheduled in given time frame for max profit
    }
    cout << endl;

    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (track[i])
            profit += arr[seq[i]].profit;
    }
    cout << profit << endl;
}

int main()
{
    Job arr[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printJobScheduling(arr, n);
    return 0;
}
