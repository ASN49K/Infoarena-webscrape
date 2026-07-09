#include<fstream.h>
int main ()
{	int n,x,y,i,r;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	for (i=1;i<=n;i++)
	    { f>>x>>y;
	      r=x%y;
	      while (r!=0)
		{ x=y;
		  y=r;
		  r=x%y;
		}
	      g<<y<<"\n";
	    }
	f.close();
	g.close();
	return 0;
}
