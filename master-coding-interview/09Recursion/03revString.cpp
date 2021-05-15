/* Function to reverse a string using recursion */

#include <bits/stdc++.h>
using namespace std;

void reverse(const string &str)
{
    int strSize = str.size();

    // base condition or exist logic
    if (strSize == 1)
    {
        cout << str << endl;
    }
    // recursive condition
    else
    {
        cout << str[strSize - 1];
        reverse(str.substr(0, strSize - 1));
    }
}

int main()
{
    string str;

    cout << " Enter a string:" << endl;
    getline(cin, str);

    // function call
    reverse(str);

    return 0;
}