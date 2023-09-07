#include <bits/stdc++.h>
using namespace std;

/**
 * @brief returns multiplcation of number(mid) n times
 * TC: O(n)
 * SC: O(1)
 * 
 * @param mid 
 * @param n 
 * @param m 
 * @return int - compares ans with m and returns respective value
 * 0 - not found
 * 1 - found
 * 2 - found greater num then required
 */
int func(int mid, int n, int m) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

/**
 * @brief binary search approach
 * TC: O(logn)
 * SC: O(1)
 * 
 * @param n nth root
 * @param m root ke andar ka number
 * @return * void 
 */
void findNthSquareRoot(int n, int m){
    int low = 1, high = m;
    while(low<=high){
        int mid = (low+high)/2;
        int midXn = func(mid,n,m);

        if(midXn == 1) {
            cout << mid << endl;
            return;
        }
        if(midXn == 0){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << -1 << endl;
}

int main(){
    // int n = 3, m = 216;
    int n = 4, m = 10000;
    findNthSquareRoot(n,m);
    return 0;
}