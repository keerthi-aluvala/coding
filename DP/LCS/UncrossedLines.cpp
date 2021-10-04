/* 1035. Uncrossed Lines 

We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:

nums1[i] == nums2[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting 
line.

Return the maximum number of connecting lines we can draw in this way.

 

Example 1:


Input: nums1 = [1,4,2], nums2 = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from nums1[1]=4 to nums2[2]=4 will intersect the line from 
nums1[2]=2 to nums2[1]=2.

*/


class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int dp[len1+1][len2+1];
        for(int i=0; i<=len1; i++)
        {
            for(int j=0; j<=len2; j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(nums1[i-1]==nums2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[len1][len2];
    }
};
