#include <bits/stdc++.h>
using namespace std;

void countReversePairsBrute(vector<int> arr) {
    int count = 0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(2*arr[j]<arr[i]) count++;
        }
    }
    cout << count << endl;
}

/**
 * @brief Optimal solution using merge sort approach
 * @param arr 
 * @param low 
 * @param mid 
 * @param high 
 * @return * int 
 */
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

/**
 * @brief This is logic that counts pairs 
 * Left Array - low to mid
 * Right Array- mid+1 to high
 * TC: O(nlogn)
 */
int countPairs(vector<int> &arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2 * arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

/**
 * @brief This is logic merge sort
 * Left Array - low to mid
 * Right Array- mid+1 to high
 * TC: O(nlogn)
 * SC: O(n)
 */
int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += countPairs(arr, low, mid, high); //Modification
    merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

/**
 * @brief Optimal solution using merge sort 
 * TC: O(2*nlogn)
 * SC: O(n)
 * 
 * @param arr 
 * @return * void 
 */
void countReversePairsOptimal(vector<int> &arr) {
    cout << mergeSort(arr,0,arr.size()-1) << endl;
}

int main(){
    vector<int> arr = {1,3,2,3,1};
    countReversePairsBrute(arr);
    return 0;
}
