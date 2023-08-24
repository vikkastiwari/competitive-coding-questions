#include <bits/stdc++.h>
using namespace std;

/**
 * Question: You are given a sorted array arr of distinct values and a target value x. 
 * You need to search for the index of the target value in the array.
 * 
 * If the value is present in the array, then return its index. Otherwise, determine the index where 
 * it would be inserted in the array while maintaining the sorted order.
 */

/**
 * @brief binary search approach
 * TC: O(logn)
 * SC: O(1)
 * 
 * @param arr 
 * @param target 
 * @return * void 
 */
void searchInsertPosition(vector<int> arr, int target){
    int low = 0 , high = arr.size()-1;
    int res = arr.size();
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid]>=target){
            res = mid;
            high = mid-1;
        }else{
            low = mid + 1;
        }
    }
    cout << res << endl;
}

int main(){
    vector<int> arr = { 1,2,4,7 };
    int target = 6;
    searchInsertPosition(arr,target);
    return 0;
}