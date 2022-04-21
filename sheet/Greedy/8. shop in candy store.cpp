// shop in candy store

vector<int> candyStore(int candies[], int n, int k)
    {
        int min=0, max=0;
        sort(candies, candies+n);
        int i=0, j=n-1;
        while(i<=j)
        {
            min += candies[i];
            i++;
            j=j-k;
        }
        reverse(candies, candies+n);
        i=0, j=n-1;
        while(i<=j)
        {
            max += candies[i];
            i++;
            j=j-k;
        }
        return {min,max};
    }
