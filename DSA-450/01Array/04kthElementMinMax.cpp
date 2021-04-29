// Find the "Kth" max and min element of an array 
// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int k;
        cin >> k;
        sort(a,a+n);
        int min = a[k-1];
        cout << min << endl;
    }
    return 0;
}