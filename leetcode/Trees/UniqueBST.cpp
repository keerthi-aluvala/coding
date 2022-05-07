/*
Given an integer n, return the number of structurally unique BST's (binary search trees) 
which has exactly n nodes of unique values from 1 to n.

*/

class Solution {
public:
    unsigned long int binomialCoeff(unsigned int n, unsigned int k)
    {
        unsigned long int res = 1;
        if(k>n-k) k=n-k;
        for(int i=0; i<k; i++)
        {
            res *= (n-i);
            res /= (i+1);
        }
        return res;
    }
    int numTrees(int n) 
    {
        unsigned long int c = binomialCoeff(2*n, n); 
	    return c/(n+1);
    }
};
