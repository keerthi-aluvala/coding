/* Run Length Encoding   Question 18 of 1031

Given a string s, return its run-length encoding. You can assume the string to be encoded have no digits and consists solely of alphabetic characters.

Constraints

n = 100,000 where n is the length of s
Example 1
Input
s = "aaaabbbccdaa"
Output
"4a3b2c1d2a"

Example 2
Input
s = "abcde"
Output
"1a1b1c1d1e"

Example 3
Input
s = "aabba"
Output
"2a2b1a"

Example 4
Input
s = "aaaaaaaaaa"
Output
"10a"

*/


string solve(string s) 
{
    int count = 1;
    string temp="";
    temp = s[0];
    string result = "";
    for(int i=1; i<s.length(); i++)
    {
        if(s[i]!=s[i-1] )
        {
            result += to_string(count);
            result += temp;
            count = 1;
            temp = s[i];
        }
        else
        {
            count++;
        }
        if(i==s.length()-1)
        {
            if(s[i]==s[i-1])
            {
                result += to_string(count);
                result += temp;
            }
            else
            {
                result += to_string(1);
                result += s[i];
            }
        }
    }
    return result;
}
