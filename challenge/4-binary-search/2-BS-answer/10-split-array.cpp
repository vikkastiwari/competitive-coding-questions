#include <bits/stdc++.h>
using namespace std;

/**
 * @problem  Given an integer array nums and an integer k, 
 * split nums into k non-empty subarrays such that the largest 
 * sum of any subarray is minimized. 
 * Return the minimized largest sum of the split.
 * A subarray is a contiguous part of the array.
 */

int countPartitionSum(vector <int> arr, int k){
    int partitionSum = 1;
    int sumPerPartition = arr[0];

    for(int i=1;i<arr.size();i++){
        if((sumPerPartition+arr[i]) <= k){
            sumPerPartition += arr[i];
        }else{
            partitionSum += 1;
            sumPerPartition = arr[i];
        }
    }

    return partitionSum;
}

/**
 * @brief binary search
 * TC: O(logn)
 * SC:O(1)
 */
int findLargestSumMinPossible(vector <int> arr, int k) {
    int n = arr.size();
    if(k>n) return -1; // number of arr elements are greater than number of arr
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid = (low+high)/2;
        // if count of partitions are more then given
        // means we can assign more arr elements to each partition wrt given number of partitions
        if(countPartitionSum(arr,mid) > k) {
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = { 10, 20, 30, 40 }; 
    int s = 2; // number of partitions
    int ans = findLargestSumMinPossible(arr, s);
    cout << ans << endl;
    return 0;
}