#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        int i=0,j=0;
        vector<int> ans;
        list<int> l;
        
        // edge case when the size of the window is greater than the size of the array
        if(k>n){
            ans.push_back(*max_element(l.begin(),l.end()));
            return ans;
        }
        
        while(j<n){
            // if list contains value smaller than arr[j]
            // then it is of no use as we have to find max in a window
            // so the number smaller than arr[j] is never going to be considered as max
            // also we keep check for the size of our list
            while(l.size() > 0 && l.back()<arr[j]){
                l.pop_back();
            }
            // pushing the new value in the window
            l.push_back(arr[j]);
            
            // increasing j in order to hit the window size
            if ((j-i+1)<k) j++;
            // the case when we hit the window size
            else if (j-i+1==k)
            {
                // as we are removing the smaller values by
                // comparing to the latest j in arr.
                // so we will always find the max value of respective
                // window size at first position of the list
                ans.push_back(l.front());
                
                // when our max i.e l.front() becomes equal to the element
                // that we are removing from our current window(in case of window slide) in that case we want max
                // of other remaining elements in that window so that we can compare other incoming value i.e arr[j] when we slide the window
                // in order to get the max value in next window
                if(l.front() == arr[i]){
                    l.pop_front();
                }
                
                i++;
                j++;
            }
        }
        return ans;
    }
};

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}