#include <bits/stdc++.h>
using namespace std;

/**
 * @brief constraints 
 * n == nums.length
 * 1 <= n <= 104
 * 0 <= nums[i] <= n
 * All the numbers of nums are unique.
 * @param nums 
 */

/**
 * Naive Approach
 * Time complexity: O(NlogN) + O(N)
 * Space Complexity: O(N)
 */
void findMissingSol1(vector<int> nums){
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        if(i!=nums[i]) {
            cout << i;
            return;
        }
    }
    cout << nums[nums.size()-1]+1;
}

/**
 * Better Approach
 * Time complexity: O(N) + O(N)
 * Space Complexity: O(N)
 */
void findMissingSol2(vector<int> nums){
    vector<int> hash = {0};
    for(int i=0;i<nums.size();i++){
        hash[nums[i]]++;
    }
    for(int i=0;i<nums.size();i++){
        if(hash[i] != 1) {
            cout << i;
            return;
        }
    }
    cout << nums[nums.size()-1]+1;
}

/**
 * Optimal Approach
 * Time complexity: O(N)
 * Space Complexity: O(1)
 * 
 * 1. Summation approach
 * 2. XOR(^) approach
 */
void findMissingSol3(vector<int> nums){
    int sum1 = 0, sum2 = 0;
    int n = nums.size();
    sum2 = n*(n+1)/2;
    for(int i=0;i<nums.size();i++){
        sum1 += nums[i];
    }
    cout << sum2 - sum1;
}

int main(){
    vector<int> nums;
    // nums = { 0,1,2,3,4,5 }; // op: 6
    nums = { 1 }; // op: 0
    // nums = { 0,1,2,4,5 }; // op: 3
    findMissingSol3(nums);
    cout << endl;
    return 0;
}