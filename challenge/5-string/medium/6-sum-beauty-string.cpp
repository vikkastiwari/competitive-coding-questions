#include <bits/stdc++.h>
using namespace std;

/**
 * @example Input: s = "aabcb"
 * Explanation: The substrings with non-zero beauty are 
 * ["aab","aabc","aabcb","abcb","bcb"],
 * each with beauty equal to 1.
 */

/**
 * @brief Sum of Beauty of All Substrings
 * 
 * @param s 
 * @return * int 
 */
int beautySum(string s)
{
    int sum = 0;
    int maxFreq = INT_MIN, minFreq = INT_MAX;

    for (int i = 0; i < s.length(); i++)
    {
        unordered_map<char, int> freq;
        for (int j = i; j < s.length(); j++)
        {
            freq[s[j]]++;
            for (const auto &pair : freq)
            {
                maxFreq = max(maxFreq, pair.second);
                minFreq = min(minFreq, pair.second);
            }
            int beauty = maxFreq - minFreq;
            sum += beauty;
            maxFreq = INT_MIN, minFreq = INT_MAX;
        }
        freq.clear();
    }
    return sum;
}
int main()
{
    string s = "aabcbaa";
    int res = beautySum(s);
    cout << res << endl;
    return 0;
}