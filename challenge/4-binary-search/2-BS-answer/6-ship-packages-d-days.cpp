#include <bits/stdc++.h>
using namespace std;

/**
 * @problem Find out the least-weight capacity so that you can ship all the packages within ‘d’ days.
 */

int sumOfWeights(vector<int> arr){
    int sum = 0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
    }
    return sum;
}

/**
 * @brief Find the number of days with respect to capacity
 */
int findDays(vector<int> weights, int capacity){
    // ‘days’(representing the required days) 
    // ‘load’ (representing the loaded weights in the ship)
    int days = 1, load = 0;
    for(int i=0;i<weights.size();i++){
        if(load+weights[i]>capacity){
            days += 1;
            // initilaize load with current weight for next iteration
            load = weights[i]; 
        }else{
            load += weights[i]; // load added in ship
        }
    }
    return days;
}

/**
 * @brief Bruteforce approach 
 * TC: O(N * (sum(arr[])-max(arr[])+1))
 * SC:O(1)
 * 
 * @param arr 
 * @param d 
 * @return * int 
 */
int shipPackages(vector<int> arr, int d) {
    // min possible capacity of ship
    int maxWeight = *max_element(arr.begin(), arr.end());
    // max possible capacity of ship
    int sumWeight = sumOfWeights(arr);
    // alternative - int sum = accumulate(weights.begin(), weights.end(), 0);

    for(int i=maxWeight;i<=sumWeight;i++){
        int days = findDays(arr,i);
        if(days<=d) return i;
    }
    return -1;
}

/**
 * @brief binary search approach where we iterate from minPossibleWeights to maxPossibleWeights
 * TC: O(logn)
 * SC:O(1)
 * 
 * @param arr 
 * @param d
 * @return * int 
 */
int shipPackages2(vector<int> arr, int d) {
    int maxWeights = *max_element(arr.begin(), arr.end());
    int sumWeights = accumulate(arr.begin(), arr.end(), 0);

    int low = maxWeights, high = sumWeights;
    while(low<=high){
        int mid = (low+high) / 2;
        int days = findDays(arr,mid);
        if(days <= d){ // when found we will move to left of array in search of min possible val
            high = mid - 1;
        }else{ // when not found we will move to right in search of possibilities 
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = { 5,4,5,2,3,4,5,6 }; 
    int numOfDays = 5;
    int ans = shipPackages2(arr, numOfDays);
    cout << ans << endl;
    return 0;
}