class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int barrier, int A[], int n, int M)
    {
        int stu=1, pages=0;
        for(int i=0; i<n; i++)
        {
            if(A[i]>barrier) return false;
            if(pages+A[i]>barrier)
            {
                stu += 1;
                pages = A[i];
            }
            else pages+= A[i];
        }
        if(stu>M) return false;
        return true;
    }
    int findPages(int A[], int n, int M) 
    {
        int high=0, low = A[0], res=0;
        for(int i=0; i<n; i++)
            high += A[i];
        int mid;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(isPossible(mid, A, n, M))
            {
                res = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return res;
    }
};
