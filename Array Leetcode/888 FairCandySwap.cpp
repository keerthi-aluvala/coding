/* 888. Fair Candy Swap 

Alice and Bob have candy bars of different sizes: aliceSizes[i] is the size of the i-th bar of candy that Alice has, 
and bobSizes[j] is the size of the j-th bar of candy that Bob has.

Since they are friends, they would like to exchange one candy bar each so that after the exchange, they both have the 
same total amount of candy.  (The total amount of candy a person has is the sum of the sizes of candy bars they have.)

Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, and ans[1] is the size 
of the candy bar that Bob must exchange.

If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.

 

Example 1:

Input: aliceSizes = [1,1], bobSizes = [2,2]
Output: [1,2]
Example 2:

Input: aliceSizes = [1,2], bobSizes = [2,3]
Output: [1,2]
Example 3:

Input: aliceSizes = [2], bobSizes = [1,3]
Output: [2,3]
Example 4:

Input: aliceSizes = [1,2,5], bobSizes = [2,4]
Output: [5,4]

*/


class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) 
    {
        int nA=A.size();
        int nB=B.size();
        int sumA=0, sumB=0;
        for(int v: A)
        {
            sumA += v;
        }
        for(int v: B)
        {
            sumB += v;
        }
        sort(B.begin(),B.end());
        for(int i=0; i<nA; i++)
        {
            int AliceBar = A[i];
            int ii=0;
            int j=nB-1;
            while(ii<=j)
            {
                int mid= ii+(j-ii)/2;
                int BobBar = B[mid];
                
                int resA = sumA-AliceBar+BobBar;
                int resB = sumB+AliceBar-BobBar;
                if(resA==resB)
                {
                    return {AliceBar, BobBar};
                }
                else if(resA>resB)
                {
                    j=mid-1;
                }
                else
                {
                    ii=mid+1;
                }
            }
        }
        return {};
    }
};
