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
int firstOccurance(vector<int> arr, int target){
    int low = 0 , high = arr.size()-1;
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
 * @brief binary search approach
 * TC: O(logn)
 * SC: O(1)
 * 
 * @param arr 
 * @param target 
 * @return * int 
 */
int lastOccurance(vector<int> arr, int target){
    int low = 0 , high = arr.size()-1;
    int occurance = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid]==target){
            occurance = mid;
            low = mid + 1;
        }else if(arr[mid]>target){
            high = mid-1;
        }else{
            low = mid + 1;
        }
    }
    return occurance;
}

/**
 * @brief count occurance
 * TC: O(2^logn)
 * SC: O(1)
 * 
 * @param arr 
 * @param target 
 * @return * int 
 */
int countOccurance(vector<int> arr, int target){
    int firstOc = firstOccurance(arr,target);
    int lastOc = lastOccurance(arr,target);
    if(firstOc == -1) return -1;
    return lastOc - firstOc + 1;
}

int main(){
    vector<int> arr = { 2, 2 , 3 , 3 , 3 , 3 , 4 };
    int target = 1;
    cout << countOccurance(arr, target) << endl;
    return 0;
}