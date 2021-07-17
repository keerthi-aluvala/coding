/* 63. Unique Paths II Leetcode Medium 

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right 
corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and space is marked as 1 and 0 respectively in the grid.

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

*/


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        if(obstacleGrid[0][0]==1)
            return 0;
        obstacleGrid[0][0] = 1;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for(int i=1; i<m; i++)
            obstacleGrid[i][0] = (obstacleGrid[i][0]==0 && obstacleGrid[i-1][0]==1)?1:0;
        for(int j=1; j<n; j++)
            obstacleGrid[0][j] = (obstacleGrid[0][j]==0 && obstacleGrid[0][j-1]==1)?1:0;
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
                obstacleGrid[i][j] = (obstacleGrid[i][j]==1)?0:obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
        }
        return obstacleGrid[m-1][n-1];
    }
};

