/* 1249. Minimum Remove to Make Valid Parentheses 

Given a string s of '(' , ')' and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses 
string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
Example 4:

Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"


*/


class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        int n=s.length();
        if(n==0) return 0;
        stack<pair<char,int>>st;
        string s1="";
        vector<int>v(n,0);
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(')
            {
                st.push(make_pair('(', i));
            }
            else if(s[i]==')')
            {
                if(st.empty())
                {
                    st.push(make_pair(')', i));
                }
                else
                {
                    pair<char,int> p=st.top();
                    if(p.first=='(')
                        st.pop();
                    else if(p.first==')')
                        st.push(make_pair(')', i));
                }
            }
            cout<<st.top().first<<" ";
        }
        if(st.empty())
            return s;
        while(!st.empty())
        {
            pair<char,int> p=st.top();
            st.pop();
            v[p.second]=1;
            cout<<p.first;
        }
        for(int i=0; i<n; i++)
        {
            if(v[i]!=1)
                s1+=s[i];
        }
        return s1;
    }
};


