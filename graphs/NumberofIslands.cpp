/* 200. Number of Islands 

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number
of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

*/

class Solution {
public:
    void marked(vector<vector<char>>&grid,int x, int y, int m, int n)
    {
        if(x<0 || y<0 || x>=m || y>=n || grid[x][y]!='1')
            return;
        grid[x][y] = '2';
        marked(grid,x-1,y,m,n);
        marked(grid,x+1,y,m,n);
        marked(grid,x,y-1,m,n);
        marked(grid,x,y+1,m,n);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int res=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='1')
                {
                    marked(grid,i,j,m,n);
                    res++;
                }
            }
        }
        return res;
    }
};
