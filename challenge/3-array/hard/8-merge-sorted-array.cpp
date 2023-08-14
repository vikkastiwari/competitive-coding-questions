#include <bits/stdc++.h>
using namespace std;

/**
 * @brief merge sorted array
 * TC: O(n)
 * SC:O(n)
 * 
 * @param arr1 
 * @param arr2 
 * @return * void    
 */
void mergeSortedArray(vector<int> &arr1,vector<int> &arr2){
    vector<int> temp;

    int p1 = 0, p2 = 0;
    while(p1<arr1.size() && p2 < arr2.size()){
        if(arr1[p1] < arr2[p2]){
            temp.push_back(arr1[p1]);
            p1++;
        }else if(arr1[p1]>arr2[p2]){
            temp.push_back(arr2[p2]);
            p2++;
        }else{
            temp.push_back(arr1[p1]);
            p1++;
        }
    }

    while(p1<arr1.size()) temp.push_back(arr1[p1++]);
    while(p2<arr2.size()) temp.push_back(arr2[p2++]);

    for(int i=0;i<temp.size();i++){
        if(i<arr1.size()) arr1[i] = temp[i];
        else {
            arr2[i-arr2.size()] = temp[i];
        }
    }
}   

/**
 * @brief Optimal 1 - two pointer method
 * 
 * @param arr1 
 * @param arr2 
 * @return * void 
 */
void mergeSortedArrayOptimal(vector<int> &arr1,vector<int> &arr2){
    int pt1=arr1.size()-1, pt2=0;

    while(pt1>=0 && pt2<arr2.size()){
        if(arr1[pt1]>arr2[pt2]){
            swap(arr1[pt1],arr2[pt2]);
            pt1--; pt2++;
        }else if(arr1[pt1]<=arr2[pt2]) {
            break;
        }
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
}

/**
 * @brief Optimised approach - two pointer method
 * push array 2 into array 1 and then sort it
 * 
 * @param arr1 
 * @param m 
 * @param arr2 
 * @param n 
 * @return * void 
 */
void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    
    while (j >= 0) {
        if (i >= 0 && arr1[i] > arr2[j]) {
            arr1[k--] = arr1[i--];
        } else {
            arr1[k--] = arr2[j--];
        }
    }
}

/**
 * @brief optimal approach using gap method - internally it uses shell sort
 * 
 * @return * int 
 */

void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void mergeSortedAr(vector<int> &arr1, vector<int> &arr2, int n, int m) {
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap: 
    // + (len % 2) convert's it into ceil
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}


int main()
{
    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};

    mergeSortedAr(arr1, arr2, arr1.size(), arr2.size());

    for(int i=0;i<arr1.size();i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    for(int j=0;j<arr2.size();j++){
        cout << arr2[j] << " ";
    }
    cout << endl;
    return 0;
}
