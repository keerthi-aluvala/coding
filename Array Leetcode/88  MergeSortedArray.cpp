/* 88. Merge Sorted Array 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

*/



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i=m-1, j=n-1, k=m+n-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i]>=nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while(j>=0)
            nums1[k--] = nums2[j--];
    }
};



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        vector<int>v(m);
        for(int i=0; i<m; i++)
            v[i]=nums1[i];
        int ptr1=0, ptr2=0;
        int i=0;
        while(ptr1<m && ptr2<n)
        {
            if(v[ptr1]<=nums2[ptr2])
            {
                nums1[i]=v[ptr1];
                ptr1++;
                i++;
            }
            else 
            {
                nums1[i]=nums2[ptr2];
                ptr2++;
                i++;
            }
        }
        
        while(ptr2<n)
        {
            nums1[i]=nums2[ptr2];
            ptr2++;
            i++;
        }

        while(ptr1<m)
        {
                nums1[i]=v[ptr1];
                ptr1++;
                i++;
        }
    }
};


