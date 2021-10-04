/* 15. 3Sum   - Medium

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []

*/



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0; i<n-2; i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int j=i+1, k=n-1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<0) j++;
                else if(sum>0) k--;
                else
                {
                    vector<int>temp{nums[i],nums[j],nums[k]};
                    v.push_back(temp);
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;
                    j++;
                    k--;
                }
            }
        }
        return v;
    }
};
