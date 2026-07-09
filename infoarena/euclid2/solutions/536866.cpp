#include <fstream.h>

int main()
{
	int t,i,a,b,r;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
	for (i=1;i<=t;i++)
	{
		f>>a;
	    f>>b;
		r=a%b;
		while(r!=0)
		{
			a=b;
		    b=r;
			r=a%b;
		}
		g<<b<<"\n";
	}
	
	f.close();
	g.close();
	return 0;
}
		