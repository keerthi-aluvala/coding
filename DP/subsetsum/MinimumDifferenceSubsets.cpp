/* Minimum Difference Subsets!

Given an integer array A containing N integers.

You need to divide the array A into two subsets S1 and S2 such that the absolute difference between their sums 
is minimum.

Find and return this minimum possible absolute difference.

NOTE:

Subsets can contain elements from A in any order (not necessary to be contiguous).
Each element of A should belong to any one subset S1 or S2, not both.
It may be possible that one subset remains empty.


Problem Constraints
1 <= N <= 100

1 <= A[i] <= 100



Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the minimum possible difference among the sums of two subsets.



Example Input
Input 1:

 A = [1, 6, 11, 5]
 
Example Output
Output 1:

 1

*/

int Solution::solve(vector<int> &A) 
{
    int sum=0;
    for(auto i: A)
        sum += i;
    int n = A.size();
    bool dp[n+1][sum+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            if(j==0)
                dp[i][j] = true;
            else if(i==0)
                dp[i][j] = false;
            else if(A[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
        }
    }
    int diff = INT_MAX;
    for(int i=0; i<=sum/2; i++)
    {
        int s1=i;
        int s2 = sum-i;
        if(dp[n][i]==true && diff>abs(s1-s2))
            diff = abs(s1-s2);
    }
    return diff;
}

