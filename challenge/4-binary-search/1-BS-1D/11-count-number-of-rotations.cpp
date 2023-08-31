#include <bits/stdc++.h>
using namespace std;

// Find number of rotations in rotated sorted array
// position of minVal will give you number of rotation made

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
    int index = -1;   
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[low]<=arr[high]){
            if(arr[low]<minVal){
                minVal = arr[low];
                index = low;
                break;
            }
        }
        // if left part is sorted
        if(arr[low] <= arr[mid]){
            // take min
            if(arr[low]<minVal){
                minVal = arr[low];
                index = low;
            }
            // eliminate left part and consider right part
            low = mid + 1;
        }else { // if right part is sorted
            // take min
            if(arr[mid]<minVal){
                minVal = arr[mid];
                index = low;
            }
            // eliminate right part and consider left part
            high = mid - 1;
        }
    }
    return index;
}

int main(){
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6 };
    cout << findMinElement(arr) << endl;
    return 0;
}