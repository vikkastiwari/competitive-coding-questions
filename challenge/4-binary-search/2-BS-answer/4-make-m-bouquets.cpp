#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &arr) {
    int maxEl = INT_MIN;
    int n = arr.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxEl = max(maxEl, arr[i]);
    }
    return maxEl;
}

int findMin(vector<int> &arr) {
    int minEl = INT_MAX;
    int n = arr.size();
    //find the min:
    for (int i = 0; i < n; i++) {
        minEl = min(minEl, arr[i]);
    }
    return minEl;
}

bool possible(vector<int> arr, int day, int m, int k){
    int cnt = 0;
    int countOfBouquets = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=day) 
            cnt++;
        else{
            countOfBouquets += floor(cnt/k); // number of possible bouquets with current found adjacent bloomed roses
            cnt = 0; // re-setting count as adjacent bloomed roses sequence is broken
        } 
    }
    // edge case to consider cnt when loop terminates
    countOfBouquets += floor(cnt/k);

    if(countOfBouquets >= m) return true;
    return false;
}

/**
 * @brief Brute force approach where we iterate from minDays to maxDays
 * TC: O(n)
 * SC:O(1)
 * 
 * @param arr 
 * @param m 
 * @param k 
 * @return * int 
 */
int makeMBouquets(vector<int> arr, int m, int k) {
    if(arr.size() < m*k) return -1;

    int maxDays = findMax(arr);
    int minDays = findMin(arr);
    for(int i=minDays;i<=maxDays;i++){
        int found = possible(arr,i,m,k);
        if(found) return arr[i];
    }
    return -1;
}

/**
 * @brief binary search approach where we iterate from minDays to maxDays
 * TC: O(logn)
 * SC:O(1)
 * 
 * @param arr 
 * @param m 
 * @param k 
 * @return * int 
 */
int makeMBouquets2(vector<int> arr, int m, int k) {
    long long val = m * 1ll * k * 1ll;
    
    if(arr.size() < val) return -1;

    int maxDays = findMax(arr);
    int minDays = findMin(arr);
    int low = minDays, high = maxDays;
    while(low<=high){
        int mid = (low+high) / 2;
        int found = possible(arr,mid,m,k);
        if(found){ // when found we will move to left of array in search of min possible days
            high = mid - 1;
        }else{ // when not found we will move to right in search of possibilities where it is possible to make m bouquets 
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    // vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7}; // rose will bloom on the ‘arr[i]th’ day
    // int m = 2, k = 3; // m - number of bouquets, k - number of roses in each bouquet
    vector<int> arr = {  83,98 }; // rose will bloom on the ‘arr[i]th’ day
    int m = 2, k = 1; // m - number of bouquets, k - number of roses in each bouquet
    int ans = makeMBouquets2(arr, m, k);
    cout << ans << endl;
    return 0;
}