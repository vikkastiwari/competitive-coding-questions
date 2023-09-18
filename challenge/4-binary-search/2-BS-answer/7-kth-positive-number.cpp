#include <bits/stdc++.h>
using namespace std;

/**
 * @problem  You are given a strictly increasing array ‘vec’ and a positive integer ‘k’. Find the ‘kth’ positive integer missing from ‘vec’.
 */


bool isPresent(vector<int> arr, int number){
    for(int i=0;i<arr.size();i++){
        if(arr[i] == number) return true;
    }
    return false;
}

/**
 * @brief Bruteforce approach 1
 * TC: O(n^2)
 * SC:O(1)
 * @note it has restriction upto maxelement of array
 * 
 * @param arr 
 * @param k
 * @return * int 
 */
int kthMissingNumberB1(vector<int> arr, int k) {
    vector<int> res;
    int maxNumber = *max_element(arr.begin(), arr.end());
    for(int i=1;i<=maxNumber;i++){
        if(!isPresent(arr,i)){
            res.push_back(i);
        }
    }
    return res[k-1];
}

/**
 * @brief brute force 2
 * TC: O(n)
 * SC:O(1)
 * 
 * @param arr 
 * @param k
 * @return * int 
 */
int kthMissingNumberB2(vector<int> arr, int k) {
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=k) k++;
        else break;
    }
    return k;
}

/**
 * @brief binary search optimised using maths
 * TC: O(logn)
 * SC:O(1)
 * 
 */
int kthMissingNumberO(vector < int > vec, int k) {
    int n = vec.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return k + high + 1;
}

int main(){
    vector<int> arr = { 1,2,3,4 }; 
    int k = 1; // kth missing number
    int ans = kthMissingNumberO(arr, k);
    cout << ans << endl;
    return 0;
}