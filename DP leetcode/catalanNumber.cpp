// catalan numbers

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





unsigned long int catalanDP(unsigned int n) 
{ 
	// Table to store results of subproblems 
	unsigned long int catalan[n+1]; 

	// Initialize first two values in table 
	catalan[0] = catalan[1] = 1; 

	// Fill entries in catalan[] using recursive formula 
	for (int i=2; i<=n; i++) 
	{ 
		catalan[i] = 0; 
		for (int j=0; j<i; j++) 
			catalan[i] += catalan[j] * catalan[i-j-1]; 
	} 

	// Return last entry 
	return catalan[n]; 
} 
