// question link: https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/

#include <bits/stdc++.h>
using namespace std;

void countDuplicates(string s)
{
    map<char, int> map;
    for (int i = 0; i < s.length(); i++)
    {
        map[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (map[s[i]] > 1)
        {
            cout << s[i] << " " << map[s[i]] << endl;
            map[s[i]] = 0;
        }
    }
}

int main()
{
    string s = "manipalpanimal";
    countDuplicates(s);
    return 0;
}
