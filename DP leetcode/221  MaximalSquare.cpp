/* 221. Maximal Square 

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxx=0;
        vector<vector<int>>dp(rows+1,vector<int>(cols+1,0));
        for(int i=1; i<=rows; i++)
        {
            for(int j=1; j<=cols; j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                    maxx = max(maxx,dp[i][j]);
                }
            }
        }
        return maxx*maxx;
    }
};
