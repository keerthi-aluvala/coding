/* 264. Ugly Number II 

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

*/


class Solution {
public:
    int nthUglyNumber(int n) 
    {
        vector<int>dp(n+1);
        dp[1]=1;
        int p2=1, p3=1, p5=1;
        for(int i=2; i<=n; i++)
        {
            int f2=2*dp[p2];
            int f3=3*dp[p3];
            int f5=5*dp[p5];
            int minn = min({f2,f3,f5});
            dp[i] = minn;
            if(minn==f2) p2++;
            if(minn==f3) p3++;
            if(minn==f5) p5++;
        }
        return dp[n];
    }
};

