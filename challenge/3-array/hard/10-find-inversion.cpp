#include <bits/stdc++.h>
using namespace std;

void countInversions(vector<int> arr) {
    int count = 0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[i]) count++;
        }
    }
    cout << count << endl;
}

int main()
{
    vector<int> arr = {5,3,2,1,4};
    countInversions(arr);
    return 0;
}
