/* 712. Minimum ASCII Delete Sum for Two Strings 

Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.


Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
Example 2:

Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

*/

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) 
    {
        int m=s1.length(), n=s2.length();
        int dp[m+1][n+1];
        int n1=0, n2=0;
        for(char c: s1)
            n1+=c;
        for(char c: s2)
            n2+=c;
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = s1[i-1]+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int lcs=dp[m][n];
        return n1+n2-(2*lcs);
    }
};


