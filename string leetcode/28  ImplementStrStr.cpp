/*  28. Implement strStr()

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() 
and Java's indexOf().

 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Example 3:

Input: haystack = "", needle = ""
Output: 0

*/




class Solution
{
public:
    // function to generate the LPS array
    vector<int>lpsGenerator(string &s)
    {
        int n=s.length(),i=1,j=0;
        vector<int>lps(n);
        lps[0]=0;
        while(i<n)
        {
            if(s[i]==s[j])
            {
                lps[i]=j+1;
                i++;
                j++;
            }
            else
            {
                if(j>0)
                {
                    j=lps[j-1];
                }
                else
                {
                    lps[i++]=0;
                }
            }
        }
        return lps;
    }
    int strStr(string haystack, string needle)
    {
        if(needle.length()==0)
        {
            return 0;
        }
        vector<int>lps=lpsGenerator(needle);
        int i=0,j=0,n=haystack.length(),m=needle.length();
        // i is pointing to haystack
        // j is pointing to needle
        while(i<n)
        {
            if(needle[j]==haystack[i])
            {
                i++;
                j++;
            }
            if(j==m)
            {
                return i-j;
            }
            else if(i<n && needle[j]!=haystack[i])
            {
                if(j>0)
                {
                    j=lps[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
        return -1;
    }
};
