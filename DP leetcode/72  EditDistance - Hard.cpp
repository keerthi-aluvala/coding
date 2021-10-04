/* 72. Edit Distance

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

*/

int editDistance(string s, string t) 
    {
        // Code here
        int len1 = s.length();
        int len2 = t.length();
        int dp[len1+1][len2+1];
        for(int i=0; i<=len1; i++)
        {
            for(int j=0; j<=len2; j++)
            {
                if(i==0)
                    dp[i][j] = j;
                else if(j==0)
                    dp[i][j] = i;
                else if(s[i-1]==t[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[len1][len2];
    }
