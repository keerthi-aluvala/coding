/* 435. Non-overlapping Intervals 

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to 
remove to make the rest of the intervals non-overlapping.

 
Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) 
    {
        int n = a.size(), res=0;
        sort(a.begin(),a.end());
        for(int i=0; i<n-1; i++)
        {
            if(a[i][1]>a[i+1][0])
            {
                res++;
                a[i+1][1] = min(a[i][1],a[i+1][1]);
            }
        }
        return res;
    }
};


