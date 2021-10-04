/* 343. Integer Break Leetcode Medium

Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

 

Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

*/


class Solution {
public:
    int integerBreak(int n) 
    {
        int dp[58];
        dp[1]=1; dp[2]=1; dp[3]=2; dp[4]=4;
        dp[5]=6; dp[6]=9;
        for(int i=7; i<=n; i++)
            dp[i] = dp[i-3]*3;
        return dp[n];
    }
};


