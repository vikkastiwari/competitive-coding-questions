#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr,int low, int high, int target){
    if(low>high) return -1;

    int mid = (low+high)/2;
    if(arr[mid] == target) return mid;
    else if(arr[mid]>target) 
        return binarySearch(arr,low,mid-1,target);
    return binarySearch(arr,mid+1,high,target);
}

/**
 * @brief binary search recursive approach
 * TC: O(logn)
 * SC: O(1)
 * 
 * @param arr 
 * @param target 
 * @return * void 
 */
void findTarget(vector<int> arr, int target){
    cout << binarySearch(arr,0,arr.size()-1,target) << endl;
}

int main(){
    vector<int> arr = { 3, 4, 6, 7, 9, 12, 16, 17 };
    int target = 9;
    findTarget(arr,target);
    return 0;
}