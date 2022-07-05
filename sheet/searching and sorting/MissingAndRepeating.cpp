// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *nums, int n) 
    {
        int *arr1 = new int[2];
        for(int i=0; i<n; i++)
        {
            if(nums[abs(nums[i])-1]>0)
                nums[abs(nums[i])-1] *= -1;
            else
            {
                arr1[0] = abs(nums[i]);
            }
        }
        for(int i=0; i<n; i++)
        {
            if(nums[i]>0)
            {
                arr1[1] = i+1;
            }
        }
        return arr1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
