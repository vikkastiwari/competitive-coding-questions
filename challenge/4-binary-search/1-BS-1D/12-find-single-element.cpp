#include <bits/stdc++.h>
using namespace std;

/**
 * @brief find single element more optimized
 * TC: O(logn)
 * SC: O(1)
 * 
 * @param arr 
 * @param target 
 * @return * int 
 */
int findMinElement(vector<int> arr){
    if(arr.size() == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[arr.size()-1] != arr[arr.size()-2]) return arr[arr.size()-1];

    int low = 1 , high = arr.size()-2;
    int res;
    while(low <= high){
        int mid = (low+high)/2;
        if((arr[mid+1] != arr[mid]) && (arr[mid] != arr[mid-1])){
            return arr[mid];
        }
        if((mid % 2 == 1 && arr[mid] == arr[mid - 1])
                || (mid % 2 == 0 && arr[mid] == arr[mid + 1])){
            low = mid+1; // move to right part
        }else{
            high = mid-1; // move to left part
        }
    }
    return res;
}

int main(){
    vector<int> arr = {1,1,2,2,3,3,4,4,5,6,6};
    cout << findMinElement(arr) << endl;
    return 0;
}