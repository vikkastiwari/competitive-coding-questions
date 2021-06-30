// question link: https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        // Your code goes
        sort(arr.begin(), arr.end());
        vector<vector<int>> pairs;
        for (int i = 0; i < arr.size() - 3; i++)
        {
            for (int j = i; j < arr.size() - 2; j++)
            {
                int low = j + 1;
                int high = arr.size() - 1;
                vector<int> temp;
                while (low < high)
                {
                    if (arr[i] + arr[j] + arr[low] + arr[high] == k)
                    {
                        temp.assign({arr[i], arr[j], arr[low], arr[high]});
                        pairs.push_back(temp);
                        temp.clear();
                        low++;
                        high--;
                    }
                    if (arr[i] + arr[j] + arr[low] + arr[high] < k)
                    {
                        low++;
                    }
                    else
                    {
                        high--;
                    }
                }
            }
        }
        return pairs;
    }
};