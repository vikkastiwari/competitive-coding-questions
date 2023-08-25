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
void lastOccurance(vector<int> arr, int target){
    int low = 0 , high = arr.size()-1;
    int last = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid]==target){
            last = mid;
            low = mid + 1;
        }else if(arr[mid]>target){
            high = mid-1;
        }else{
            low = mid + 1;
        }
    }
    cout << last << endl;
}

int main(){
    vector<int> arr = { 1,2,4,6,7 };
    int target = 6;
    lastOccurance(arr,target);
    return 0;
}