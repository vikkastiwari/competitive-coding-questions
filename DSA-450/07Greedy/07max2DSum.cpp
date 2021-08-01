#include <bits/stdc++.h>
using namespace std;
#define M 4

int maxIncSum(int arr[][M], int n)
{
    for (int i = 0;i<n;i++)
    {
        sort(arr[i],arr[i]+M);
    }

    int sum=arr[n-1][M-1];
    int prevEl = arr[n-1][M-1];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = M-1;j>=0;j--){
            if(arr[i][j]<prevEl){
                sum+=arr[i][j];
                prevEl=arr[i][j];
                break;
            }
        }
        
    }
    if(j==-1)
        return 0;
}

int main()
{

    int arr[][4] = {{1, 7, 3, 4},
                    {4, 2, 5, 1},
                    {9, 5, 1, 8}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxIncSum(arr, n);
    return 0;
}