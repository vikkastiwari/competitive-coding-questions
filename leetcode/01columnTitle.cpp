// question link: https://leetcode.com/problems/excel-sheet-column-title/

#include <bits/stdc++.h>
using namespace std;

string convertToTitle(int columnNumber)
{
    string str;
    while (columnNumber--)
    {
        str += char('A' + columnNumber % 26);
        columnNumber /= 26;
    }
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    int n = 234;
    cout << convertToTitle(n) << endl;
    return 0;
}
