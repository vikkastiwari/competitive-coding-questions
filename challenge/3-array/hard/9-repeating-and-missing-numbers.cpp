#include <bits/stdc++.h>
using namespace std;

// Find the repeating and missing numbers

/**
 * @brief Using set 
 * 
 * @param arr1 
 * @return * void 
 */
void repeatingAndMissingNum1(vector<int> &arr1) {
    set<int> setDist;
    vector<int> res;
    for(int i=0;i<arr1.size();i++){
        if(setDist.find(arr1[i]) == setDist.end()){
            setDist.insert(arr1[i]);
        }else {
            res.push_back(arr1[i]);
        }
    }
    for(int i=0;i<arr1.size();i++){
        if(setDist.find(i+1) == setDist.end()){
            res.push_back(i+1);
        }
    }
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    cout << endl;
}

/**
 * @brief Using hashing
 * 
 */
void repeatingAndMissingNum2(vector<int> &arr) {
    unordered_map<int, int> map(arr.size()+1);
    for (int i = 0; i < arr.size(); ++i) {
        map[i+1] = 0;
    }
    for(int i=0;i<arr.size();i++){
        map[arr[i]]++;
    }
    for(auto itr : map){
        if(itr.second == 0 || itr.second == 2){
            cout << itr.first << " ";
        }
    }
    cout << endl;
}

/**
 * @brief Using maths equation
 * 
 * @param a 
 * @return * void 
 */
void findMissingRepeatingNumbersOptimal(vector<int> a) {
    long long n = a.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    //S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    cout << (int)x << " " << (int)y << endl;
}

int main()
{
    vector<int> arr1 = {3,1,2,5,4,6,7,5};
    findMissingRepeatingNumbersOptimal(arr1);
    return 0;
}
