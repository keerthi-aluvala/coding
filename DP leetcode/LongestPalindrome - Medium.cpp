/* 5. Longest Palindromic Substring Leetcode Medium 

Given a string s, return the longest palindromic substring in s.


Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"

*/

class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.length();
        int dp[n][n];
        int start=0, end=0, maxx=0;
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++)
        {
            dp[i][i]=1;
            start = i;
            end = 1;
        }
        for(int i=0; i<n-1; i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                start=i;
                end=2;
            }
        }
        for(int k=3; k<=n; k++)
        {
            for(int i=0; i<=n-k; i++)
            {
                int j=i+k-1;
                if(s[i]==s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = 1;
                    start = i;
                    end = max(end,k);
                }
            }
        }
        return s.substr(start, end);
    }
};


