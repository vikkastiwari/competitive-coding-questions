#include <bits/stdc++.h>
using namespace std;

int hashh[1000000]={0};

void computeHash(int arr[], int n){
    for(int i=0;i<n;i++){
        hashh[arr[i]] += 1;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    computeHash(arr,n);
    int q;
    cin >> q;
    while(q--){
        int num;
        cin >> num;
        cout << hashh[num] << endl;
    }
    return 0;
}