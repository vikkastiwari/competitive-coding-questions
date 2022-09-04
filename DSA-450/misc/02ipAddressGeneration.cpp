//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
    void solve(string s, int i, int j, int level, string temp, vector<string>& res)
    {
        if (i == (j + 1) && level == 5) {
            res.push_back(temp.substr(1));
            cout << temp.substr(1) << " " << "temp.substr(1)" << endl;
        }
     
        for (int k = i; k < i + 3 && k <= j; k++) {
            string ad = s.substr(i, k - i + 1);
            cout << ad << "ad" << endl;
            if ((s[i] == '0' && ad.size()>1) || stol(ad) > 255)
                return;
     
            solve(s, k + 1, j, level + 1, temp + '.' + ad, res);
        }
    }
    
    vector<string> genIp(string &s) {
        // Your code here
         int n = s.length();
        vector<string> res;
        solve(s, 0, n - 1, 1, "", res);
        return res;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends