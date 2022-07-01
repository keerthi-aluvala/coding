bool comp(vector<int> s1, vector<int> s2)
    {
        return (s1[1] < s2[1]);
    }
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>job(n);
        for(int i=0; i<n; i++)
        {
            int x = startTime[i];
            int y = endTime[i];
            int z = profit[i];
            job[i] = {x,y,z};
        }
        sort(job.begin(), job.end(), comp);
        int dp[n];
        dp[0] = job[0][2];
        
        for(int i=1; i<n; i++)
        {
            int inc = job[i][2];
            int last=-1, low=0, high=i-1;
            while(low<=high)
            {
                int mid = (low+high)/2;
                if(job[mid][1]<=job[i][0])
                {
                    last = mid;
                    low = mid+1;
                }
                else high=mid-1;
            }
            if(last!=-1) inc+=dp[last];
            int exc = dp[i-1];
            dp[i] = max(inc, exc);
        }
        return dp[n-1];
    }
};
