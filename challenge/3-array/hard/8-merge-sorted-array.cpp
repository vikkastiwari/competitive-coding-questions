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
 * @brief Optimised approach
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

int main()
{
    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};

    mergeSortedArray(arr1, arr2);
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
