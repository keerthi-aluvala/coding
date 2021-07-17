/* Sum of Two Numbers */

/*  Given a list of numbers nums and a number k, return whether any two elements from the list add up to k. 
	You may not use the same element twice.
Note: Numbers can be negative or 0.*/


bool solve(vector<int>& nums, int k) 
{
    unordered_map<int,int>st;
    int x=0;
    for(int i=0; i<nums.size(); i++)
    {
        if(st.find(nums[i])!=st.end())
        {
            return true;
        }
        else 
        {
            int temp = k-nums[i];
            st[temp]=i;
            
        }
    }
    return false;
}
