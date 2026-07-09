#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
main()
{
	int n,i,a,b,c;
	f>>n;
	for (i=1;i<=n;i++)
	{
		f>>a>>b;
		c=1;
		while (c)
		{
			if (a>b)
			{
				c=a%b;
				a=c;
			}
			else 
			{
				c=b%a;
				b=a;
				a=c;
			}
		}
		g<<b<<"\n";
	}
}
			