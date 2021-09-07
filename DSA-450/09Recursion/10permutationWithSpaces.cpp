#include <bits/stdc++.h>
using namespace std;

void solve(string op, string ip)
{
    if (ip.length() == 0)
    {
        cout << op << endl;
        return;
    }
    string op1 = op, op2 = op;
    // with space
    op1 += " ";
    op1 += ip[0];
    // without space
    op2 += ip[0];
    ip.erase(ip.begin() + 0);
    solve(op1, ip);
    solve(op2, ip);
}

int main()
{
    string ip = "abc";
    string op = "";
    op.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(op, ip);
    return 0;
}