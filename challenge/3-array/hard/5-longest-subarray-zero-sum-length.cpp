#include <bits/stdc++.h>
using namespace std;

int longestSubarrayZeroSum(vector<int> arr){
    int n = arr.size();
    int sum = 0, maxEl = 0, count = 0;
    for(int i=0;i<n;i++){
        count = 1;
        sum = 0;
        sum += arr[i];
        for(int j=i+1;j<n;j++){
            sum += arr[j];
            count++;
            if(sum == 0){
                maxEl = max(maxEl,count);
            }
        }
    }
    return maxEl;
}   

int longestSubarrayZeroSumOptimal(vector<int> arr){
    int n = arr.size();
    int target = 0;
    unordered_map<int, int> hashMap;
    
    hashMap[0] = 1;
    // its similar to the below code - inside inner loop
    // if(sum == 0) {
    //     maxi = i + 1; 
    // }

    int sum = 0, maxEl = 0, count = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        int diff = sum - target;
        // if(sum == 0) {
        //     maxEl = i + 1; 
        //     cout << "2l" << endl;
        // }
        if(hashMap.find(diff) != hashMap.end()){
            maxEl = max(maxEl, i - hashMap[diff]);
        }else {
            hashMap[sum] =  i;
        }
    }
    return maxEl;
}   

int main()
{
    vector<int> arr = {9, -3, 3, -1, 6, -5};
    int res = longestSubarrayZeroSumOptimal(arr);
    cout << res << endl;
    return 0;
}
