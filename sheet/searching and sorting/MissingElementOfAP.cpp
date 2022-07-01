class Solution{   
public:
    int findMissing(int arr[], int n) 
    {
        // code here
        int diff = (arr[n-1]-arr[0])/n;
        int low=0, high=n-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if((arr[mid]-arr[0])/diff == mid)
            {
                low = mid+1;
            }
            else high = mid-1;
        }
        return arr[high]+diff;
    }
};
