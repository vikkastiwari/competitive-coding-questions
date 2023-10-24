#include <bits/stdc++.h>
using namespace std;

/**
 * @brief rotate string by shift 
 * 
 * @param s 
 * @param goal 
 * @return boolean 
 */
bool rotateString(string s, string goal) {
    if(s.length()!=goal.length()) return false;

    string res = s; int i=0;
    while(i<s.length()){
        if(res == goal) return true;
        res += res[0];
        res.erase(res.begin()+0);
        i++;
    }
    return false;
}

int main(){
    string s = "abcde", goal = "cdeab";
    bool res = rotateString(s, goal);
    cout << res << endl; 
    return 0;
}