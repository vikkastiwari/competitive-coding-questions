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

int main(){
    vector<int> arr = { 1,2,3,4 }; 
    int k = 1; // kth missing number
    int ans = kthMissingNumberB2(arr, k);
    cout << ans << endl;
    return 0;
}