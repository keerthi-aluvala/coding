/* 392. Is Subsequence Leetcode 

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the 
characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" 
while "aec" is not).

 
Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false

*/

class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int m = s.length();
        int n = t.length();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1; i<m+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        if(dp[m][n]==m)
            return true;
        return false;
    }
};
