#include <bits/stdc++.h>
using namespace std;

/**
 * @problem  Given an array/list of length ‘N’, where the array/list 
 * represents the boards and each element of the given array/list 
 * represents the length of each boardUnits. Some ‘K’ numbers of painters 
 * are available to paint these boards. Consider that each unit of a 
 * boardUnits takes 1 unit of time to paint. You are supposed to 
 * return the area of the minimum time to get this job done of painting 
 * all the ‘N’ boards under the constraint that any painter will only 
 * paint the continuous sections of boards.
 */

int countPainters(vector <int> boards, int boardUnits){
    int numberOfPainters = 1;
    int boardsPerPainter = boards[0];

    for(int i=1;i<boards.size();i++){
        if((boardsPerPainter+boards[i]) <= boardUnits){
            boardsPerPainter += boards[i];
        }else{
            numberOfPainters += 1;
            boardsPerPainter = boards[i];
        }
    }

    return numberOfPainters;
}

/**
 * @brief brute force
 * TC: O(N * (sum(arr[])-max(arr[])+1))
 * SC:O(1)
 */
int allocateBoards(vector <int> boards, int s) {
    int n = boards.size();
    if(s>n) return -1; // number of Painters are greater than number of boards
    int minAllocPossible = *max_element(boards.begin(), boards.end());
    int maxAllocPossible = accumulate(boards.begin(),boards.end(),0);
    for(int boardUnits=minAllocPossible; boardUnits<=maxAllocPossible; boardUnits++){
        if(countPainters(boards,boardUnits) == s) {
            return boardUnits;
        }
    }
    return -1;
}

/**
 * @brief binary search
 * TC: O(logn)
 * SC:O(1)
 */
int paintBoardsOpt(vector <int> boards, int s) {
    int n = boards.size();
    if(s>n) return -1; // number of Painters are greater than number of boards
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(),boards.end(),0);
    while(low<=high){
        int mid = (low+high)/2;
        // if count of painters are more then given
        // means we can assign more boardUnits wrt given number of painters
        if(countPainters(boards,mid) > s) {
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {10, 20, 30, 40}; 
    int s = 2; // number of painters
    int ans = paintBoardsOpt(arr, s);
    cout << ans << endl;
    return 0;
}