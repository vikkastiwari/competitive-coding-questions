#include <bits/stdc++.h>
using namespace std;

int minSwaps(int arr[], int n)
{
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }

    sort(arrPos, arrPos + n);

    // initialized all the positons as not visited
    vector<bool> visited(n, false);
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] || arrPos[i].second == i)
        {
            continue;
        }
        int cycle_size = 0;
        // we take i in temp
        int temp = i;
        // until our cycle i.e. both nodes are not marked visited we run loop
        while (!visited[temp])
        {
            // marked visited one node
            visited[temp] = 1;

            //now we will search current nodes index value i.e. current.second in all the further nodes i.e next.first and if current.second = next.first means we found the correct node with which we have to perform swap. now if it is non visited we mark it visited and increase our swap count and if it is visited we continue with our sequence

            temp = arrPos[temp].second;
            cycle_size++;
        }

        // for each cycle we sum it in ans
        if (cycle_size > 0)
        {
            // from a to b one cycle and from b to a second cycle
            // cycle_size=2
            // but we perform only one swap for this cycle thats why we reduce it by one
            ans += (cycle_size - 1);
        }
    }

    return ans;
}

int main()
{
    // two swaps b/w 5 and 2 , 4 and 3
    int arr[] = {1, 5, 4, 3, 2};
    int n = (sizeof(arr) / sizeof(int));
    cout << minSwaps(arr, n);
    return 0;
}
