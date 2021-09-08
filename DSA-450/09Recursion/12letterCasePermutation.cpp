#include <bits/stdc++.h>
using namespace std;

void solve(string op, string ip, vector<string> &v)
{
    if (ip.length() == 0)
    {
        v.push_back(op);
        return;
    }
    if (isalpha(ip[0]))
    {
        string op1 = op, op2 = op;
        op1 += tolower(ip[0]);
        op2 += toupper(ip[0]);
        ip.erase(ip.begin() + 0);
        solve(op1, ip, v);
        solve(op2, ip, v);
    }
    else
    {
        string op1 = op;
        op1 += ip[0];
        ip.erase(ip.begin() + 0);
        solve(op1, ip, v);
    }
    return;
}

int main()
{
    string ip = "a1B2";
    string op = "";
    vector<string> ans;
    solve(op, ip, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}