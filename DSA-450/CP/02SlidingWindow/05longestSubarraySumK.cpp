#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int i=0;
        int j=0;
        int res = -1; // max size of substring
        unordered_map<char,int> map;
        while(j<s.length()){
            map[s[j]]++;
            
            if(map.size()<k){ 
                j++;
            }else if(map.size() == k){
                res = max(res,j-i+1);
                j++;
            }else if(map.size()>k){
                while(map.size()>k){
                    map[s[i]]--;
                    if(map[s[i]] == 0){
                        map.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}