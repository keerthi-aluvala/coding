/* 1464. Leetcode. Maximum Product of Two Elements in an Array 

	Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 

Example 1:

Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.

*/


// Time Complexity: O(n logn)
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        return (nums[n-1]-1)*(nums[n-2]-1);
    }
};

// Time Complexity: O(n log2)
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        priority_queue<int>maxheap;
        for(int i: nums)
            maxheap.push(i);
        int a = maxheap.top();
        maxheap.pop();
        int b = maxheap.top();
        return ((a-1)*(b-1));
    }
};


// Time Complexity: O(nlog(n-2))
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        priority_queue<int, vector<int>, greater<int> >minheap;
        for(int i: nums)
            minheap.push(i);
        while(minheap.size()!=2)
            minheap.pop();
        int a = minheap.top();
        minheap.pop();
        int b = minheap.top();
        return ((a-1)*(b-1));
    }
};
