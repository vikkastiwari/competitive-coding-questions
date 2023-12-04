#include <bits/stdc++.h>
using namespace std;

int myAtoi(string str)
{
    int res = 0;
    int sign = 1;
    size_t i = 0;

    while (i < str.length() && str[i] == ' ')
        ++i;

    if (str[i] == '-')
    {
        sign = -1;
        ++i;
    }
    else if (str[i] == '+')
    {
        ++i;
    }

    while (i < str.length() && std::isdigit(str[i]))
    {
        if (res > (INT_MAX / 10) || (res == (INT_MAX / 10) && str[i] - '0' > 7))
        {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        res = res * 10 + (str[i] - '0');
        ++i;
    }

    return sign == 1 ? res : -res;
}

int main()
{
    string s = "   -42";
    int res = myAtoi(s);
    cout << res << endl;
    return 0;
}