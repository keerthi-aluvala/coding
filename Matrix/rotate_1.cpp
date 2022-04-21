// rotate anticlockwise by 1 element
int main()
{
	int row=0, col=0, prev, curr;
	while(row<m && col<n)
	{
		if(row+1==m || col+1==n) break;
		prev = mat[row+1][col];
		for(int i=col; i<n; i++)
		{
			curr = mat[row][i];
			mat[row][i] = prev;
			prev = curr;
		}
		row++;
		for(int i=row; i<m; i++)
		{
			curr = mat[i][col];
			mat[i][col] = prev;
			prev = curr;
		}
		n--;
		if(row<m)
		{
			for(int i=n-1; i>=col; i--)
			{
				curr = mat[m-1][i];
				mat[m-1][i] = prev;
				prev = curr;
			}
		}
		m--;
		if(col<n)
		{
			for(int i=m-1; i>=row; i--)
			{
				curr = mat[i][col];
				mat[i][col] = prev;
				prev = curr;
			}
		}
		col++;
	}
}
