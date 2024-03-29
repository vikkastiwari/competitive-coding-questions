#include <bits/stdc++.h>
using namespace std;

/**
 * @brief binary search approach
 * TC: O(logn)
 * SC: O(1)
 * 
 * @param arr 
 * @param target 
 * @return * int 
 */
int bs(vector<int> arr, int low, int high, int target){
    int occurance = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid]==target){
            occurance = mid;
            high = mid - 1;
        }else if(arr[mid]>target){
            high = mid-1;
        }else{
            low = mid + 1;
        }
    }
    return occurance;
}

/**
 * @brief search element
 * TC: O(2logn)
 * SC: O(1)
 * 
 * @param arr 
 * @param target 
 * @return * int 
 */
int searchElement(vector<int> arr, int target){
    int breakPoint = 0;
    if(arr[breakPoint] == target) return breakPoint;

    for(int i=1;i<arr.size();i++){
        if(arr[i-1]>arr[i]) breakPoint = i;
    }
    if(breakPoint != -1){
        int part1 = bs(arr, 0, breakPoint-1, target);
        int part2 = bs(arr, breakPoint, arr.size()-1, target);
        return part1 != -1 ? part1 : part2;
    }
    return bs(arr, 0, arr.size()-1, target);
}

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
    vector<int> arr = { 7, 8, 1, 2, 3, 4, 5, 6 };
    int target = 0;
    cout << searchElement2(arr, target) << endl;
    return 0;
}