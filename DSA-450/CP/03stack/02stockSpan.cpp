#include<bits/stdc++.h>
using namespace std;

class Solution
{
    // it is of the type of nearest greater element to left
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
        // Your code here
        vector<int> v;
        vector<int> res;

        // now in stack we will store a pair of (value,index) --> (arr[i],i)
        stack<pair<int,int>> s;
        
        for(int i=0;i<n;i++){
            if(s.size() == 0){
                v.push_back(-1);
            }else if(s.size()>0 && s.top().first>arr[i]){ // we will compare the value of arr with the value stored in stack
                v.push_back(s.top().second); // and we will store the index of the value where we find the nearest greater to left
            }else if(s.size()>0 && s.top().first<=arr[i]){
                while(s.size()>0 && s.top().first<=arr[i]){
                    s.pop();
                }
                if(s.size()==0){
                    v.push_back(-1);
                }else{
                    v.push_back(s.top().second);
                }
            }
            s.push({arr[i],i});
            // when we will subtract the index of nearest greater element from the current index in the array 
            // we will get the span of all the stocks which is  less than or equal to the current value on the given index
            res.push_back(i-v[i]);
        }
        return res;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}