#include<bits/stdc++.h>
using namespace std;

/** 
 * It is correct but not efficient it is giving TLE
*/
void solve(int arr[], int n, int k) {
    if(k==0) return;
    int temp = arr[0]; 
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp; 
    solve(arr,n,k-1);
}

/**
 * line number 32 did all the trick
 * Here we reversed the array into two parts to generate required outcome
 * Note: for reverse we can use inbuilt function as well
 */
void reverse(vector<int>& arr, int start, int end)
{
    while (start <= end) {
        swap(arr[start], arr[end]);
        start++; end--;
    }
}

void rotateRight(vector<int>& arr, int n, int k)
{
    k=k%arr.size();
    reverse(arr, 0, n - k - 1);
    reverse(arr, n - k, n - 1);
    reverse(arr, 0, n - 1);
}

void rotate(vector<int>& nums, int n, int k) {
    rotateRight(nums, nums.size(), k);
}

int main() {
  vector<int> arr = {1,2,3,4,5};
  int n = arr.size();
  rotate(arr, n, 2);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}