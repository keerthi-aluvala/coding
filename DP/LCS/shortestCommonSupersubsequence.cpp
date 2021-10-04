/* 1092. Shortest Common Supersequence 

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.  
If multiple answers exist, you may return any of them.

(A string S is a subsequence of string T if deleting some number of characters from T (possibly 0, and the 
characters are chosen anywhere from T) results in the string S.)

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.

*/

class Solution {
public:
    string solve_lcs(string s1, string s2)
    {
        int len1 = s1.length();
        int len2 = s2.length();
        string dp[len1+1][len2+1];
    
        for(int i=0; i<=len1; i++)
        {
            for(int j=0; j<=len2; j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = "";
                else if(s1[i-1]==s2[j-1])
                    dp[i][j] = dp[i-1][j-1]+s1[i-1];
                else
                    dp[i][j] = dp[i-1][j].size() > dp[i][j-1].size() ? dp[i-1][j] : dp[i][j-1];
            }
        }
        return dp[len1][len2];
    }
    string shortestCommonSupersequence(string str1, string str2) 
    {
        string s3="";
        int p1=0, p2=0;
        string lcs = solve_lcs(str1, str2);
        for(char c: lcs)
        {
            while(str1[p1]!=c)
                s3 += str1[p1++];
            while(str2[p2]!=c)
                s3 += str2[p2++];
            s3 += c;
            p1++;
            p2++;
        }
        s3 += str1.substr(p1);
        s3 += str2.substr(p2);
        return s3;
    }
};
