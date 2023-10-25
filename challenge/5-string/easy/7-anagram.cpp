#include <bits/stdc++.h>
using namespace std;

/**
 * @brief An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 * 
 * @param s 
 * @param t 
 * @return boolean 
 */
bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;

    unordered_map<char, int> freq;
    for(auto c : s) freq[c]++;
    for(auto c : t) freq[c]--;
    for(auto f : freq) if(f.second != 0) return false;

    return true;
}

int main(){
    string s = "abcde", goal = "cdeab";
    bool res = isAnagram(s, goal);
    cout << res << endl; 
    return 0;
}