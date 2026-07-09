# include <cstdio>
int main ()
{
	freopen ("euclid2.in","r",stdin);
	freopen ("euclid2.out","w",stdout);
	long a,b,r,t;
	scanf ("%ld",&t);
	for (int i=1;i<=t;i++)
	{
		scanf ("%ld%ld",&a,&b);
		r=a%b;
		while (r)
		{
			a=b;
			b=r;
			r=a%b;
		}
		printf ("%ld\n",b);
	}
	return 0;
}