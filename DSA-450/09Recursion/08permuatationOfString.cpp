#include <bits/stdc++.h>
using namespace std;

void solve(string op, string ip, int &count)
{
    if (ip.length() == 0)
    {
        cout << op << " ";
        count += 1;
        return;
    }
    string op1 = op, op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(op1, ip, count);
    solve(op2, ip, count);
}

int main()
{
    string ip = "ab";
    string op = "";
    int count = 0;
    solve(op, ip, count);
    cout << endl;
    cout << count << endl;
    return 0;
}