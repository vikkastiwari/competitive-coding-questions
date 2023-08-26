#include <bits/stdc++.h>
using namespace std;

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