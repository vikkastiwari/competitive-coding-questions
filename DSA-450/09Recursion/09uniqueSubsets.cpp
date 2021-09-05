#include <bits/stdc++.h>
using namespace std;

void solve(string op, string ip, int &count, vector<string> &st)
{
    if (ip.length() == 0)
    {
        if (find(st.begin(), st.end(), op) == st.end())
        {
            st.push_back(op);
            count += 1;
        }
        return;
    }
    string op1 = op, op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(op1, ip, count, st);
    solve(op2, ip, count, st);
}

int main()
{
    string ip = "aabb";
    string op = "";
    int count = 0;
    vector<string> st;
    solve(op, ip, count, st);
    cout << "Count: " << count << endl;
    for (int i = 0; i < st.size(); i++)
    {
        cout << st[i] << " ";
    }
    return 0;
}