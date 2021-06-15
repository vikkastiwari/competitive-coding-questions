// question link: https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/

#include <bits/stdc++.h>
using namespace std;

int checkRotations(string s, string goal)
{
    if (s.length() == 0)
        return 0;
    if (s == goal)
        return 1;
    string temp = s + s;
    if (temp.find(goal) != string::npos)
    {
        return 1;
    }
    return 0;
}

int main()
{
    string s = "abcd";
    string goal = "dabc";
    cout << checkRotations(s, goal) << endl;
    return 0;
}
