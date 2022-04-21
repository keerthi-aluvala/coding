//Minimum platforms

int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int res=1,i=1, j=0;
    	while(i<n)
    	{
    	    if(arr[i]<=dep[j]) res++;
    	    else j++;
    	    i++;
    	}
    	return res;
    }
