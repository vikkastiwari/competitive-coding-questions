// https://leetcode.com/problems/xor-queries-of-a-subarray/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int XOR(vector<int>& arr, vector<int>& queries){
        if(queries.size() < 2) return -1;
        int ans = 0;
        for(int i=queries[0];i<=queries[1];i++){
            ans = ans ^ arr[i];
        }
        return ans;
    }

public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        for(int i=1;i<n;i++){ // prefix xor - using prefix sum technique
            arr[i]= arr[i]^arr[i-1];
        }
        cout << endl;
        vector<int> res;
        for(int i=0; i<queries.size();i++){
            int start = queries[i][0];
            int end = queries[i][1];
            
            if(start == 0) res.push_back(arr[end]);
            else {
                // a xor a cancel out each other resulting to 0
                // and z xor 0 gives z only 

                // 0 to end
                // 0 to start - 1
                // in this which ever elements are repeated they cancel each other 
                // hence we get the xor of elements with in range
                int ans = arr[end] ^ arr[start-1];
                res.push_back(ans);
            }
        }

        return res;
    }
};

int main(){
    Solution xorr;
    vector<int> arr = {1,3,4,8};
    vector<vector<int>> queries = {{0,1},{1,2},{0,3},{3,3}};
    vector<int> res = xorr.xorQueries(arr,queries);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}