#include <bits/stdc++.h>
using namespace std;

string convert_s(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (i == 0 && s[i] != ' ' || s[i] != ' ' && s[i - 1] == ' ')
        {
            if (islower(s[i]))
            {
                s[i] = toupper(s[i]);
            }
        }
        else if (isupper(s[i]))
        {
            s[i] = tolower(s[i]);
        }
    }
    return s;
}

int main()
{
    string s = "vIKas TiWArI iS my nAmE.";
    cout << convert_s(s);
    return 0;
}