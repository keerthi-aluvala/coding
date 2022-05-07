//3sum
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
                int sum = nums[i] + nums[j] + nums[k];
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
