#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Brute Force Approach
 * TC: O(N) - N is size of array
 * SC: O(N) - N is number of distinct elements
 * @param nums 
 * @return * void 
 */
void freqMoreThanNby2Sol1(vector<int> nums)
{
    unordered_map<int, int> freq;
    int max = 0;
    for(int i=0;i<nums.size();i++){
        freq[nums[i]]++;
    }
    for(auto itr : freq){
            if(itr.second > max && itr.second > nums.size()/2){
            max = itr.first;
        }
    }
    cout << max << endl;
}

/**
 * @brief Optimal Approach - Moore's Voting Algorithm
 * TC: O(N) + O(N) - N is size of array
 * SC: O(1)
 * @param nums 
 * @return * void 
 */
void freqMoreThanNby2Sol2(vector<int> nums)
{
    int ct = 0, el;
    for(int i=0;i<nums.size();i++){
        if(ct == 0){
            el = nums[i];
            ct++;
        }else if(el == nums[i]){
            ct++;
        }else{
            ct--;
        }
    }

    /**
     * If in question it is assumed that majority element 
     * always be present then no need of below iterationa 
     * and check of n/2
     */ 
    int max_ct = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] == el) max_ct++;
    }
    if(max_ct > nums.size()/2){
        cout << el << endl;
    }else{
        cout << "Majority Element Not Found" << endl;
    }
}


int main()
{
    vector<int> arr = {2,2,1,1,1,2,2};
    freqMoreThanNby2Sol2(arr);
    return 0;
}