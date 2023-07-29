#include <bits/stdc++.h>
using namespace std;

/**
 * @brief bruteforce approach
 * 
 * @param nums 
 * @param K 
 * @return * void 
 */
void countSubarraySumK1(vector<int> nums, int K)
{
    int count = 0;
    int sum = 0;
    for(int i=0;i<nums.size();i++){
        sum = 0;
        for(int j=i;j<nums.size();j++){
            sum += nums[j];
            if(sum == K) count++;
        }
    }
    cout << count;
}

/**
 * @brief Optimal solution
 * TC: O(N * 1) - for unordered map, 1 in best and avg case, O(N * N) for worst case - in case of collision
 * @note TC: O(N * log n) for ordered map
 * SC: O(N)
 * 
 * 
 */
void countSubarraySumK2(vector<int> nums, int K)
{
    int count = 0;
    unordered_map<int,int> prefixMap;
    int prefixSum = 0;
    prefixMap[0] = 1;
    for(int i=0;i<nums.size();i++){
        // adding current value to prefix sum
        prefixSum += nums[i];

        // calculate x-k
        int XminusKval = prefixSum - K;

        // adding count of XminusKval
        // as number of x-k found will be equivalent to sum of K found
        // reverse engineering
        count += prefixMap[XminusKval];

        // adding count of prefixSum
        prefixMap[prefixSum] +=1;
    }
    cout << count;
}

int main()
{
    vector<int> nums;
    int K = 6;
    // nums = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    nums = {3, 1, 2, 4};
    countSubarraySumK2(nums, K);
    cout << endl;
    return 0;
}