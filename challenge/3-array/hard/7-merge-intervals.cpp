#include <bits/stdc++.h>
using namespace std;

/**
 * @brief mergeIntervals
 * TC: O(nlogn * n)
 * SC:O(n)
 * @param arr 
 * @return * void    
 */
void mergeIntervals(vector<vector<int>> arr){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    ans.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        if(ans.back()[1] >= arr[i][0]){
            ans.back()[1] = max(ans.back()[1],arr[i][1]);
        }else{
            ans.push_back(arr[i]);
        }
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}   

int main()
{
    vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};
    mergeIntervals(arr);
    return 0;
}
