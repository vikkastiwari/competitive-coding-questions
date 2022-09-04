//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

int longestSubstrDistinctChars (string s)
{
    // your code here
    int i=0;
    int j=0;
    int res = -1; // max size of substring
    unordered_map<char,int> map;
    while(j<s.length()){
        map[s[j]]++;
        // j-i+1 represents window size
        // instead of k here we will use window size as we need to consider all the distinct chars in a window size
        if(map.size() == j-i+1){
            res = max(res,j-i+1);
        }else if(map.size()<j-i+1){
            while(map.size()<j-i+1){
                map[s[i]]--;
                if(map[s[i]] == 0){
                    map.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }
    return res;
}