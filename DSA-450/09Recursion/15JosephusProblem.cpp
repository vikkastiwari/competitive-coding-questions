#include <bits/stdc++.h>
using namespace std;
void solve(int k, int sword, vector<int> person, int &ans)
{
    if (person.size() == 1)
    {
        ans = person[0];
        return;
    }
    sword = (sword + k) % person.size();
    person.erase(person.begin() + sword);
    solve(k, sword, person, ans);
    return;
}

int main()
{
    int index = 0;     // sword
    int n = 14, k = 2; // for first iteration where k=3 it will kill index=2 therefore k-- is done
    k = k - 1;
    int ans = -1;
    vector<int> person;
    for (int i = 1; i <= n; i++)
        person.push_back(i);

    solve(k, index, person, ans);
    cout << ans << endl;
    return 0;
}