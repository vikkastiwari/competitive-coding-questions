#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector <long long> NSL(long long arr[], int n) // nearest smaller to left
    {
       // Your code here
       vector<long long> left;
        stack<pair<long long,long long>> s;
        int pseudoIndex = -1;
        
        for(int i=0;i<n;i++){
            if(s.size() == 0){
                left.push_back(pseudoIndex);
            }else if(s.size()>0 && s.top().first<arr[i]){
                left.push_back(s.top().second);
            }else if(s.size()>0 && s.top().first>=arr[i]){
                while(s.size()>0 && s.top().first>=arr[i]){
                    s.pop();
                }
                if(s.size()==0){
                    left.push_back(pseudoIndex);
                }else{
                    left.push_back(s.top().second);
                }
            }
            s.push({arr[i],i});
        }
        return left;
    }
    
    vector <long long> NSR(long long arr[], int n) // nearest smaller to right
    {
       // Your code here
       vector<long long> right;
        stack<pair<long long,long long>> s;
        int pseudoIndex = n;
        
        for(int i=n-1;i>=0;i--){
            if(s.size() == 0){
                right.push_back(pseudoIndex);
            }else if(s.size()>0 && s.top().first<arr[i]){
                right.push_back(s.top().second);
            }else if(s.size()>0 && s.top().first>=arr[i]){
                while(s.size()>0 && s.top().first>=arr[i]){
                    s.pop();
                }
                if(s.size()==0){
                    right.push_back(pseudoIndex);
                }else{
                    right.push_back(s.top().second);
                }
            }
            s.push({arr[i],i});
        }
        reverse(right.begin(),right.end());
        return right;
    }
    
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long> width;
        vector<long long> area;
        
        vector<long long> i_nsl = NSL(arr,n);
        vector<long long> i_nsr = NSR(arr,n);
        
        for(int i=0;i<n;i++){
            width.push_back(i_nsr[i]-i_nsl[i]-1);
            area.push_back(width[i]*arr[i]);
        }
            
        return *max_element(area.begin(), area.end());
    }
};

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}