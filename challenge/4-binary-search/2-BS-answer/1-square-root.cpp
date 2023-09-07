#include <bits/stdc++.h>
using namespace std;

/**
 * @brief linear search approach
 * TC: O(n)
 * SC: O(1)
 * 
 * @param arr 
 * @param target 
 * @return * void 
 */
void findNearestSquareRoot(int num){
    int ans = 1;
   for(long long i=1;i<=num;i++){
       if(i*i < num*1ll){
           ans = i;
       }else{
           break;
       }
   }
   cout << ans << endl;
}

/**
 * @brief binary search approach
 * TC: O(logn)
 * SC: O(1)
 * 
 * @param arr 
 * @param target 
 * @return * void 
 */
void findNearestSquareRoot2(int num){
    long long low = 1, high = num;
    while(low<=high){
        long long mid = (low+high)/2;
        long long sq = mid*mid;

        if(sq <= num*1ll){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << high << endl;
}

int main(){
    int n = 36;
    findNearestSquareRoot2(n);
    return 0;
}