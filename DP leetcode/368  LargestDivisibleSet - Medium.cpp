/* 368. Largest Divisible Subset 

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) 
of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]

*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n,1), parent(n,-1), ans;
        sort(nums.begin(),nums.end());
        int idx=0, maxx=INT_MIN;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if((nums[i]%nums[j]==0 ||nums[j]%nums[i]==0) && dp[j]+1>dp[i])
                {
                    dp[i] = dp[j]+1;
                    parent[i] = j;
                }
            }
            if(maxx<dp[i])
            {
                maxx=dp[i];
                idx = i;
            }
        }
        while(idx!=-1)
        {
            ans.push_back(nums[idx]);
            idx=parent[idx];
        }
        return ans;
    }
};


