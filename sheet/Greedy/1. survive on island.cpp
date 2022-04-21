//can survive in island

int main()
{
	int s,n,m;
	int sm=s*m;
	int x = s/7;
	int y = s-x;
	int days = sm/n;
	if(sm%n!=0) days++;
	if(days<=y) cout<<"yes";
	else cout<<"No";
	return 0;
}
