#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Time Compleixty : O((m+n)log(m+n))
 * Inserting an element in a set takes logN time, where N is no of elements in the set
 * max set can store m+n elements - nums1 & nums2 contains all distinct elements
 * To insert m+n elements will take O((m+n)log(m+n))
 * @param nums1 
 * @param nums2 
 */
void findUnionSol1(vector<int> nums1, vector<int> nums2)
{
    set<int> unionn;
    int n;

    if(nums1.size() > nums2.size()) n = nums1.size();
    else n = nums2.size();

    for(int i=0;i<n; i++){
        /**
         * @brief The check unionn.find(nums2[i]) == unionn.end() is not required 
         * set wont insert already exisiting elements
         * Incase you want to add check we can add it like below
         */
        if(unionn.find(nums1[i]) == unionn.end() && i < nums1.size()){
            unionn.insert(nums1[i]);
        }
        if(unionn.find(nums2[i]) == unionn.end() && i < nums2.size()){
            unionn.insert(nums2[i]);
        }
    }
    for (auto itr : unionn){
        cout << itr << " ";
    }
    cout << endl;

    // map also can be utilised by tracking frequencies in both vectors
    // map<int, int> unionn;
    // for (int i = 0; i < n; i++)
    //     freq[arr1[i]]++;

}

/**
 * @brief We assumed that vectors are already in sorted order for this approach.
 * Hence we reduced the complexity from O((m+n)log(m+n)) to O(m+n)
 * Time Complexity: O(m+n)
 * Space Complexity : O(m+n)
 * @param nums1 
 * @param nums2 
 */

void findUnionSol2(vector<int> nums1, vector<int> nums2){
    vector<int> unionn = {};
    int n;

    int i = 0, j = 0 ;
    while(i<nums1.size() && j<nums2.size()){
        /**
         * @brief adding check nums1[i] != unionn[unionn.size()-1] to make sure
         * that no duplicate elements are pushed
         * NOTE: Add unionn.size() == 0 check such that you dont access unionn[-1] for unionn[unionn.size()-1]
         * else You will get segmentation error
         * checking last element only coz the vectors are already in sorted order
         * NOTE: inserting elements in unionn in sorted order wrt conditions
         */
        if(nums1[i]<=nums2[j]){
            if(unionn.size() == 0 || nums1[i] != unionn[unionn.size()-1])
                unionn.push_back(nums1[i]);
            i++;
        }else if(nums1[i] > nums2[j]){
            if(unionn.size() == 0 || nums2[j] != unionn[unionn.size()-1])
                unionn.push_back(nums2[j]);
            j++;
        }
    }
    while(i < nums1.size()){
        if(nums1[i] != unionn[unionn.size()-1]) unionn.push_back(nums1[i]);
        i++;
    }
    while(j < nums2.size()){
        if(nums2[j] != unionn[unionn.size()-1]) unionn.push_back(nums2[j]);
        j++;
    }

    for(int k=0;k<unionn.size();k++){
        cout << unionn[k] << " ";
    }
}

int main(){
    vector<int> nums1;
    vector<int> nums2;
    nums1 = { 1,2,3,4,5 };
    nums2 = { 2,3,4,4,5 };
    findUnionSol2(nums1, nums2);
    cout << endl;
    return 0;
}