#include <bits/stdc++.h>
using namespace std;

/**
 * @brief find peak element more optimized
 * TC: O(logn)
 * SC: O(1)
 * 
 * @param arr 
 * @param target 
 * @return * int 
 */
int findPeakElement(vector<int> arr){
    if(arr.size() == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[arr.size()-1] > arr[arr.size()-2]) return arr.size()-1;

    int low = 1 , high = arr.size()-2;
    while(low <= high){
        int mid = (low+high)/2;
        if((arr[mid+1] < arr[mid]) && (arr[mid] > arr[mid-1])){
            return mid;
        }
        if(arr[mid]>arr[mid-1]){
            low = mid+1; // move to right part
        }else{ // arr[mid] > arr[mid+1]
            high = mid-1; // move to left part
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,5,1};
    cout << findPeakElement(arr) << endl;
    return 0;
}