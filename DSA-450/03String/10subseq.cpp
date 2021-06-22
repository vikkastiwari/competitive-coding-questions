// question link: https://www.geeksforgeeks.org/print-subsequences-string/

#include <bits/stdc++.h>
using namespace std;

unordered_set<string> res;

void subSeq(string s, int i, int n, string temp)
{
    if ((i == n))
    {
        res.insert(temp);
    }
    else
    {
        subSeq(s, i + 1, n, temp);
        temp += s[i];
        subSeq(s, i + 1, n, temp);
    }
}

int main()
{
    string s = "aaa";
    int i = 0;
    int n = s.length();
    subSeq(s, i, n, "");
    for (auto x : res)
    {
        cout << x << " ";
    }
    return 0;
}
