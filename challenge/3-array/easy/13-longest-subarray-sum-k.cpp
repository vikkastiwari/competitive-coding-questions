#include <bits/stdc++.h>
using namespace std;

/**
 * @brief brute force solution
 * TC: O(N^2)
 * SC: O(1)
 * 
 * @param nums 
 * @param K 
 * @return * void 
 */
void longestSubarraySumK1(vector<int> nums, int K){
    int maxEl = 0, sum = 0;
    for(int i=0;i<nums.size();i++){
        sum = 0;
        for(int j=i;j<nums.size();j++){
            sum += nums[j];
            if(sum == K){
                maxEl = max(maxEl,j-i+1);
            }
        }
    }
    
    cout << maxEl;
}

/**
 * @brief optimal solution for array that contains +ves & -ves both
 * TC: O(NlogN) - ordered map
 * SC: O(N)
 * 
 * we can use undordered_map too:
 * TC: O(N*1) - in case of no collision's
 * TC: O(N*N) ~ O(N^2) - in case of collision's
 * 
 * @param nums 
 * @param K 
 * @return * void 
 */
void longestSubarraySumK2(vector<int> nums, int K){
    map<int, int> prefSumMap; // ordered map
    int sum = 0;
    int maxLen = 0;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];
        if(sum == K){
            maxLen = max(maxLen, i+1);
        }
        int rem = sum - K; // remaining wala - extreme left
        if(prefSumMap.find(rem) != prefSumMap.end()){ // if rem present in hashmap
            // len - length of elements that gives sum K
            // i - current position of iteration
            // prefSumMap[rem] - gives end index of rem - this is rev eng.
            int len = i - prefSumMap[rem];
            maxLen = max(maxLen, len);
        }
        // if sum not found in hash then only update the hash
        // it handles zero wala edge case - eg: [2,0,0,3], K = 3
        if(prefSumMap.find(sum) == prefSumMap.end()){
            prefSumMap[sum] = i;
        }
    }
    cout << maxLen;
}

int main(){
    vector<int> nums;
    int K = 3;
    nums = { 2,0,0,3 }; // op: 3
    // nums = { 2,3,5,0,1,9 }; // op: 4
    longestSubarraySumK2(nums, K);
    cout << endl;
    return 0;
}