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
    // copy as it is
    op1 += ip[0];
    // copy by making uppercase
    op2 += toupper(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(op1, ip);
    solve(op2, ip);
    return;
}

int main()
{
    string ip = "ab";
    string op = "";
    solve(op, ip);
    return 0;
}