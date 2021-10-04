/* 118. Pascal's Triangle Leetcode 

Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>>v;
        for(int i=1; i<numRows+1; i++)
        {
            vector<int>temp(i,1);
            v.push_back(temp);
        }
        for(int row=1; row<v.size(); row++)
        {
            for(int column=1; column<v[row].size()-1; column++)
            {
                v[row][column] = v[row-1][column-1] + v[row-1][column];
            }
        }
        return v;
    }
};
