
int main()
{
	int a,b,r,i,n;
	ifstream f("euclid2.in");
	ofstream g("eucld2.out");
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>a>>b;
		r=a%b;
		while(r!=0)
		{
			a=b;
			b=r;
			r=a%b;
		}
		g<<b<<'\n';
	}
	f.close();
	g.close();
	return 0;
}
