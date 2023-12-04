#include <bits/stdc++.h>
using namespace std;

int hashh[1000000]={0};

void computeHash(int arr[], int n){
    for(int i=0;i<n;i++){
        hashh[arr[i]] += 1;
    }
}

void frequency(int arr[], int n){
    unordered_map<int, int> map;
    int max = 0;
    int min = n;
    for(int i=0;i<n;i++)
        map[arr[i]]++;
    
    for(auto itr : map){
        cout << itr.first << itr.second << endl;
        if(itr.second > max) max = itr.second;
        if(itr.second < min) min = itr.second;
    }
    cout << "max: " << max << endl;
    cout << "min: " << min << endl;
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

    /*
    * count min and max frequency
    */
    int arr[] = { 1, 1, 1, 1, 1, 2, 1, 1, 3, 4, 3 };
    frequency(arr,sizeof(arr) / sizeof(arr[0]));
    return 0;
}