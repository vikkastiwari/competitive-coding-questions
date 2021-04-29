// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#

#include <bits/stdc++.h>
using namespace std;

void sort012(int a[], int n)
{
    // code here 
    // int temp;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(a[i] > a[j]) temp = a[i], a[i] = a[j], a[j] = temp;
    //     }
    // }
    int low=0,mid=0;
    int high=n-1;
    int temp;
    for(int i=0;i<n;i++){
        if(a[mid]==0){ // for 0
            temp=a[mid];
            a[mid]=a[low];
            a[low]=temp;
            low++;
            mid++;
        }else if(a[mid]==2){ // for 2
            temp=a[mid];
            a[mid]=a[high];
            a[high]=temp;
            high--;
        }else{ // for 1
            mid++;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int low=0,mid=0,high=n-1;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        sort012(a,n);
        for(int i=0;i<n;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}