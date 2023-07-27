#include <bits/stdc++.h>
using namespace std;

/**
      1
     212
    32123
   4321234
  543212345
 65432123456
7654321234567

*/
void printPattern(int n){
    for(int i=n-1; i>=0;i--){
        for(int j=0;j<i;j++){
            cout << " ";
        }
        for(int j=n-i;j>0;j--){
            cout << j;
        }
        for(int j=1;j<=n-i-1;j++){
            cout << j+1;
        }
        cout << endl;
    }
}

void printPattern2(int n){
    for(int i=n-1; i>=0;i--){
        for(int j=0;j<i;j++){
            cout << " ";
        }
        for(int j=0;j<n-i;j++){
            cout << j+1;
        }
        for(int j=n-i-1;j>0;j--){
            cout << j;
        }
        cout << endl;
    }
}

int powerNum(int n, int k, int ans){
    while(k>0){
        ans = ans*n;
        k--;
        powerNum(n,k,ans); 
    }
    return ans;
}

int removeOdd(vector<int> &arr){
    int i=0,j=1;
    int n = arr.size();
    while(i<n && j<n){
        if(arr[i]%2!=0 && arr[j]%2==0){
            swap(arr[i],arr[j]);
            i++;j++;
        }else if(arr[i]%2==0 && arr[j]%2!=0){
            i++;
        }else if(arr[i]%2!=0 && arr[j]%2!=0){
            j++;
        }else if(arr[i]%2==0 && arr[j]%2==0){
            i++;j++;
        }
    }
    return i;
}

int main()
{
    int n = 2;
    int k = 3;
    // vector<int> arr = {4,1,2,2,5,8,1,0,3,9,6};
    vector<int> arr = {4,2,2,8,1};
    // cout << powerNum(n,k,1) << endl;
    int oddCount = arr.size() - removeOdd(arr);
    for(int i=0;i<arr.size()-oddCount;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}