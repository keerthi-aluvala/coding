/* 650. 2 Keys Keyboard 

There is only one character 'A' on the screen of a notepad. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

 

Example 1:

Input: n = 3
Output: 3
Explanation: Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
Example 2:

Input: n = 1
Output: 0

*/


class Solution {
public:
    int f(int ele)
    {
        int i;
        int ans;
        for(i=ele-1;i>=1;i--)
        {
            if(ele%i == 0)
            {
                ans=i;
                break;
            }
        }
        return ans;
    }
    int minSteps(int n) {
        if(n == 1)
        {
            return 0;
        }
       if(n <= 5)
       {
           return n;
       }
        
        int dp[n+1];
        dp[1]=0;
        dp[2]=2;
        dp[3]=3;
        dp[4]=4;
        dp[5]=5;
        for(int i=6;i<=n;i++)
        {
            if(i%2 == 0)
            {
                int x=(i/2);
                dp[i]=(dp[i/2]+(i/x));
            }
            else if(i%2 != 0)
            {
                int ele=f(i);
                int x=(i/ele);
                dp[i]=(dp[ele]+x);
            }
        }
        return dp[n];
    }
};


class Solution {
public:
    int minSteps(int n) 
    {
         int ans = 0, d = 2;
           while (n > 1) 
           {
             while (n % d == 0) 
             {
                 ans += d;
                 n /= d;
             }
             d++;
         }
         return ans;
    }
};
