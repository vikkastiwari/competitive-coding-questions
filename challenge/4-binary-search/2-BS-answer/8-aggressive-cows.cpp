#include <bits/stdc++.h>
using namespace std;

/**
 * @problem  You are given an array ‘arr’ of size ‘n’ which denotes the position of stalls.
 * You are also given an integer ‘k’ which denotes the number of aggressive cows.
 * You are given the task of assigning stalls to ‘k’ cows 
 * such that the minimum distance between any two of them is as large as possible.
 * Find the maximum possible minimum distance.
 */

bool canWePlaceCows(vector <int> stalls, int k, int dist){
    int cntCows = 1;
    int lastVisitedStall = stalls[0];
    for(int i=1;i<stalls.size();i++){
        // It will check that two cows are placed apart from each other with min distance of dist
        if((stalls[i] - lastVisitedStall) >= dist){
            cntCows++;
            lastVisitedStall = stalls[i];
        }
        // The cows are placed with given dist
        if(cntCows >= k){
            return true;
        }
    }
    return false;
}

/**
 * @brief binary search optimised
 * TC: O(nlogn)
 * SC:O(1)
 * 
 */
int aggressiveCows(vector <int> stalls, int k) {
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());

    int minDistPossible, low = 1;
    int maxDistPossible, high = *max_element(stalls.begin(), stalls.end()) - *min_element(stalls.begin(), stalls.end());
    
    while(low<=high){
        int mid = (low+high)/2;
        if(canWePlaceCows(stalls,k,mid)){
            low = mid + 1;
        }else{
            high = mid - 1;
        }

    }
    
    return high;
}

int main(){
    // vector<int> arr = { 0,3,4,7,10,9 }; 
    // int k = 4; // number of cows
    vector<int> arr = {1,2,8,4,9 }; 
    int k = 3; // number of cows
    int ans = aggressiveCows(arr, k);
    cout << ans << endl;
    return 0;
}