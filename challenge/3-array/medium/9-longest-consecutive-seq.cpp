#include <bits/stdc++.h>
using namespace std;

/**
 * @brief better approach
 * TC: O(NlogN) + O(N)
 */
void longConsecutiveSeq(vector<int> arr) {
    int n = arr.size();
    sort(arr.begin(),arr.end());
    int current = INT_MIN;
    int count = 0;
    int maxlen = 1;
    for(int i=0;i<n;i++){
        if(arr[i]-1 == current){
            count+=1;
            current = arr[i];
        }else{
            count = 1;
            current = arr[i];
        }
        maxlen = max(maxlen,count);
    }
    cout << maxlen << endl;
}

/**
 * @brief optimal approach
 * TC: O(2*N)
 * SC: O(N)
 * 
 * @param arr 
 * @return * void 
 */
void longConsecutiveSeq2(vector<int> arr){
    if(arr.size() == 0) return;
    unordered_set<int> set;
    int n = arr.size();
    int longseq = 1; // min possible longseq will always be 1
    for(int i=0;i<n;i++){
        set.insert(arr[i]);
    }

    for(auto itr : set){
        /**
         * here we are trying to start from starting point and not from somewhere in between of seq
         * eg. 102 1 101 2 3 4 100
         * if 102 encountered we will search if 101 exists 
         *  if yes then it is not start in this sequence so will go to next one
         * 
         * now say you encountered 100 we will search 99 and it does not exist in current sequence
         * so 100 is the starting point and now we will proceed with finding long consecutive sequence
         */
        if(set.find(itr-1) == set.end()){
            int count = 1;
            int val = itr;
            // we will run loop until next consecutive element is found 
            while(set.find(val+1) != set.end()){
                val += 1;
                count += 1;
            }
            // store the max consecutive sequence
            longseq = max(longseq, count);
        }
    }
    cout << longseq << endl;
}

int main(){
    vector<int> n = {100, 200, 1, 3, 2, 4};
    longConsecutiveSeq2(n);
    return 0;
}