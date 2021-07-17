/* 119. Pascal's Triangle II leetcode 

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]


*/


class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        if(rowIndex==0)
            return {1};
        if(rowIndex==1)
            return {1,1};
        vector<int>last = {1,1};
        for(int i=2; i<rowIndex+1; i++)
        {
            vector<int>temp(i+1,0);
            temp[0] = temp[i] = 1;
            for(int j=1; j<i; j++)
                temp[j] = last[j] + last[j-1];
            if(i==rowIndex) return temp;
            else
                last = temp;
        }
        return {};
    }
};
