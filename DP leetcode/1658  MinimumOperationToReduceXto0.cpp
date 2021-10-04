/* 1658. Minimum Operations to Reduce X to Zero 

You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost 
or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array 
for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1

*/

class Solution {
public:
    unordered_map<string,int>m;
    int solve(vector<int>&nums, int x, int l, int r, int count)
    {
        if(x==0)
            return count;
        if(x<0 || l>r)
            return 1e6;
        string key = to_string(l)+"*"+to_string(r)+"*"+to_string(x);
        if(m.find(key)!=m.end())
            return m[key];
        int left = solve(nums, x-nums[l], l+1, r, count+1);
        int right = solve(nums, x-nums[r], l, r-1, count+1);
        
        return m[key]=min(left, right);
    }
    int minOperations(vector<int>& nums, int x) 
    {
        int n = nums.size()-1;
        int ans = solve(nums, x, 0, n, 0);
        return ans==1e6?-1:ans;
    }
};
