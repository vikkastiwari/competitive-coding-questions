#include<bits/stdc++.h>
using namespace std;

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int maxl[n];
        int maxr[n];
        
        for(int i=0;i<n;i++){
            if(i==0) maxl[i] = arr[i];
            else{
                int maxVal = std::max(maxl[i-1],arr[i]);
                maxl[i] = maxVal;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            if(i==n-1) maxr[i] = arr[i];
            else{
                int maxVal = std::max(maxr[i+1],arr[i]);
                maxr[i] = maxVal;
            }
        }
        
        long long sum = 0;
        for(int i=0;i<n;i++){
            arr[i] = min(maxl[i],maxr[i]) - arr[i];
            sum += arr[i];
        }
        
        return sum;
    }
};

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}