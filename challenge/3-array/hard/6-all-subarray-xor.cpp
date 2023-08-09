#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Given an array of integers A and an integer B. 
 * Find the total number of subarrays having bitwise XOR of all elements equal to k.
 * 
 * TC: O(N^2)
 * SC: O(1)
 * 
 */
void longestSubarrayXor(vector<int> arr,int target){
    int n = arr.size();
    int xxor = 0, maxEl = 0, count = 0;

    for(int i=0;i<n;i++){
        xxor = 0;
        for(int j=i;j<n;j++){
            xxor ^= arr[j];
            if(xxor == target){
                count++;
            }
        }
    }   
    cout << count << endl;
}   

/**
 * @brief Optimal way - using hashing technique
 * TC: O(N)
 * SC: O(1)
 */
int longestSubarrayZeroSumOptimal(vector<int> arr, int target){
    int n = arr.size();
    unordered_map<int, int> hashMap;
    
    hashMap[0] = 1;
    int sum = 0, maxEl = 0, count = 0;
    for(int i=0;i<n;i++){
        sum ^= arr[i];
        int diff = sum ^ target; // only trick from + -> xor(^)
        if(hashMap.find(diff) != hashMap.end()){
            maxEl = max(maxEl, i - hashMap[diff]);
            count++;
        }else {
            hashMap[sum] =  i;
        }
    }
    return count;
}   

int main()
{
    // vector<int> arr = {4, 2, 2, 6, 4};
    // int k = 6;
    vector<int> arr = {5, 6, 7, 8, 9};
    int k = 5;
    longestSubarrayXor(arr,k);
    return 0;
}
