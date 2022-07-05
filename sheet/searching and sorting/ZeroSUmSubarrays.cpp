class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) 
    {
        int sum=0, ans=0;
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
            if(sum==0) ans++;
            if(mp.find(sum)!=mp.end())
                ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};
