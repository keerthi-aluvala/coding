/* 53. Maximum Subarray Leetcode 

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and 
return its sum.

 
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>sums(n,0);
        sums[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            sums[i] = max(nums[i]+sums[i-1],nums[i]);
        }
        return *max_element(sums.begin(),sums.end());
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int currsum, maxsofar;
        currsum = maxsofar = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            currsum = max(nums[i]+currsum,nums[i]);
            maxsofar = max(maxsofar, currsum);
        }
        return maxsofar;
    }
};
