#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegativeNum(int K, vector<int> &arr)
{
    int N = arr.size();
    int i = 0;
    int j = 0;
    vector<int> ans;
    list<int> l;
    while (j < N)
    {
        if (arr[j] < 0)
            l.push_back(arr[j]);

        if (j - i + 1 < K)
            j++;
        else if (j - i + 1 == K)
        {
            if (l.size() == 0)
                ans.push_back(0);
            else
            {
                ans.push_back(l.front());
                if (arr[i] == l.front())
                    l.pop_front();
            }

            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {-1, 2, -3, 4, -5};
    int k = 2;
    vector<int> ans = firstNegativeNum(k, arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}