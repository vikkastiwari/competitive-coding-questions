// question link: https://practice.geeksforgeeks.org/problems/common-elements5420/0

#include <bits/stdc++.h>
using namespace std;

vector<int> common_element(vector<int> v1, vector<int> v2)
{

    vector<int> common;
    // Your code here
    int i = 0, j = 0;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    while (v1.size() > i && v2.size() > j)
    {
        if (v1[i] == v2[j])
        {
            common.push_back(v1[i]);
            i++;
            j++;
        }
        else if (v1[i] < v2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    sort(common.begin(), common.end());
    return common;
}

int main()
{
    vector<int> v1 = {3, 4, 2, 2, 4};
    vector<int> v2 = {3, 2, 2, 7};
    vector<int> common = common_element(v1, v2);
    for (auto c : common)
    {
        cout << c << " ";
    }
    return 0;
}