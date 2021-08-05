#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

// evaluating number of ways such that the experssion evaluates to true
int evaluate(string exp, int i, int j, bool isTrue)
{
    // index of map = temp
    // instead of mapping values in 3d matrix we are concating the parameters of function call and storing the result of that at that particular key in map.
    string temp = to_string(i) + " " + to_string(j) + " " + (isTrue ? "T" : "F");

    if (mp.find(temp) != mp.end())
    {
        return mp[temp];
    }

    if (i >= j)
    {
        if (isTrue == true)
            // if exp[i]==true return true else return false
            mp[temp] = exp[i] == 'T';
        else
            // if exp[i]==false return true else return false
            mp[temp] = exp[i] == 'F';
        return mp[temp];
    }

    int ans = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        int lT = evaluate(exp, i, k - 1, true);
        int lF = evaluate(exp, i, k - 1, false);
        int rT = evaluate(exp, k + 1, j, true);
        int rF = evaluate(exp, k + 1, j, false);

        if (exp[k] == '|')
        {
            if (isTrue == true)
                ans += (lT * rT) + (lT * rF) + (rT * lF);
            else
                ans += (rF * lF);
        }
        if (exp[k] == '&')
        {
            if (isTrue == true)
                ans += (lT * rT);
            else
                ans += (lT * rF) + (rT * lF) + (rF * lF);
        }
        if (exp[k] == '^')
        {
            if (isTrue == true)
                ans += (lT * rF) + (rT * lF);
            else
                ans += (lT * rT) + (rF * lF);
        }
    }
    return mp[temp] = ans;
}

int main()
{
    string exp = "T^F|F";
    cout << evaluate(exp, 0, exp.length() - 1, true) << endl;
    return 0;
}