/* 673. Number of Longest Increasing Subsequence 

Given an integer array nums, return the number of longest increasing subsequences.
Notice that the sequence has to be strictly increasing.

 
Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.


*/


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        if(n<=1) return n;
        vector<int>dp(n,1);
        vector<int>count(n,1);
        int result = INT_MIN;
        for(int j=1;j<n;j++)
        {
            for(int i=0; i<j; i++)
            {
                if(nums[j]>nums[i])
                {
                    if(dp[j]<dp[i]+1)
                    {
                        dp[j]=dp[i]+1;
                        count[j]=count[i];
                    }
                    else if(dp[j]==dp[i]+1)
                        count[j]=count[i]+count[j];
                }
            }
            result = max(result,dp[j]);
        }
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(dp[i]==result)
                ans+=count[i];
            cout<<count[i];
        }
        return ans;
    }
};

