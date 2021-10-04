/* 97. Interleaving String 

Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings 
such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

*/

// Recursion with memoization:

class Solution {
public:
    unordered_map<string, int>m;
    bool solve(string s1, string s2, string s3, int len1, int len2, int len3, int p1, int p2,int p3)
    {
        if(p3==len3)
            return (p2==len2 && p1==len1) ? true : false;
        
        string key = to_string(p1) + "*" + to_string(p2) + "*" + to_string(p3);
        if(m.find(key)!=m.end())
            return m[key];
        
        if(p1==len1)
            return m[key] = s2[p2]==s3[p3] ? solve(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1) : false;
        if(p2==len2)
            return m[key] = s1[p1]==s3[p3] ? solve(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1) : false;
        
        bool one=false, two=false;
        if(s1[p1]==s3[p3])
            one = solve(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1);
        if(s2[p2]==s3[p3])
            two = solve(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1); 
        
        return m[key] = one || two;
            
    }
    bool isInterleave(string s1, string s2, string s3) 
    {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if(len3 != (len1+len2))
            return false;
        return solve(s1, s2, s3, len1, len2, len3, 0, 0, 0);
    }
};
