#include <bits/stdc++.h>
using namespace std;

/**
 * @brief isIsomorphic
 * 
 * @param s 
 * @param t 
 * @return * bool 
 */
bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        
        unordered_map<char, int> map_s;
        unordered_map<char, int> map_t;

        for (int i = 0; i < s.size(); ++i){
            // If they are not the same, it means that the characters 
            // are not mapped consistently and the strings are not isomorphic
            cout << map_s[s[i]] << " " << map_t[t[i]] << endl;
            if (map_s[s[i]]!=map_t[t[i]]) return false;
            map_s[s[i]] = i+1;
            map_t[t[i]] = i+1;
        }

        return true;  
    }

int main(){
    string s = "egg", t = "add";
    bool res = isIsomorphic(s,t);
    cout << res << endl;
    return 0;
}