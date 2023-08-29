#include <bits/stdc++.h>
using namespace std;

// Now duplicate elements will be present in the array

/**
 * @brief search element more optimized
 * TC: O(logn)
 * SC: O(1)
 * 
 * @param arr 
 * @param target 
 * @return * int 
 */
int searchElement2(vector<int> arr, int target){
    int low = 0 , high = arr.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid]==target) return mid;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low += 1;
            high -= 1;
            continue;
        }

        // if left part is sorted
        if(arr[low] <= arr[mid]){
            // if element exists move high pointer to left of mid
            if(arr[low]<=target && target<=arr[mid]){
                high = mid-1;
            } // if element doesn't exists in left part move low pointer to right of mid - right part is considered
            else{ 
                low = mid+1;
            }
        // if right part is sorted
        }else{ // (arr[mid] < arr[high])
            // if element exists move low pointer to right of mid
            if(target >= arr[mid] && target<=arr[high]){
                low = mid+1;
            } // if element doesn't exists in right part move high pointer to left of mid - left part is considered
            else{ 
                high = mid-1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6 };
    int target = 3;
    cout << searchElement2(arr, target) << endl;
    return 0;
}