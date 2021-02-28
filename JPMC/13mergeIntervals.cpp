// this is chunck of code that need to be compiled in leetcode code editor if compiled directly it will throw an  error
// for question link refer readme section in this folder
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;

        // sorting intervals
        sort(intervals.begin(), intervals.end());

        // keeping track of starting and ending of current interval
        int start = intervals[0][0], end = intervals[0][1];

        // starting from index 1 because we took first interval for comparison

        for (int i = 1; i < intervals.size(); ++i)
        {

            /* if starting of current interval is less then or equal to ending of last processed interval
            then will update end so that it could be considered as merged */
            if (intervals[i][0] <= end)
                end = max(end, intervals[i][1]);

            /* inserting interval which are merged and the intervals which cannot be merged
            and updating our start and end with the bounds of current interval*/
            else
            {
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        // adding last pair which is left because loop will terminate for last value
        result.push_back({start, end});
        return result;
    }
};