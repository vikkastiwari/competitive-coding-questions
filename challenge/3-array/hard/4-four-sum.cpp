#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 3 sum
 * TC: O(N^4)*O(logn) - O(logn) for sorting
 * SC: O(2 * no. of the quadruplets)) as we are using a set data structure and a list to store the triplets.
 * @param arr 
 * @return * vector<vector<int>> 
 */
vector<vector<int>> fourSumBrute(vector<int> arr){
    int n = arr.size();
    set<vector<int>> sumSet;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    if(arr[i]+arr[j]+arr[k]+arr[l] == 0){
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        // sorting it to make sure that only unique pairs are counted
                        sort(temp.begin(), temp.end());
                        sumSet.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> res(sumSet.begin(), sumSet.end());
    return res;

}   

/**
 * @brief fourSumBetter
 * TC: O(N^3 * log(no. of the quadruplets))), where N = size of the array
 * SC: O(2 * no. of the quadruplets) + O(N) as we are using a set data structure 
 * and a list to store the triplets and extra O(N) for storing the array elements in another set.
 * 
 */
vector<vector<int>> fourSumBetter(vector<int> arr){
    int n = arr.size();
    int target = 0;
    set<vector<int>> sumSet;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> hash; // storing values only between i and j
            for(int k=j+1;k<n;k++){
                int diff = target - (arr[i] + arr[j] + arr[k]);
                if(hash.find(diff) != hash.end()){ // found
                    vector<int> temp = {arr[i], arr[j], arr[k], diff};
                    sort(temp.begin(),temp.end());
                    sumSet.insert(temp);
                }
                hash.insert(arr[k]);
            }   
        }   
    }

    vector<vector<int>> res(sumSet.begin(), sumSet.end());
    return res;
}

/**
 * @brief fourSumOptimal
 * TC: O(N^3 + log(no. of the quadruplets)), where N = size of the array
 * SC: O(no. of the quadruplets) 
 */
vector<vector<int>> fourSumOptimal(vector<int> arr){
    int n = arr.size();
    int target = 0;
    int i = 0; // ith pointer will be fixed will only move j and k
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    for (int h = 0; h < n; h++) {
        //remove duplicates:
        if (h != 0 && arr[h] == arr[h - 1]) continue;

        for (int i = h+1; i < n; i++) {
        //remove duplicates:
            if (i != 0 && arr[i] == arr[i - 1]) continue;
            int j = i+1, k = n-1;
            while(j<k ){
                int sum = arr[h] + arr[i] + arr[j] + arr[k];
                if(sum == target){
                    vector<int> temp = {arr[h], arr[i], arr[j], arr[k]};
                    res.push_back(temp);
                    j++;k--;
                    
                    //  To skip the duplicate elements
                    while(j<k && arr[j]==arr[j-1]) j++;
                    while(j<k && arr[k]==arr[k+1]) k--;

                }else if(sum > target) {
                    k--;
                }else { // sum < target
                    j++;
                }
            }
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {1,0,-1,0,-2,2};
    vector<vector<int>> res = fourSumOptimal(arr);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
