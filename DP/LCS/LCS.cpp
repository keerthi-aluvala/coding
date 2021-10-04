/* 1143. Longest Common Subsequence 

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, 
return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without 
changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

*/


class Solution {
public:
    int longestCommonSubsequence(string s, string t) 
    {
        int m = s.length(), n = t.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1; i<m+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
   //             cout<<dp[i][j]<<" ";
            }
   //         cout<<endl;
        }
        return dp[m][n];
    }
};
        
