#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution{
  public:
  
    vector <int> NSL(vector<int> arr, int n) // nearest smaller to left
    {
       // Your code here
       vector<int> left;
        stack<pair<int,int>> s;
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
    
    vector <int> NSR(vector<int> arr, int n) // nearest smaller to right
    {
       // Your code here
       vector<int> right;
        stack<pair<int,int>> s;
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
    int MAH(vector<int> arr, int n)
    {
        // Your code here
        vector<int> width;
        vector<int> area;
        
        vector<int> i_nsl = NSL(arr,n);
        vector<int> i_nsr = NSR(arr,n);
        
        for(int i=0;i<n;i++){
            width.push_back(i_nsr[i]-i_nsl[i]-1);
        }

        for(int i=0;i<n;i++){
            area.push_back(width[i]*arr[i]);
        }
            
        return *max_element(area.begin(), area.end());
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int> v;
        for(int j=0;j<m;j++){
            v.push_back(M[0][j]);
        }
        int mx = MAH(v,v.size());
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==0) v[j]=0;
                else{
                    v[j] = v[j] + M[i][j];
                }
            }
            mx = max(mx, MAH(v,v.size()));
        }
        
        return mx;
    }
};

int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}