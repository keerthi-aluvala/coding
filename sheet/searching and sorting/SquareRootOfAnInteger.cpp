/* Square Root of Integer */

int Solution::sqrt(int A) 
{
    if(A==0 || A==1) return A;
    int ans,l=1,h=A/2;
    while(l<=h)
    {
        long mid = (h+l)/2;
        if(mid*mid==A)
        {
            return mid;
        }
        if(mid*mid<=A)
        {
            l=mid+1;
            ans = mid;
        }
        else
            h=mid-1;
    }
    return ans;
}

