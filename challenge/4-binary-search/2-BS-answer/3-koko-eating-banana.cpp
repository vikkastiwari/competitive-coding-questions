#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &arr) {
    int maxEl = INT_MIN;
    int n = arr.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxEl = max(maxEl, arr[i]);
    }
    return maxEl;
}

/**
 * @brief calculateTotalHours
 * 
 * @param v - vector
 * @param hourly - number of bananas koko eats hourly
 * @return * int - total hours rquired to finish eating all piles of banana
 */
double calculateTotalHours(vector<int> &v, int hourly) {
    double totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        // considering ceil value - as before finishing current pile with respect to hour allocated koko can't move to next one
        // eg: koko eats 2 bananas each hour
        // so koko will take 3 hours to finish 5 bananas in a pile
        // 2 bananas --> 1 hour
        // 2 bananas --> 1 hour
        // 1 bananas --> 1 hour --- before finishing this piles time koko can't move to other one

        // 5 bananas --> 3 hours
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

/**
 * @brief koko eating banana binary search approach - return min bananas to finish all piles in given time
 * TC: O(logn)
 * SC: O(1)
 * 
 * @param n nth root
 * @param m root ke andar ka number
 * @return * void 
 */
void eatMinBanana(vector<int> arr, int h){
    int low = 1; int high = findMax(arr);
    while(low<=high){
        int mid = (low+high)/2;
        double totalHrs = calculateTotalHours(arr,mid);
        if(totalHrs == h) {
            cout << mid << endl;
            return;
        }
        else if(totalHrs > h){
            /**
             * here when totalhrs > givenLimit
             * we will increase the number of bananas eaten hourly such that totalHrs can be reduced
             * and in this case we will consider right half and cutoff left part
             */
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }
    cout << -1 << endl;
}

int main(){
    vector<int> arr = {7, 15, 6, 3}; // arr[i] bananas in each pile
    int h = 8; // time limit to eat all bananas
    eatMinBanana(arr,h);
    return 0;
}