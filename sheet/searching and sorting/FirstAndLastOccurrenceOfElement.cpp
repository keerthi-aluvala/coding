/*Find First and Last Position of Element in Sorted Array


Given an array of integers nums sorted in non-decreasing order, 
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].*/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int x) 
    {
        if(nums.size()==0)
            return {-1,-1};
        vector<int>v;
        long long l=0;
        long long r=nums.size()-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(nums[mid]==x)
            {
                int l1=l, r1=mid;
                int l2=mid, r2=r;
                while(l1<=r1)
                {
                    int mid1 = l1+(r1-l1)/2;
                    if(nums[mid1]==x)
                        r1=mid1-1;
                    else
                        l1 = mid1+1;
                }
                while(l2<=r2)
                {
                    int mid2 = l2+(r2-l2)/2;
                    if(nums[mid2]==x)
                        l2=mid2+1;
                    else
                        r2=mid2-1;
                }
                return {l1,r2};
            }
            else if(nums[mid]<x)
            {
                l=mid+1;
            }
            else 
                r=mid-1;
        }
        return {-1,-1};
    }
};
