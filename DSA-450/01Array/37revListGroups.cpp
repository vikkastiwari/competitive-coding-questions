#include <bits/stdc++.h>
using namespace std;

void reverseListGroups(vector<int> arr, int key)
{
    stack<int> s;
    int counter = 0;
    while (counter < arr.size())
    {
        int count = 0;
        while (counter < arr.size() && count < key)
        {
            s.push(arr[counter]);
            counter++;
            count++;
        }

        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
    }
}

int main()
{
    vector<int> arr = {4, 5, 7, 3, 8, 2, 6, 1, 9};
    int key = 4;
    reverseListGroups(arr, key);
    return 0;
}