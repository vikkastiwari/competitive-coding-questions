#include <bits/stdc++.h>
using namespace std;

// Find min in rotated sorted array

/**
 * @brief search element more optimized
 * TC: O(logn)
 * SC: O(1)
 * 
 * @param arr 
 * @param target 
 * @return * int 
 */
int findMinElement(vector<int> arr){
    int low = 0 , high = arr.size()-1;
    int minVal = INT_MAX;   
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[low]<=arr[high]){
            minVal = min(minVal,arr[low]);
            break;
        }
        // if left part is sorted
        if(arr[low] <= arr[mid]){
            // take min
            minVal = min(minVal,arr[low]);
            // eliminate left part and consider right part
            low = mid + 1;
        }else { // if right part is sorted
            // take min
            minVal = min(minVal,arr[mid]);
            // eliminate right part and consider left part
            high = mid - 1;
        }
    }
    return minVal;
}

int main(){
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6 };
    cout << findMinElement(arr) << endl;
    return 0;
}