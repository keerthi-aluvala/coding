/* 516. Longest Palindromic Subsequence 

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the 
order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

*/

class Solution {
public:
    int longestPalindromeSubseq(string b) 
    {
        string a = b;
        reverse(b.begin(),b.end());
        int n = a.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};


