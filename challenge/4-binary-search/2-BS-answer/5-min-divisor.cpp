#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Find the Smallest Divisor Given a Threshold
 */

bool possible(vector<int> arr, int divisor, int limit){
    int divisorSum = 0;
    for(int i=0;i<arr.size();i++){
        divisorSum += ceil((double) (arr[i])/(double) (divisor));
    }
    if(divisorSum <= limit) return true;
    return false;
}

/**
 * @brief Bruteforce approach where we iterate from 1 to maxDays
 * TC: O(n)
 * SC:O(1)
 * 
 * @param arr 
 * @param m 
 * @param k 
 * @return * int 
 */
int findMinDivisor(vector<int> arr, int limit) {
    int maxDays = *max_element(arr.begin(), arr.end());
    for(int i=1;i<=maxDays;i++){
        int found = possible(arr,i,limit);
        if(found) return i;
    }
    return -1;
}

/**
 * @brief binary search approach where we iterate from 1 to maxDays
 * TC: O(logn)
 * SC:O(1)
 * 
 * @param arr 
 * @param m 
 * @param k 
 * @return * int 
 */
int findMinDivisor2(vector<int> arr, int limit) {
    int maxDays = *max_element(arr.begin(), arr.end());
    int low = 1, high = maxDays;
    while(low<=high){
        int mid = (low+high) / 2;
        int found = possible(arr,mid,limit);
        if(found){ // when found we will move to left of array in search of min possible val
            high = mid - 1;
        }else{ // when not found we will move to right in search of possibilities where it is possible to find min divisor 
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {  1,2,5,9 }; 
    int limit = 6;
    int ans = findMinDivisor2(arr, limit);
    cout << ans << endl;
    return 0;
}