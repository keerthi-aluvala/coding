//rotate by 90 clockwise
int n=A.size();
    int m=A[0].size();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            swap(A[i][j],A[j][i]);
        }
    }
    for(int i=0; i<n; i++)
    {
        reverse(A[i].begin(),A[i].end());
    }
    
