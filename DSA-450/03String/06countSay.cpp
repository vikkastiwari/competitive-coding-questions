// question link: https://leetcode.com/problems/count-and-say/submissions/

#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n)
{
    if (n == 1)
        return "1";
    string say = "1";
    while (--n)
    {
        string temp = "";
        for (int i = 0; i < say.size(); i++)
        {
            int count = 1;
            while (i + 1 < say.size() && say[i] == say[i + 1])
            {
                count++;
                i++;
            }
            temp += to_string(count);
            temp += say[i];
        }
        say = temp;
    }
    return say;
}

int main()
{
    int n = 4;
    cout << countAndSay(n) << endl;
    return 0;
}
