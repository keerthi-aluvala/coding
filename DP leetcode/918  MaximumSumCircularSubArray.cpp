/* 918. Maximum Sum Circular Subarray 

Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] 
is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], 
..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10

*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int max_sum=0,sum=0,min_sum=0;
        int maxx=INT_MIN;
        int minn=INT_MAX;
        for(int i=0; i<nums.size(); i++)
        {
            max_sum = max(max_sum+nums[i],nums[i]);
            min_sum = min(min_sum+nums[i],nums[i]);
            maxx = max(maxx,max_sum);
            minn = min(minn,min_sum);
            sum += nums[i];
        }
        if(sum==minn)
            return maxx;
        return max(maxx,sum-minn);
    }
};
