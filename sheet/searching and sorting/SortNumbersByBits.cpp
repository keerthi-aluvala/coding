//sort by set bit count

int countBits(int a)
{
    int count = 0;
    while (a) {
        if (a & 1)
            count += 1;
        a = a >> 1;
    }
    return count;
}
// custom comparator of std::sort
int cmp(int a, int b)
{
    int count1 = countBits(a);
    int count2 = countBits(b);
 
    // this takes care of the stability of sorting algorithm too
    if (count1 <= count2)
        return false;
    return true;
} 
// Function to sort according to bit count using std::sort
void sortBySetBitCount(int arr[], int n)
{
    stable_sort(arr, arr + n, cmp);
}
 
// Utility function to print an array
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}



/* 2. Using count Sort*/

int countBits(int n)
    {
        int count=0;
        while(n)
        {
            if(n&1) count++;
            n>>=1;
        }
        return count;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        vector<vector<int>>v(32);
        for(int i=0; i<n; i++)
        {
            int x = countBits(arr[i]);
            v[x].push_back(arr[i]);
        }
        int j=0;
        for(int i=31; i>=0; i--)
        {
            vector<int>k = v[i];
            for(auto x: k)
            {
                arr[j++] = x;
            }
        }
    }
