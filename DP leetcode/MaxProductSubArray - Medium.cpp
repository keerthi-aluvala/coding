/* 152. Maximum Product Subarray Leetcode Medium 

Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and 
return the product.

It is guaranteed that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

 
Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/


class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>maxDp(n);
        vector<int>minDp(n);
        maxDp[0] = minDp[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            if(nums[i]>0)
            {
                maxDp[i] = max(nums[i],maxDp[i-1]*nums[i]);
                minDp[i] = min(nums[i],minDp[i-1]*nums[i]);
            }
            else
            {
                maxDp[i] = max(nums[i],minDp[i-1]*nums[i]);
                minDp[i] = min(nums[i],maxDp[i-1]*nums[i]);
            }
        }
        return *max_element(maxDp.begin(),maxDp.end());
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();
        int maxDp = nums[0];
        int minDp = nums[0];
        int maxx = nums[0];
        for(int i=1; i<n; i++)
        {
            if(nums[i]>=0)
            {
                maxDp = max(nums[i],maxDp*nums[i]);
                minDp = min(nums[i],minDp*nums[i]);
            }
            else
            {
                int max_old_dp = maxDp;
                maxDp = max(nums[i],minDp*nums[i]);
                minDp = min(nums[i],max_old_dp*nums[i]);
            }
            maxx = max(maxx,maxDp);
        }
        return maxx;
    }
};


