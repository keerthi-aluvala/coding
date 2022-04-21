//fractional knapsack

static bool comp(Item a, Item b)
    {
        return ((double)a.value/a.weight) > ((double)b.value/b.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double res = 0.0;
        int s = 0;
        sort(arr, arr+n, comp);
        for(int i=0; i<n; i++)
        {
            if(s+arr[i].weight<=W)
            {
                res += arr[i].value;
                s += arr[i].weight;
            }
            else
            {
                int x = (W-s);
                res+=arr[i].value*((double)x/(double)arr[i].weight);
                break;
            }
        }
        return res;
    }
