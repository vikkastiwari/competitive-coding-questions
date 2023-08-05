#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 3 sum
 * TC: O(N^3)*O(logn) - O(logn) for sorting
 * SC: O(2 * no. of the unique triplets) as we are using a set data structure and a list to store the triplets.
 * @param arr 
 * @return * vector<vector<int>> 
 */
vector<vector<int>> threeSumBrute(vector<int> arr){
    int n = arr.size();
    set<vector<int>> sumSet;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k] == 0){
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    // sorting it to make sure that only unique pairs are counted
                    sort(temp.begin(), temp.end());
                    sumSet.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> res(sumSet.begin(), sumSet.end());
    return res;

}   

/**
 * @brief threeSumBetter
 * TC: O(N^2 * log(no. of unique triplets)), where N = size of the array
 * SC: O(2 * no. of the unique triplets) + O(N) as we are using a set data structure 
 * and a list to store the triplets and extra O(N) for storing the array elements in another set.
 * 
 */
vector<vector<int>> threeSumBetter(vector<int> arr){
    int n = arr.size();
    int target = 0;
    set<vector<int>> sumSet;

    for(int i=0;i<n;i++){
        set<int> hash; // storing values only between i and j
        for(int j=i+1;j<n;j++){
            int diff = target - (arr[i] + arr[j]);
            if(hash.find(diff) != hash.end()){ // found
                vector<int> temp = {arr[i], arr[j], diff};
                sort(temp.begin(),temp.end());
                sumSet.insert(temp);
            }
            hash.insert(arr[j]);
        }   
    }

    vector<vector<int>> res(sumSet.begin(), sumSet.end());
    return res;
}

/**
 * @brief threeSumOptimal
 * TC: O(N^2 + log(no. of unique triplets)), where N = size of the array
 * SC: O(no. of the unique triplets) 
 */
vector<vector<int>> threeSumOptimal(vector<int> arr){
    int n = arr.size();
    int target = 0;
    int i = 0; // ith pointer will be fixed will only move j and k
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;
        int j = i+1, k = n-1;
        while(j<k ){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum == target){
                vector<int> temp = {arr[i], arr[j], arr[k]};
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
    return res;
}

int main()
{
    vector<int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSumOptimal(arr);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
        cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
