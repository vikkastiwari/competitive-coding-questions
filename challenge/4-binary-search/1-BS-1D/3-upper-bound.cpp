#include <bits/stdc++.h>
using namespace std;

/**
 * Question: The upper bound algorithm finds the first or the 
 * smallest index in a sorted array where the value at that 
 * index is greater than the given key i.e. x.
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
void findUpperBound(vector<int> arr, int target){
    int low = 0 , high = arr.size()-1;
    int res = high;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid]>target){
            res = mid;
            high = mid-1;
        }else{
            low = mid + 1;
        }
    }
    cout << res << endl;
}

int main(){
    vector<int> arr = { 1,1,1,1,1 };
    int target = 1;
    findUpperBound(arr,target);
    return 0;
}