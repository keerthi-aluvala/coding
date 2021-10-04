/* 349. Intersection of Two Arrays 

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be 
unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

*/


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>v;
        unordered_map<int,int>mp;
        for(int i=0; i<nums1.size(); i++)
            mp[nums1[i]]=1;
        for(int i=0; i<nums2.size(); i++)
        {
            if(mp.find(nums2[i])!=mp.end())
            {
                if(v.size()==0)
                    v.push_back(nums2[i]);
                else
                {
                    vector<int>::iterator it = find(v.begin(), v.end(), nums2[i]);
                    if(it!=v.end())
                        ;
                    else
                        v.push_back(nums2[i]);
                }
            }
        }
        return v;
    }
};
